/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_system20190504_roll_types.h
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

#ifndef RTW_HEADER_px4demo_attitude_system20190504_roll_types_h_
#define RTW_HEADER_px4demo_attitude_system20190504_roll_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#ifndef DEFINED_TYPEDEF_FOR_RGBLED_MODE_ENUM_
#define DEFINED_TYPEDEF_FOR_RGBLED_MODE_ENUM_

typedef enum {
  MODE_OFF = 0,                        /* Default value */
  MODE_ON,
  MODE_BLINK_SLOW,
  MODE_BLINK_NORMAL,
  MODE_BLINK_FAST,
  MODE_BREATHE,
  MODE_PATTERN
} RGBLED_MODE_ENUM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RGBLED_COLOR_ENUM_
#define DEFINED_TYPEDEF_FOR_RGBLED_COLOR_ENUM_

typedef enum {
  COLOR_OFF = 0,                       /* Default value */
  COLOR_RED,
  COLOR_YELLOW,
  COLOR_PURPLE,
  COLOR_GREEN,
  COLOR_BLUE,
  COLOR_WHITE,
  COLOR_AMBER,
  COLOR_DIM_RED,
  COLOR_DIM_YELLOW,
  COLOR_DIM_PURPLE,
  COLOR_DIM_GREEN,
  COLOR_DIM_BLUE,
  COLOR_DIM_WHITE,
  COLOR_DIM_AMBER
} RGBLED_COLOR_ENUM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PX4_TUNE_ENUM_
#define DEFINED_TYPEDEF_FOR_PX4_TUNE_ENUM_

typedef enum {
  STOP_TUNE = 0,                       /* Default value */
  STARTUP_TUNE,
  ERROR_TUNE,
  NOTIFY_POSITIVE_TUNE,
  NOTIFY_NEUTRAL_TUNE,
  NOTIFY_NEGATIVE_TUNE,
  ARMING_WARNING_TUNE,
  BATTERY_WARNING_SLOW_TUNE,
  BATTERY_WARNING_FAST_TUNE,
  GPS_WARNING_TUNE,
  ARMING_FAILURE_TUNE,
  PARACHUTE_RELEASE_TUNE,
  NUMBER_OF_TUNES
} PX4_TUNE_ENUM;

#endif

#ifndef struct_tag_sNDTslA0cNqpP8MzjGk0gx
#define struct_tag_sNDTslA0cNqpP8MzjGk0gx

struct tag_sNDTslA0cNqpP8MzjGk0gx
{
  int32_T isInitialized;
  int32_T fh_index;
};

#endif                                 /*struct_tag_sNDTslA0cNqpP8MzjGk0gx*/

#ifndef typedef_codertarget_pixhawk_blocks_Se_T
#define typedef_codertarget_pixhawk_blocks_Se_T

typedef struct tag_sNDTslA0cNqpP8MzjGk0gx codertarget_pixhawk_blocks_Se_T;

#endif                                 /*typedef_codertarget_pixhawk_blocks_Se_T*/

#ifndef typedef_struct_T_px4demo_attitude_sys_T
#define typedef_struct_T_px4demo_attitude_sys_T

typedef struct {
  real_T f0[2];
} struct_T_px4demo_attitude_sys_T;

#endif                                 /*typedef_struct_T_px4demo_attitude_sys_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_px4demo_attitude_syst_T RT_MODEL_px4demo_attitude_sys_T;

#endif                                 /* RTW_HEADER_px4demo_attitude_system20190504_roll_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
