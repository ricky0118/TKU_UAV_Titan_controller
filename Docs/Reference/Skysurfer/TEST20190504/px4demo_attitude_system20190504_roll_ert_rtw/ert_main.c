/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'px4demo_attitude_system20190504_roll'.
 *
 * Model version                  : 1.185
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Jul 29 10:46:04 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "px4demo_attitude_system20190504_roll.h"
#include "px4demo_attitude_system20190504_roll_private.h"
#include "rtwtypes.h"
#include "limits.h"
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
#include "unistd.h"
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
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x

void baseRateTask(void *arg);
void exitTask(void *arg);
void terminateTask(void *arg);
static void usage(const char *reason);
void SpawnThreads_Task(void *arg);
void ShutDown_Procedure(void);

/* For Pixhawk Firmware build-process */
__EXPORT int px4_simulink_app_main(int argc, char *argv[]);

/* Define semaphores */
sem_t stopSem;
sem_t termSem;
sem_t baserateTaskSem;
sem_t Thread_Spawner_Task_Sem;

#ifdef EXT_MODE_BKGND

sem_t ExtModeTsk_Sem;
volatile int ExtModeStarted = 0;
pthread_t EXT_Mode_Thread;

#endif

/* Base-rate HRT-callback is used to post base-rate semaphore */
extern struct hrt_call BaseRate_HRT;

/* Define pthread_t for aperiodic tasks */

/* Define pthread_t for nuttxinitialize.c */
pthread_t terminateThread;
pthread_t schedulerThread;
pthread_t baseRateThread;
int subratePriority[0];

/* Define the Base Rate Task here */
void baseRateTask(void *arg)
{
  volatile boolean_T noErr;
  noErr = (rtmGetErrorStatus(px4demo_attitude_system20190_M) == (NULL));
  int sem_value;
  while (noErr ) {
    sem_getvalue(&baserateTaskSem, &sem_value);
    if (sem_value > 1) {

#ifdef PIXHAWK_PSP_HARD_REAL_TIME

      if (sem_value > 20) {
        printf("Hard real-time constraint violated, shutting down \n");
        fflush(stdout);
        ShutDown_Procedure();
      }

#else
#ifdef MW_RTOS_DEBUG

      printf("Task over-run, sem_value: %d \n",sem_value);
      fflush(stdout);

#endif

      sem_init(&baserateTaskSem,0,0);

#endif

    }

    sem_wait(&baserateTaskSem);
    px4demo_attitude_system20190504_roll_step();

    /* Get model outputs here */
    noErr = (rtmGetErrorStatus(px4demo_attitude_system20190_M) == (NULL));
  }                                    /* while */

  /* Wait for aperiodic threads to close */

  /* Close BaseRate thread */
  sem_post(&termSem);
}

/* Define the exit task here */
void exitTask(void *arg)
{
  sem_post(&stopSem);
}

/* Define the terminate task here */
void terminateTask(void *arg)
{
  printf("**blocking on termSem semaphore in terminateTask**\n");
  sem_wait(&termSem);
  printf("**terminating the model**\n");
  fflush(stdout);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  px4demo_attitude_system20190504_roll_terminate();
  sem_post(&stopSem);
}

/* Define the nuttx function calls here */
/* Print the correct usage. */
static void usage(const char *reason)
{
  if (reason)
    warnx("%s\n", reason);
  errx(1,
       "usage: px4_simulink_app {start|stop|status} [-p <additional params>]\n\n");
}

void SpawnThreads_Task(void *arg)
{
  px4demo_attitude_system20190504_roll_initialize();
  sleep(1);
  nuttxRTOSInit(0.004, 250, 0);
  sem_wait(&Thread_Spawner_Task_Sem);
  hrt_cancel(&BaseRate_HRT);
  warnx("Received semaphore to end this task \n");
}

void ShutDown_Procedure()
{
  /*if we get here, it means we experienced a task over-run, this also implies:
     - the sem_value is > 10 and base-rate thread will still execute until the end of this current iteration
     - <model>_M structs error status will be set to ERROR
     - sub-rate semaphores states are not known - it is better to increment inside here to force exit */
  FILE* fp_taskover_run = NULL;
  char buff[20];
  struct tm *sTm;
  time_t now = time(NULL);
  sTm = gmtime (&now);
  strftime (buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
  fp_taskover_run = fopen("/fs/microsd/log/task_overrun_log.txt","a+");
  fprintf(fp_taskover_run,"%s \n",buff);
  fclose(fp_taskover_run);
  rtmSetErrorStatus(px4demo_attitude_system20190_M, "Module finished");
  g_baseRateLife = false;
  sem_post(&Thread_Spawner_Task_Sem);
}

int px4_simulink_app_main(int argc, char *argv[]) //Px4 App
{
  int rc = 0;
  int SpawnThread_Task_PID = 0;
  if (argc < 1)
    usage("missing command");
  if (!strcmp(argv[1], "start")) {
    if (g_baseRateLife == false) {
      /* just start the Simulink Tasks here */
      printf("**starting the model**\n");
      fflush(stdout);
      g_baseRateLife = true;
      sem_init(&Thread_Spawner_Task_Sem,0,0);
      SpawnThread_Task_PID = task_create("Spawn_Thread_Tasks", 100, 2048, (void *)
        SpawnThreads_Task, (void *) &SpawnThread_Task_PID);
    } else {
      warnx("\t**model is already running**\n");
      fflush(stdout);
    }

    exit(0);
  }

  if (!strcmp(argv[1], "stop")) {
    if (g_baseRateLife == true) {
      rtmSetErrorStatus(px4demo_attitude_system20190_M, "Module finished");
      g_baseRateLife = false;
      sem_post(&baserateTaskSem);

      /* wait until the tasks completely finish */
      warnx("exiting model... waiting on stopSem...");

      /* Wait for stop semaphore */
      sem_wait(&stopSem);
      sem_post(&Thread_Spawner_Task_Sem);
    } else {
      warnx("\t**model is not running**\n");
      fflush(stdout);
    }

    exit(0);
  }

  if (!strcmp(argv[1], "status")) {
    if (g_baseRateLife) {
      warnx("\trunning\n");
    } else {
      warnx("\tnot started\n");
    }

    exit(0);
  }

  usage("unrecognized command");
  rc = 1;
  return rc;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
