#include <unistd.h>
#include <log.h>
#include <trampoline/devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <pthread.h>
#include <fcntl.h>
#include <linux/watchdog.h>

#define WATCHDOG_INTERVAL 1
#define WATCHDOG_MARGIN 20

#define PID_TOUCH "/touch.pid"

static void write_pid(const char* path, int pid) {
	FILE* f = fopen(path, "w");
	int num = fprintf(f, "%d\n", pid);
	fclose(f);
}

static void kill_pid(const char* path) {
	int pid;
	FILE *f	= fopen(path, "r");
	if (f == NULL)
		return;
	fscanf(f, "%d", &pid);
	fclose(f);
	kill(pid, SIGKILL);
	unlink(path);
}

static void ts_thread() {
	symlink("/realdata/media/0/multirom/touchscreen", "/sbin/touchscreen");
	wait_for_file("/dev/touch", 10);
	wait_for_file("/realdata/media/0/multirom", 10);

	ERROR("Starting rm-wrapper...\n");
	char* argv[] = {"/sbin/touchscreen/rm-wrapper", NULL};
	char* envp[] = {"LD_LIBRARY_PATH=/sbin/touchscreen", NULL};
	execve(argv[0], &argv[0], envp);
}

int mrom_hook_after_android_mounts(const char *busybox_path, const char *base_path, int type) {
	mrom_hook_before_fb_close();
	return 0;
}

void mrom_hook_before_fb_close() {
	kill_pid(PID_TOUCH);
}

void tramp_hook_before_device_init() {
	signal(SIGCHLD, SIG_IGN);

	if (fork() == 0) {
		write_pid(PID_TOUCH, getpid());
		ts_thread();
		_exit(0);
	}
}
