/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311roll.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311roll'.
 *
 * Model version                  : 1.388
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jun 04 19:06:10 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_control20190311roll_h_
#define RTW_HEADER_px4demo_attitude_control20190311roll_h_
#include <string.h>
#ifndef px4demo_attitude_control20190311roll_COMMON_INCLUDES_
# define px4demo_attitude_control20190311roll_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* px4demo_attitude_control20190311roll_COMMON_INCLUDES_ */

#include "px4demo_attitude_control20190311roll_types.h"

/* Shared type includes */
#include "model_reference_types.h"
#include "rt_roundf_snf.h"

/* Block signals for system '<S3>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function1' */
} B_MATLABFunction1_px4demo_att_T;

/* Block signals for system '<S3>/MATLAB Function2' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function2' */
} B_MATLABFunction2_px4demo_att_T;

/* Block signals for system '<Root>/pwm_out1' */
typedef struct {
  uint16_T M1;                         /* '<Root>/pwm_out1' */
  uint16_T M2;                         /* '<Root>/pwm_out1' */
  uint16_T M3;                         /* '<Root>/pwm_out1' */
  uint16_T M4;                         /* '<Root>/pwm_out1' */
} B_pwm_out1_px4demo_attitude_c_T;

/* Block signals for model 'px4demo_attitude_control20190311roll' */
typedef struct {
  real32_T Switch1[4];                 /* '<Root>/Switch1' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T Saturate;                     /* '<S16>/Saturate' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T Sum_j;                        /* '<S17>/Sum' */
  real_T Saturate_o;                   /* '<S17>/Saturate' */
  real_T Sum_m;                        /* '<S15>/Sum' */
  real_T Saturate_d;                   /* '<S15>/Saturate' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T Sum_f;                        /* '<S14>/Sum' */
  real_T Saturate_h;                   /* '<S14>/Saturate' */
  real_T DataTypeConversion10;         /* '<S3>/Data Type Conversion10' */
  real_T rty_mode;
  real32_T Gain5;                      /* '<Root>/Gain5' */
  real32_T Gain6;                      /* '<Root>/Gain6' */
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out2;/* '<Root>/pwm_out2' */
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out1;/* '<Root>/pwm_out1' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction6;/* '<S3>/MATLAB Function6' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction4;/* '<S3>/MATLAB Function4' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction3;/* '<S3>/MATLAB Function3' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction2;/* '<S3>/MATLAB Function2' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
} B_px4demo_attitude_control2_c_T;

/* Block states (auto storage) for model 'px4demo_attitude_control20190311roll' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S16>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S17>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S15>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S14>/Integrator' */
  real_T UnitDelay4_DSTATE;            /* '<S3>/Unit Delay4' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
} DW_px4demo_attitude_control_f_T;

/* Invariant block signals for model 'px4demo_attitude_control20190311roll' */
typedef struct {
  const real_T Gain3;                  /* '<S3>/Gain3' */
  const real_T Constant7;              /* '<S3>/Constant7' */
  const real_T Constant3;              /* '<S3>/Constant3' */
  const real_T Constant;               /* '<S3>/Constant' */
  const real_T Constant8;              /* '<S3>/Constant8' */
  const real_T Constant4;              /* '<S3>/Constant4' */
  const real_T Constant5;              /* '<S3>/Constant5' */
  const real_T Constant6;              /* '<S3>/Constant6' */
} ConstB_px4demo_attitude_con_h_T;

/* Real-time Model Data Structure */
struct tag_RTM_px4demo_attitude_cont_T {
  const char_T **errorStatus;
};

typedef struct {
  B_px4demo_attitude_control2_c_T rtb;
  DW_px4demo_attitude_control_f_T rtdw;
  RT_MODEL_px4demo_attitude_con_T rtm;
} MdlrefDW_px4demo_attitude_con_T;

/* Model reference registration function */
extern void px4demo_attitude_con_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
  RT_MODEL_px4demo_attitude_con_T *const px4demo_attitude_control2019_M,
  B_px4demo_attitude_control2_c_T *localB, DW_px4demo_attitude_control_f_T
  *localDW);
extern void px4demo_attitud_MATLABFunction1(real32_T rtu_u,
  B_MATLABFunction1_px4demo_att_T *localB);
extern void px4demo_attitud_MATLABFunction2(real32_T rtu_u,
  B_MATLABFunction2_px4demo_att_T *localB);
extern void px4demo_attitude_contr_pwm_out1(real32_T rtu_Roll, real32_T
  rtu_Pitch, real32_T rtu_Yaw, real32_T rtu_Thrust,
  B_pwm_out1_px4demo_attitude_c_T *localB);
extern void px4demo_attitude_control2019031(const real32_T *rtu_roll, const
  real32_T *rtu_pitch, const uint16_T *rtu_ch1, const uint16_T *rtu_ch2, const
  uint16_T *rtu_ch3, const uint16_T *rtu_ch4, const uint16_T *rtu_ch5, const
  uint16_T *rtu_ch6, const real32_T *rtu_P, const real32_T *rtu_Q, uint16_T
  rty_PWM[4], boolean_T *rty_ARM_Control, real32_T *rty_rollout, real32_T
  *rty_pitchout, boolean_T *rty_mode, B_px4demo_attitude_control2_c_T *localB,
  DW_px4demo_attitude_control_f_T *localDW);

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
 * '<Root>' : 'px4demo_attitude_control20190311roll'
 * '<S1>'   : 'px4demo_attitude_control20190311roll/ARMINGControl'
 * '<S2>'   : 'px4demo_attitude_control20190311roll/ARMINGControl1'
 * '<S3>'   : 'px4demo_attitude_control20190311roll/AttitudeControl'
 * '<S4>'   : 'px4demo_attitude_control20190311roll/InputConditioning'
 * '<S5>'   : 'px4demo_attitude_control20190311roll/pwm_out1'
 * '<S6>'   : 'px4demo_attitude_control20190311roll/pwm_out2'
 * '<S7>'   : 'px4demo_attitude_control20190311roll/ARMINGControl/Compare To Constant3'
 * '<S8>'   : 'px4demo_attitude_control20190311roll/ARMINGControl1/Compare To Constant3'
 * '<S9>'   : 'px4demo_attitude_control20190311roll/AttitudeControl/MATLAB Function1'
 * '<S10>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/MATLAB Function2'
 * '<S11>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/MATLAB Function3'
 * '<S12>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/MATLAB Function4'
 * '<S13>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/MATLAB Function6'
 * '<S14>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/PITCH'
 * '<S15>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/pitch1'
 * '<S16>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/roll'
 * '<S17>'  : 'px4demo_attitude_control20190311roll/AttitudeControl/roll1'
 */
#endif                                 /* RTW_HEADER_px4demo_attitude_control20190311roll_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
