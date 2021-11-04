/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_system20190504_gps.h
 *
 * Code generated for Simulink model 'px4demo_attitude_system20190504_gps'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 13 20:43:33 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_system20190504_gps_h_
#define RTW_HEADER_px4demo_attitude_system20190504_gps_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef px4demo_attitude_system20190504_gps_COMMON_INCLUDES_
# define px4demo_attitude_system20190504_gps_COMMON_INCLUDES_
#include <uORB/topics/vehicle_attitude.h>
#include <poll.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <drivers/drv_rc_input.h>
#include <uORB/topics/sensor_combined.h>
#include <sys/ioctl.h>
#include <drivers/drv_pwm_output.h>
#include <px4_defines.h>
#include <px4_posix.h>
#include <systemlib/err.h>
#include <systemlib/param/param.h>
#include <drivers/drv_led.h>
#include <drivers/drv_rgbled.h>
#include <drivers/drv_tone_alarm.h>
#include <fcntl.h>
#include <stdio.h>
#include "rtwtypes.h"
#endif                                 /* px4demo_attitude_system20190504_gps_COMMON_INCLUDES_ */

#include "px4demo_attitude_system20190504_gps_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Child system includes */
#include "px4demo_attitude_control20190311gps.h"
#include "rt_nonfinite.h"
#include "rt_roundd_snf.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#define px4demo_attitude_system20190504_gps_M (px4demo_attitude_system20190_M)

typedef struct pollfd pollfd_t;

/* Block signals (auto storage) */
typedef struct {
  real32_T RateTransition_m[8];
  char_T b[24];
  int32_T TmpSignalConversionAtSFunctionI[5];
  real_T ControlSubsystem_o3;          /* '<Root>/ControlSubsystem' */
  real_T ControlSubsystem_o4;          /* '<Root>/ControlSubsystem' */
  real_T file;
  real32_T phi;                        /* '<Root>/vehicle_attitude' */
  real32_T theta;                      /* '<Root>/vehicle_attitude' */
  real32_T vehicle_attitude_o3;        /* '<Root>/vehicle_attitude' */
  real32_T sensor_combined_o1;         /* '<Root>/sensor_combined' */
  real32_T sensor_combined_o2;         /* '<Root>/sensor_combined' */
  real32_T sensor_combined_o3;         /* '<Root>/sensor_combined' */
  real32_T sensor_combined_o4;         /* '<Root>/sensor_combined' */
  real32_T ControlSubsystem_o5;        /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o6;        /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o7;        /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o8;        /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o9;        /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o10;       /* '<Root>/ControlSubsystem' */
  real32_T ControlSubsystem_o11;       /* '<Root>/ControlSubsystem' */
  real32_T RateTransition[8];          /* '<Root>/Rate Transition' */
  real32_T Gain2;                      /* '<Root>/Gain2' */
  real32_T Gain3;                      /* '<Root>/Gain3' */
  real32_T Gain1;                      /* '<Root>/Gain1' */
  real32_T f0;
  int32_T vehicle_gps_o1;              /* '<Root>/vehicle_gps' */
  int32_T vehicle_gps_o2;              /* '<Root>/vehicle_gps' */
  int32_T i;
  int32_T i0;
  int32_T cst;
  RGBLED_MODE_ENUM Switch;             /* '<S3>/Switch' */
  RGBLED_COLOR_ENUM Switch1;           /* '<S3>/Switch1' */
  PX4_TUNE_ENUM Switch1_i;             /* '<S4>/Switch1' */
  uint16_T ControlSubsystem_o1[4];     /* '<Root>/ControlSubsystem' */
  char_T c[3];
  uint16_T input_rc_o1;                /* '<Root>/input_rc' */
  uint16_T input_rc_o2;                /* '<Root>/input_rc' */
  uint16_T input_rc_o3;                /* '<Root>/input_rc' */
  uint16_T input_rc_o4;                /* '<Root>/input_rc' */
  uint16_T input_rc_o5;                /* '<Root>/input_rc' */
  uint16_T input_rc_o6;                /* '<Root>/input_rc' */
  int8_T fileid;
  int8_T j;
  int8_T k;
  int8_T fileid_c;
  int8_T fileid_k;
  int8_T fileid_cx;
  uint8_T vehicle_gps_o3;              /* '<Root>/vehicle_gps' */
  uint8_T DataTypeConversion;          /* '<S4>/Data Type Conversion' */
  boolean_T ControlSubsystem_o2;       /* '<Root>/ControlSubsystem' */
  boolean_T ControlSubsystem_o12;      /* '<Root>/ControlSubsystem' */
  boolean_T autoflush;
  boolean_T autoflush_b;
} B_px4demo_attitude_system2019_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  pollfd_t vehicle_attitude_vehicle_attitu;/* '<Root>/vehicle_attitude' */
  pollfd_t vehicle_gps_gps_fd;         /* '<Root>/vehicle_gps' */
  pollfd_t input_rc_input_rc_fd;       /* '<Root>/input_rc' */
  pollfd_t sensor_combined_sensor_fd;  /* '<Root>/sensor_combined' */
  codertarget_pixhawk_blocks_Se_T obj; /* '<Root>/Serial' */
  void *Serial_PWORK;                  /* '<Root>/Serial' */
  int32_T RGB_LED_rgbled_fd;           /* '<Root>/RGB_LED' */
  int32_T Speaker_Tune_tune_fd;        /* '<Root>/Speaker_Tune' */
  uint8_T Speaker_Tune_triggerState;   /* '<Root>/Speaker_Tune' */
  boolean_T UnitDelay_DSTATE;          /* '<S4>/Unit Delay' */
  boolean_T eml_autoflush[20];         /* '<Root>/MATLAB Function' */
  FILE * eml_openfiles[20];            /* '<Root>/MATLAB Function' */
  MdlrefDW_px4demo_attitude_con_T ControlSubsystem_DWORK1;/* '<Root>/ControlSubsystem' */
} DW_px4demo_attitude_system201_T;

/* Real-time Model Data Structure */
struct tag_RTM_px4demo_attitude_syst_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_px4demo_attitude_system2019_T px4demo_attitude_system201905_B;

/* Block states (auto storage) */
extern DW_px4demo_attitude_system201_T px4demo_attitude_system20190_DW;

/* External data declarations for dependent source files */
extern const uint8_T px4demo_attitude_system20190504_gps_U8GND;/* uint8_T ground */

/* Model entry point functions */
extern void px4demo_attitude_system20190504_gps_initialize(void);
extern void px4demo_attitude_system20190504_gps_step(void);
extern void px4demo_attitude_system20190504_gps_terminate(void);
extern const char* g_pwm_device;
extern bool g_pwm_enabled;
extern int g_pwm_fd;

/* Real-time Model object */
extern RT_MODEL_px4demo_attitude_sys_T *const px4demo_attitude_system20190_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'px4demo_attitude_system20190504_gps'
 * '<S1>'   : 'px4demo_attitude_system20190504_gps/MATLAB Function'
 * '<S2>'   : 'px4demo_attitude_system20190504_gps/MATLAB Function7'
 * '<S3>'   : 'px4demo_attitude_system20190504_gps/RGB_Mode_Subsystem'
 * '<S4>'   : 'px4demo_attitude_system20190504_gps/Tune_Mode_Subsystem'
 */
#endif                                 /* RTW_HEADER_px4demo_attitude_system20190504_gps_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
