/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20180822car.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20180822car'.
 *
 * Model version                  : 1.380
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jul 30 10:34:50 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_control20180822car_h_
#define RTW_HEADER_px4demo_attitude_control20180822car_h_
#include <math.h>
#include <string.h>
#ifndef px4demo_attitude_control20180822car_COMMON_INCLUDES_
# define px4demo_attitude_control20180822car_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* px4demo_attitude_control20180822car_COMMON_INCLUDES_ */

#include "px4demo_attitude_control20180822car_types.h"

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

/* Block signals for model 'px4demo_attitude_control20180822car' */
typedef struct {
  real32_T pn[3];                      /* '<S3>/MATLAB Function' */
  real_T y_j;                          /* '<S3>/MATLAB Function5' */
  real_T UnitDelay;                    /* '<S3>/Unit Delay' */
  real_T Sum;                          /* '<S21>/Sum' */
  real_T Saturate;                     /* '<S21>/Saturate' */
  real_T UnitDelay1;                   /* '<S3>/Unit Delay1' */
  real_T Sum_a;                        /* '<S20>/Sum' */
  real_T Saturate_p;                   /* '<S20>/Saturate' */
  real_T SumI1;                        /* '<S21>/SumI1' */
  real_T SumI1_m;                      /* '<S20>/SumI1' */
  real_T y_h;                          /* '<S3>/MATLAB Function' */
  real_T y_f;                          /* '<S3>/MATLAB Function10' */
  real_T yaw_pwm;                      /* '<S3>/MATLAB Function' */
  real_T thera_new;                    /* '<S3>/MATLAB Function' */
  real_T positionx;                    /* '<S3>/MATLAB Function' */
  real_T positiony;                    /* '<S3>/MATLAB Function' */
  real_T Quadrant;                     /* '<S3>/MATLAB Function' */
  real32_T vector_b[2];                /* '<S3>/MATLAB Function' */
  real32_T vector_a[2];                /* '<S3>/MATLAB Function' */
  real32_T Gain1;                      /* '<S3>/Gain1' */
  real32_T RateTransition;             /* '<S3>/Rate Transition' */
  real32_T RateTransition1;            /* '<S3>/Rate Transition1' */
  real32_T Gain1_k;                    /* '<Root>/Gain1' */
  real32_T Gain5;                      /* '<Root>/Gain5' */
  real32_T Gain6;                      /* '<Root>/Gain6' */
  real32_T a;
  real32_T b_a;
  real32_T Gain3;                      /* '<S3>/Gain3' */
  real32_T DataTypeConversion11;       /* '<S3>/Data Type Conversion11' */
  real32_T Sum1;                       /* '<S3>/Sum1' */
  real32_T Switch2;                    /* '<Root>/Switch2' */
  real32_T y_n;                        /* '<S3>/MATLAB Function9' */
  real32_T y_jg;                       /* '<S3>/MATLAB Function7' */
  real32_T dif_thera;                  /* '<S3>/MATLAB Function' */
  real32_T rtb_Switch1_idx_1;
  real32_T vector_a1_idx_0;
  int32_T q;
  int32_T q1;
  int32_T arrival;
  int32_T y;                           /* '<S3>/MATLAB Function8' */
  int32_T y1;                          /* '<S3>/MATLAB Function' */
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out2;/* '<Root>/pwm_out2' */
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out1;/* '<Root>/pwm_out1' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction6;/* '<S3>/MATLAB Function6' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction4;/* '<S3>/MATLAB Function4' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction3;/* '<S3>/MATLAB Function3' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction2;/* '<S3>/MATLAB Function2' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
} B_px4demo_attitude_control2_c_T;

/* Block states (auto storage) for model 'px4demo_attitude_control20180822car' */
typedef struct {
  real_T UnitDelay2_DSTATE;            /* '<S3>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<S3>/Unit Delay3' */
  real_T UnitDelay4_DSTATE;            /* '<S3>/Unit Delay4' */
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S21>/Integrator' */
  real_T UnitDelay1_DSTATE;            /* '<S3>/Unit Delay1' */
  real_T Integrator_DSTATE_n;          /* '<S20>/Integrator' */
  real32_T Delay2_DSTATE;              /* '<Root>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<Root>/Delay3' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
} DW_px4demo_attitude_control_f_T;

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
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1, int_T
  mdlref_TID2, RT_MODEL_px4demo_attitude_con_T *const
  px4demo_attitude_control2018_M, B_px4demo_attitude_control2_c_T *localB,
  DW_px4demo_attitude_control_f_T *localDW);
extern void px4demo_attitud_MATLABFunction1(real32_T rtu_u,
  B_MATLABFunction1_px4demo_att_T *localB);
extern void px4demo_attitud_MATLABFunction2(real32_T rtu_u,
  B_MATLABFunction2_px4demo_att_T *localB);
extern void px4demo_attitude_contr_pwm_out1(real32_T rtu_Roll, real32_T
  rtu_Pitch, real32_T rtu_Yaw, real32_T rtu_Thrust,
  B_pwm_out1_px4demo_attitude_c_T *localB);
extern void px4demo_attitude_control20_Init(DW_px4demo_attitude_control_f_T
  *localDW);
extern void px4demo_attitude_control2018082(const real32_T *rtu_roll, const
  real32_T *rtu_pitch, const uint16_T *rtu_ch1, const uint16_T *rtu_ch2, const
  uint16_T *rtu_ch3, const uint16_T *rtu_ch4, const uint16_T *rtu_ch5, const
  uint16_T *rtu_ch6, const int32_T *rtu_lat, const int32_T *rtu_long, const
  real32_T *rtu_yaw, const real32_T *rtu_attin, uint16_T rty_PWM[4], boolean_T
  *rty_ARM_Control, real_T *rty_q1, real_T *rty_q, real32_T *rty_y_out, real32_T
  *rty_lat_out, real32_T *rty_long_out, real32_T *rty_waypoint, real32_T
  *rty_distance, real32_T *rty_rollout, real32_T *rty_pitchout, real32_T
  *rty_attout, B_px4demo_attitude_control2_c_T *localB,
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
 * '<Root>' : 'px4demo_attitude_control20180822car'
 * '<S1>'   : 'px4demo_attitude_control20180822car/ARMINGControl'
 * '<S2>'   : 'px4demo_attitude_control20180822car/ARMINGControl1'
 * '<S3>'   : 'px4demo_attitude_control20180822car/AttitudeControl'
 * '<S4>'   : 'px4demo_attitude_control20180822car/InputConditioning'
 * '<S5>'   : 'px4demo_attitude_control20180822car/pwm_out1'
 * '<S6>'   : 'px4demo_attitude_control20180822car/pwm_out2'
 * '<S7>'   : 'px4demo_attitude_control20180822car/ARMINGControl/Compare To Constant3'
 * '<S8>'   : 'px4demo_attitude_control20180822car/ARMINGControl1/Compare To Constant3'
 * '<S9>'   : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function'
 * '<S10>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function1'
 * '<S11>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function10'
 * '<S12>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function2'
 * '<S13>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function3'
 * '<S14>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function4'
 * '<S15>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function5'
 * '<S16>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function6'
 * '<S17>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function7'
 * '<S18>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function8'
 * '<S19>'  : 'px4demo_attitude_control20180822car/AttitudeControl/MATLAB Function9'
 * '<S20>'  : 'px4demo_attitude_control20180822car/AttitudeControl/pitch'
 * '<S21>'  : 'px4demo_attitude_control20180822car/AttitudeControl/roll'
 */
#endif                                 /* RTW_HEADER_px4demo_attitude_control20180822car_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
