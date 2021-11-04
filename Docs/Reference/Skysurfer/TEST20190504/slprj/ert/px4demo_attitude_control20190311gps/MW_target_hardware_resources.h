#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#include "nuttx/config.h"
#include "nuttx/i2c.h"
#include "nuttx/mtd.h"
#include "nuttx/fs/ioctl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "unistd.h"
#include "fcntl.h"
#include "errno.h"
#include "debug.h"
#include "time.h"
#include "math.h"
#include "poll.h"
#include "uORB/uORB.h"
#include "uORB/topics/sensor_combined.h"
#include "uORB/topics/vehicle_attitude.h"
#include "uORB/topics/optical_flow.h"
#include "drivers/drv_led.h"
#include "drivers/drv_pwm_output.h"
#include "drivers/drv_rc_input.h"
#include "drivers/drv_hrt.h"
#include "arch/board/board.h"
#include "sys/mount.h"
#include "sys/ioctl.h"
#include "sys/stat.h"
#include "systemlib/perf_counter.h"
#include "systemlib/systemlib.h"
#include "systemlib/err.h"
#include "systemlib/param/param.h"

#define MW_USECODERTARGET 1.000000
#define MW_TARGETHARDWARE Pixhawk PX4
#define MW_RTOS NuttX
#define MW_RTOSBASERATETASKPRIORITY 250
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 0
#define MW_CLOCKING_CPUCLOCKRATEMHZ 168
#define MW_TASK_STORAGE 0
#define MW_DSC_STORAGE ttyS6
#define MW_BAUD_STORAGE 6
#define MW_AUTOMATIC_SERIAL_SCAN 1
#define MW_COM_UPLOAD_STORAGE COM6
#define MW_DATAVERSION 2016.02
#define MW_HRT_CONSTRAINT 0
#define MW_SEM_WATERMARK 20
#define MW_MULTI_TASKING_MODE 0

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
