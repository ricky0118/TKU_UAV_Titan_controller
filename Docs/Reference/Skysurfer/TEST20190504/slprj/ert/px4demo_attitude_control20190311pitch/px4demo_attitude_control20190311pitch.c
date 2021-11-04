/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311pitch.c
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311pitch'.
 *
 * Model version                  : 1.390
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue May 14 07:51:22 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_control20190311pitch.h"
#include "px4demo_attitude_control20190311pitch_private.h"

int_T px4demo_attitude_cont_GlobalTID[2];
const rtTimingBridge *px4demo_attitude_con_TimingBrdg;

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function1'
 *    '<S3>/MATLAB Function4'
 */
void px4demo_attitud_MATLABFunction1(real32_T rtu_u,
  B_MATLABFunction1_px4demo_att_T *localB)
{
  /* MATLAB Function 'AttitudeControl/MATLAB Function1': '<S9>:1' */
  /* '<S9>:1:3' */
  localB->y = rt_roundf_snf(rtu_u * 10.0F) / 10.0F;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function2'
 *    '<S3>/MATLAB Function3'
 *    '<S3>/MATLAB Function6'
 */
void px4demo_attitud_MATLABFunction2(real32_T rtu_u,
  B_MATLABFunction2_px4demo_att_T *localB)
{
  /* MATLAB Function 'AttitudeControl/MATLAB Function2': '<S10>:1' */
  /* '<S10>:1:3' */
  localB->y = rt_roundf_snf(rtu_u * 100.0F) / 100.0F;
}

/*
 * Output and update for atomic system:
 *    '<Root>/pwm_out1'
 *    '<Root>/pwm_out2'
 */
void px4demo_attitude_contr_pwm_out1(real32_T rtu_Roll, real32_T rtu_Pitch,
  real32_T rtu_Yaw, real32_T rtu_Thrust, B_pwm_out1_px4demo_attitude_c_T *localB)
{
  real32_T tmp;

  /* MATLAB Function 'pwm_out1': '<S5>:1' */
  /* idle_PWM = uint16(1000); */
  /*  Quad X */
  /*  M1 = ((Roll + Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((-Roll + Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Roll - Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Roll - Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M5 = 1000; */
  /*  M6 = 1000; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Quad + */
  /*  M1 = ((Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((-Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = 1000; */
  /*  M6 = 1000; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Hex X */
  /*  M1 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M6 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Hex X (From Adam) */
  /* '<S5>:1:36' */
  tmp = rt_roundf_snf(rtu_Roll * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M1 = (uint16_T)tmp;
    } else {
      localB->M1 = 0U;
    }
  } else {
    localB->M1 = MAX_uint16_T;
  }

  /* '<S5>:1:37' */
  tmp = rt_roundf_snf(rtu_Pitch * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M2 = (uint16_T)tmp;
    } else {
      localB->M2 = 0U;
    }
  } else {
    localB->M2 = MAX_uint16_T;
  }

  /* '<S5>:1:38' */
  tmp = rt_roundf_snf(rtu_Thrust * 800.0F + 1100.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M3 = (uint16_T)tmp;
    } else {
      localB->M3 = 0U;
    }
  } else {
    localB->M3 = MAX_uint16_T;
  }

  /* '<S5>:1:39' */
  tmp = rt_roundf_snf(rtu_Yaw * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M4 = (uint16_T)tmp;
    } else {
      localB->M4 = 0U;
    }
  } else {
    localB->M4 = MAX_uint16_T;
  }

  /*  Hex X (Version 2) */
  /*  Roll/Yaw */
  /*  M1 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  % + Pitch/Roll */
  /*  M6 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  % - Pitch/Roll */
  /*  M5 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
}

/* Output and update for referenced model: 'px4demo_attitude_control20190311pitch' */
void px4demo_attitude_control2019031(const real32_T *rtu_roll, const real32_T
  *rtu_pitch, const uint16_T *rtu_ch1, const uint16_T *rtu_ch2, const uint16_T
  *rtu_ch3, const uint16_T *rtu_ch4, const uint16_T *rtu_ch5, const uint16_T
  *rtu_ch6, const int32_T *rtu_P, const int32_T *rtu_Q, uint16_T rty_PWM[4],
  boolean_T *rty_ARM_Control, real32_T *rty_rollout, real32_T *rty_pitchout,
  boolean_T *rty_mode, B_px4demo_attitude_control2_c_T *localB,
  DW_px4demo_attitude_control_f_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_Saturation9;
  real32_T rtb_DataTypeConversion4;
  real32_T rtb_Saturation8;
  real32_T rtb_DataTypeConversion5;
  real32_T rtb_Gain1_k;
  real32_T rtb_Gain2_a;
  real32_T rtb_Gain3;
  real32_T rtb_Gain4;
  real32_T rtb_Saturation10;
  real32_T rtb_DataTypeConversion1_k;
  real32_T rtb_DataTypeConversion;
  real32_T rtb_Saturation7;
  real32_T rtb_Switch1_idx_2;
  real32_T rtb_Switch1_idx_3;
  real32_T u0;

  /* Delay: '<Root>/Delay1' */
  *rty_mode = localDW->Delay1_DSTATE;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  if (*rty_mode) {
    /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_DataTypeConversion4 = 0.0F;
    localB->rtb_Switch1_idx_1 = 0.0F;
    rtb_Switch1_idx_2 = 0.0F;
    rtb_Switch1_idx_3 = 0.0F;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    rtb_DataTypeConversion1_k = (real32_T)*rtu_P;

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    rtb_DataTypeConversion = (real32_T)*rtu_Q;

    /* DataTypeConversion: '<S3>/Data Type Conversion4' */
    rtb_DataTypeConversion4 = *rtu_roll;
    localB->rtb_Switch1_idx_1 = *rtu_pitch;
    rtb_Switch1_idx_2 = rtb_DataTypeConversion1_k;
    rtb_Switch1_idx_3 = rtb_DataTypeConversion;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Fcn: '<S4>/Fcn2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   */
  u0 = ((real32_T)*rtu_ch1 - 1500.0F) / 400.0F;

  /* Saturate: '<S4>/Saturation9' */
  if (u0 > 1.0F) {
    rtb_Saturation9 = 1.0F;
  } else if (u0 < (-1.0F)) {
    rtb_Saturation9 = (-1.0F);
  } else {
    rtb_Saturation9 = u0;
  }

  /* End of Saturate: '<S4>/Saturation9' */

  /* MATLAB Function: '<S3>/MATLAB Function3' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation9, &localB->sf_MATLABFunction3);

  /* MATLAB Function: '<S3>/MATLAB Function4' */
  px4demo_attitud_MATLABFunction1(rtb_DataTypeConversion4,
    &localB->sf_MATLABFunction4);

  /* Sum: '<S3>/Sum1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain2'
   */
  localB->Sum1 = 1.0F * localB->sf_MATLABFunction3.y -
    localB->sf_MATLABFunction4.y;

  /* Sum: '<S16>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S16>/Integrator'
   *  Gain: '<S16>/Proportional Gain'
   *  Gain: '<S3>/Gain2'
   *  Sum: '<S3>/Sum1'
   */
  localB->Sum = (1.0F * localB->sf_MATLABFunction3.y -
                 localB->sf_MATLABFunction4.y) * 1.10009301262288 +
    localDW->Integrator_DSTATE;

  /* Saturate: '<S16>/Saturate' */
  if (localB->Sum > 1.0) {
    localB->Saturate = 1.0;
  } else if (localB->Sum < (-1.0)) {
    localB->Saturate = (-1.0);
  } else {
    localB->Saturate = localB->Sum;
  }

  /* End of Saturate: '<S16>/Saturate' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  localB->Sum2 = localB->Saturate - rtb_Switch1_idx_2;

  /* Sum: '<S17>/Sum' incorporates:
   *  DiscreteIntegrator: '<S17>/Integrator'
   *  Gain: '<S17>/Proportional Gain'
   */
  localB->Sum_n = 0.0549143230570902 * localB->Sum2 +
    localDW->Integrator_DSTATE_c;

  /* Saturate: '<S17>/Saturate' */
  if (localB->Sum_n > 1.0) {
    localB->Saturate_b = 1.0;
  } else if (localB->Sum_n < (-1.0)) {
    localB->Saturate_b = (-1.0);
  } else {
    localB->Saturate_b = localB->Sum_n;
  }

  /* End of Saturate: '<S17>/Saturate' */

  /* DataTypeConversion: '<S3>/Data Type Conversion6' */
  *rty_rollout = (real32_T)localB->Saturate_b;

  /* Fcn: '<S4>/Fcn5' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  u0 = ((real32_T)*rtu_ch2 - 1500.0F) / 400.0F;

  /* Saturate: '<S4>/Saturation8' */
  if (u0 > 1.0F) {
    rtb_Saturation8 = 1.0F;
  } else if (u0 < (-1.0F)) {
    rtb_Saturation8 = (-1.0F);
  } else {
    rtb_Saturation8 = u0;
  }

  /* End of Saturate: '<S4>/Saturation8' */

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation8, &localB->sf_MATLABFunction2);

  /* DataTypeConversion: '<S3>/Data Type Conversion5' */
  rtb_DataTypeConversion5 = localB->rtb_Switch1_idx_1;

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  px4demo_attitud_MATLABFunction1(rtb_DataTypeConversion5,
    &localB->sf_MATLABFunction1);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  if (*rty_mode) {
    localB->rty_mode = px4demo_attitude_control_ConstB.Gain3;
  } else {
    localB->rty_mode = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Gain: '<S3>/Gain'
   */
  localB->Sum_e = ((real_T)(1.0F * localB->sf_MATLABFunction2.y) -
                   localB->sf_MATLABFunction1.y) + localB->rty_mode;

  /* Sum: '<S15>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  DiscreteIntegrator: '<S15>/Integrator'
   *  Gain: '<S15>/Proportional Gain'
   */
  localB->Sum_a = 1.8545410952272 * localB->Sum_e + localDW->Integrator_DSTATE_n;

  /* Saturate: '<S15>/Saturate' */
  if (localB->Sum_a > 1.0) {
    localB->Saturate_p = 1.0;
  } else if (localB->Sum_a < (-1.0)) {
    localB->Saturate_p = (-1.0);
  } else {
    localB->Saturate_p = localB->Sum_a;
  }

  /* End of Saturate: '<S15>/Saturate' */

  /* Sum: '<S3>/Sum3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   */
  localB->Sum3 = localB->Saturate_p - rtb_Switch1_idx_3;

  /* Sum: '<S14>/Sum' incorporates:
   *  DiscreteIntegrator: '<S14>/Integrator'
   *  Gain: '<S14>/Proportional Gain'
   */
  localB->Sum_c = 0.92594405565099358 * localB->Sum3 +
    localDW->Integrator_DSTATE_p;

  /* Saturate: '<S14>/Saturate' */
  if (localB->Sum_c > 1.0) {
    localB->Saturate_c = 1.0;
  } else if (localB->Sum_c < (-1.0)) {
    localB->Saturate_c = (-1.0);
  } else {
    localB->Saturate_c = localB->Sum_c;
  }

  /* End of Saturate: '<S14>/Saturate' */

  /* DataTypeConversion: '<S3>/Data Type Conversion7' */
  *rty_pitchout = (real32_T)localB->Saturate_c;
  if (rtmIsSampleHit(1, 0)) {
    /* Fcn: '<S4>/Fcn7' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     */
    u0 = ((real32_T)*rtu_ch4 - 1500.0F) / 400.0F;

    /* Saturate: '<S4>/Saturation7' */
    if (u0 > 1.0F) {
      rtb_Saturation7 = 1.0F;
    } else if (u0 < (-1.0F)) {
      rtb_Saturation7 = (-1.0F);
    } else {
      rtb_Saturation7 = u0;
    }

    /* End of Saturate: '<S4>/Saturation7' */

    /* MATLAB Function: '<S3>/MATLAB Function6' */
    px4demo_attitud_MATLABFunction2(rtb_Saturation7, &localB->sf_MATLABFunction6);

    /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion9'
     *  Gain: '<S3>/Gain1'
     */
    localB->DataTypeConversion10 = 1.0F * localB->sf_MATLABFunction6.y;

    /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
     *  UnitDelay: '<S3>/Unit Delay4'
     */
    localB->DataTypeConversion11 = (real32_T)localDW->UnitDelay4_DSTATE;

    /* Gain: '<Root>/Gain5' */
    localB->Gain5 = 1.0F * localB->DataTypeConversion11;

    /* Gain: '<Root>/Gain6' */
    localB->Gain6 = 1.0F * rtb_Saturation7;
  }

  /* Gain: '<Root>/Gain1' */
  rtb_Gain1_k = (-1.0F) * *rty_rollout;

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2_a = (-1.0F) * *rty_pitchout;

  /* Gain: '<Root>/Gain3' */
  rtb_Gain3 = (-1.0F) * rtb_Saturation9;

  /* Gain: '<Root>/Gain4' */
  rtb_Gain4 = (-1.0F) * rtb_Saturation8;

  /* Fcn: '<S4>/Fcn6' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   */
  u0 = ((real32_T)*rtu_ch3 - 1100.0F) / 800.0F;

  /* Saturate: '<S4>/Saturation10' */
  if (u0 > 1.0F) {
    rtb_Saturation10 = 1.0F;
  } else if (u0 < 0.0F) {
    rtb_Saturation10 = 0.0F;
  } else {
    rtb_Saturation10 = u0;
  }

  /* End of Saturate: '<S4>/Saturation10' */

  /* MATLAB Function: '<Root>/pwm_out1' */
  px4demo_attitude_contr_pwm_out1(rtb_Gain1_k, rtb_Gain2_a, localB->Gain5,
    rtb_Saturation10, &localB->sf_pwm_out1);

  /* MATLAB Function: '<Root>/pwm_out2' */
  px4demo_attitude_contr_pwm_out1(rtb_Gain3, rtb_Gain4, localB->Gain6,
    rtb_Saturation10, &localB->sf_pwm_out2);

  /* Switch: '<Root>/Switch' incorporates:
   *  Saturate: '<Root>/Output_Limits1'
   */
  if (*rty_mode) {
    /* Saturate: '<Root>/Output_Limits2' */
    if (localB->sf_pwm_out2.M1 > ((uint16_T)2000U)) {
      rty_PWM[0] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M1 < ((uint16_T)1000U)) {
      rty_PWM[0] = ((uint16_T)1000U);
    } else {
      rty_PWM[0] = localB->sf_pwm_out2.M1;
    }

    if (localB->sf_pwm_out2.M2 > ((uint16_T)2000U)) {
      rty_PWM[1] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M2 < ((uint16_T)1000U)) {
      rty_PWM[1] = ((uint16_T)1000U);
    } else {
      rty_PWM[1] = localB->sf_pwm_out2.M2;
    }

    if (localB->sf_pwm_out2.M3 > ((uint16_T)2000U)) {
      rty_PWM[2] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M3 < ((uint16_T)1000U)) {
      rty_PWM[2] = ((uint16_T)1000U);
    } else {
      rty_PWM[2] = localB->sf_pwm_out2.M3;
    }

    if (localB->sf_pwm_out2.M4 > ((uint16_T)2000U)) {
      rty_PWM[3] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M4 < ((uint16_T)1000U)) {
      rty_PWM[3] = ((uint16_T)1000U);
    } else {
      rty_PWM[3] = localB->sf_pwm_out2.M4;
    }

    /* End of Saturate: '<Root>/Output_Limits2' */
  } else {
    if (localB->sf_pwm_out1.M1 > ((uint16_T)2000U)) {
      /* Saturate: '<Root>/Output_Limits1' */
      rty_PWM[0] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M1 < ((uint16_T)1000U)) {
      /* Saturate: '<Root>/Output_Limits1' */
      rty_PWM[0] = ((uint16_T)1000U);
    } else {
      rty_PWM[0] = localB->sf_pwm_out1.M1;
    }

    /* Saturate: '<Root>/Output_Limits1' */
    if (localB->sf_pwm_out1.M2 > ((uint16_T)2000U)) {
      rty_PWM[1] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M2 < ((uint16_T)1000U)) {
      rty_PWM[1] = ((uint16_T)1000U);
    } else {
      rty_PWM[1] = localB->sf_pwm_out1.M2;
    }

    if (localB->sf_pwm_out1.M3 > ((uint16_T)2000U)) {
      rty_PWM[2] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M3 < ((uint16_T)1000U)) {
      rty_PWM[2] = ((uint16_T)1000U);
    } else {
      rty_PWM[2] = localB->sf_pwm_out1.M3;
    }

    if (localB->sf_pwm_out1.M4 > ((uint16_T)2000U)) {
      rty_PWM[3] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M4 < ((uint16_T)1000U)) {
      rty_PWM[3] = ((uint16_T)1000U);
    } else {
      rty_PWM[3] = localB->sf_pwm_out1.M4;
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* Delay: '<Root>/Delay' */
  *rty_ARM_Control = localDW->Delay_DSTATE;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  localDW->Delay1_DSTATE = (*rtu_ch6 >= ((uint16_T)1300U));

  /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  Gain: '<S16>/Integral Gain'
   *  Gain: '<S16>/Kb'
   *  Sum: '<S16>/SumI1'
   *  Sum: '<S16>/SumI2'
   */
  localDW->Integrator_DSTATE += ((localB->Saturate - localB->Sum) * 1.0 +
    0.0135349169634299 * localB->Sum1) * 0.004;

  /* Update for DiscreteIntegrator: '<S17>/Integrator' incorporates:
   *  Gain: '<S17>/Integral Gain'
   *  Gain: '<S17>/Kb'
   *  Sum: '<S17>/SumI1'
   *  Sum: '<S17>/SumI2'
   */
  localDW->Integrator_DSTATE_c += ((localB->Saturate_b - localB->Sum_n) * 1.0 +
    1.1637891162682 * localB->Sum2) * 0.004;

  /* Update for DiscreteIntegrator: '<S15>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  Gain: '<S15>/Integral Gain'
   *  Gain: '<S15>/Kb'
   *  Sum: '<S15>/SumI1'
   *  Sum: '<S15>/SumI2'
   */
  localDW->Integrator_DSTATE_n += ((localB->Saturate_p - localB->Sum_a) * 1.0 +
    2.0387841436751 * localB->Sum_e) * 0.004;

  /* Update for DiscreteIntegrator: '<S14>/Integrator' incorporates:
   *  Gain: '<S14>/Integral Gain'
   *  Gain: '<S14>/Kb'
   *  Sum: '<S14>/SumI1'
   *  Sum: '<S14>/SumI2'
   */
  localDW->Integrator_DSTATE_p += ((localB->Saturate_c - localB->Sum_c) * 1.0 +
    0.746476159593003 * localB->Sum3) * 0.004;
  if (rtmIsSampleHit(1, 0)) {
    /* Update for UnitDelay: '<S3>/Unit Delay4' */
    localDW->UnitDelay4_DSTATE = localB->DataTypeConversion10;
  }

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  localDW->Delay_DSTATE = (*rtu_ch5 >= ((uint16_T)1500U));
}

/* Model initialize function */
void px4demo_attitude_con_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
  RT_MODEL_px4demo_attitude_con_T *const px4demo_attitude_control2019_M,
  B_px4demo_attitude_control2_c_T *localB, DW_px4demo_attitude_control_f_T
  *localDW)
{
  /* Registration code */

  /* setup the global timing engine */
  px4demo_attitude_cont_GlobalTID[0] = mdlref_TID0;
  px4demo_attitude_cont_GlobalTID[1] = mdlref_TID1;
  px4demo_attitude_con_TimingBrdg = timingBridge;

  /* initialize error status */
  rtmSetErrorStatusPointer(px4demo_attitude_control2019_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_px4demo_attitude_control2_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_px4demo_attitude_control_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
