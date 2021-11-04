/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311roll_private.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311roll'.
 *
 * Model version                  : 1.382
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat May 11 23:52:28 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_control20190311roll_private_h_
#define RTW_HEADER_px4demo_attitude_control20190311roll_private_h_
#include "rtwtypes.h"
#include "px4demo_attitude_control20190311roll.h"

extern real32_T rt_roundf_snf(real32_T u);
extern void px4demo_attitud_MATLABFunction1(real32_T rtu_u,
  B_MATLABFunction1_px4demo_att_T *localB);
extern void px4demo_attitud_MATLABFunction2(real32_T rtu_u,
  B_MATLABFunction2_px4demo_att_T *localB);
extern void px4demo_attitude_contr_pwm_out1(real32_T rtu_Roll, real32_T
  rtu_Pitch, real32_T rtu_Yaw, real32_T rtu_Thrust,
  B_pwm_out1_px4demo_attitude_c_T *localB);

#endif                                 /* RTW_HEADER_px4demo_attitude_control20190311roll_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
