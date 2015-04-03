#include <stdlib.h>

const char *mr_init_devices[] = {
	"/sys/class/graphics/fb0",

	"/sys/block/mmcblk0",
	"/sys/devices/platform/sdhci-tegra.3",
	"/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0",
	"/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001",
	"/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
	"/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0*",

	"/sys/bus/mmc",
	"/sys/bus/mmc/drivers/mmcblk",
	"/sys/bus/sdio/drivers/bcmsdh_sdmmc",
	"/sys/module/mmc_core",
	"/sys/module/mmcblk",
	"/sys/module/sdhci",

	"/sys/devices/virtual/input*",
	"/sys/devices/virtual/misc/uinput",
	"/sys/bus/spi",
	"/sys/bus/spi/drivers/rm_ts_spidev",
	"/sys/devices/platform/spi-tegra114.0",
	"/sys/devices/platform/spi-tegra114.0*",
	"/sys/bus/platform/drivers/spi-tegra114",
	"/sys/devices/virtual/misc/touch",
	"/sys/bus/hid",
	"/sys/bus/hid/drivers/hid-multitouch",

	"/sys/class/tty/ptmx",
	"/sys/class/misc/android_adb",
	"/sys/class/android_usb",
	"/sys/class/android_usb/android0",
	"/sys/class/android_usb/android0*",
	"/sys/bus/usb",
	"/sys/devices/platform/tegra-ehci.1",
	"/sys/devices/platform/tegra-ehci.1*",
	"/sys/devices/platform/tegra-udc.0",
	"/sys/devices/platform/tegra-udc.0*",
	"/sys/devices/platform/tegra-otg",
	"/sys/devices/platform/tegra-otg*",
	"/sys/module/tegra_udc",
        "/sys/module/usbcore",
        "/sys/devices/virtual/android_usb/android0/f_ffs",
	"/sys/module/g_android",

	"/sys/devices/platform/gpio-keys.4",
	"/sys/devices/platform/gpio-keys.4*",
	"/sys/bus/platform/drivers/gpio-keys",

	"/sys/devices/platform/60005100.watchdog",
	"/sys/devices/virtual/misc/watchdog",
	"/sys/devices/virtual/watchdog*",

	// fix for slow reboot
	//"/sys/bus/platform/drivers/host1x",
	//"/sys/devices/platform/host1x",
	//"/sys/devices/platform/host1x*",
	// initialized separately

	//"/sys*", // yolo

	NULL
};
