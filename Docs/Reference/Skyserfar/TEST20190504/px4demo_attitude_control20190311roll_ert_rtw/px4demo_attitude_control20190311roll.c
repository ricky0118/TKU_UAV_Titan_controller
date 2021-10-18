/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311roll.c
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

#include "px4demo_attitude_control20190311roll.h"
#include "px4demo_attitude_control20190311roll_private.h"

/* Block signals (auto storage) */
B_px4demo_attitude_control201_T px4demo_attitude_control20190_B;

/* Block states (auto storage) */
DW_px4demo_attitude_control20_T px4demo_attitude_control2019_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_px4demo_attitude_control_T px4demo_attitude_control20190_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_px4demo_attitude_control_T px4demo_attitude_control20190_Y;

/* Real-time model */
RT_MODEL_px4demo_attitude_con_T px4demo_attitude_control2019_M_;
RT_MODEL_px4demo_attitude_con_T *const px4demo_attitude_control2019_M =
  &px4demo_attitude_control2019_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1]) > 24) {/* Sample time: [0.1s, 0.0s] */
    px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

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

/* Model step function */
void px4demo_attitude_control20190311roll_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Saturation7;
  real32_T rtb_Sum_gx;
  real_T rtb_Saturate_l;
  real_T rtb_DataTypeConversion10;
  real32_T rtb_Saturation9;
  real32_T rtb_Saturation8;
  real32_T rtb_Saturation10;
  real32_T rtb_Switch1_idx_1;
  real32_T rtb_Switch1_idx_2;
  real32_T rtb_Switch1_idx_3;
  real_T tmp;

  /* Fcn: '<S4>/Fcn2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  Inport: '<Root>/ch1'
   */
  rtb_Saturation9 = ((real32_T)px4demo_attitude_control20190_U.ch1 - 1500.0F) /
    400.0F;

  /* Saturate: '<S4>/Saturation9' */
  if (rtb_Saturation9 > 1.0F) {
    rtb_Saturation9 = 1.0F;
  } else {
    if (rtb_Saturation9 < (-1.0F)) {
      rtb_Saturation9 = (-1.0F);
    }
  }

  /* End of Saturate: '<S4>/Saturation9' */

  /* Fcn: '<S4>/Fcn5' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   *  Inport: '<Root>/ch2'
   */
  rtb_Saturation8 = ((real32_T)px4demo_attitude_control20190_U.ch2 - 1500.0F) /
    400.0F;

  /* Saturate: '<S4>/Saturation8' */
  if (rtb_Saturation8 > 1.0F) {
    rtb_Saturation8 = 1.0F;
  } else {
    if (rtb_Saturation8 < (-1.0F)) {
      rtb_Saturation8 = (-1.0F);
    }
  }

  /* End of Saturate: '<S4>/Saturation8' */
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* Fcn: '<S4>/Fcn7' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     *  Inport: '<Root>/ch4'
     */
    rtb_Saturation10 = ((real32_T)px4demo_attitude_control20190_U.ch4 - 1500.0F)
      / 400.0F;

    /* Saturate: '<S4>/Saturation7' */
    if (rtb_Saturation10 > 1.0F) {
      rtb_Saturation7 = 1.0F;
    } else if (rtb_Saturation10 < (-1.0F)) {
      rtb_Saturation7 = (-1.0F);
    } else {
      rtb_Saturation7 = rtb_Saturation10;
    }

    /* End of Saturate: '<S4>/Saturation7' */

    /* Gain: '<Root>/Gain6' */
    px4demo_attitude_control20190_B.Gain6 = 1.0F * rtb_Saturation7;
  }

  /* Fcn: '<S4>/Fcn6' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   *  Inport: '<Root>/ch3'
   */
  rtb_Saturation10 = ((real32_T)px4demo_attitude_control20190_U.ch3 - 1100.0F) /
    800.0F;

  /* Saturate: '<S4>/Saturation10' */
  if (rtb_Saturation10 > 1.0F) {
    rtb_Saturation10 = 1.0F;
  } else {
    if (rtb_Saturation10 < 0.0F) {
      rtb_Saturation10 = 0.0F;
    }
  }

  /* End of Saturate: '<S4>/Saturation10' */

  /* MATLAB Function: '<Root>/pwm_out2' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   */
  px4demo_attitude_contr_pwm_out1((-1.0F) * rtb_Saturation9, (-1.0F) *
    rtb_Saturation8, px4demo_attitude_control20190_B.Gain6, rtb_Saturation10,
    &px4demo_attitude_control20190_B.sf_pwm_out2);

  /* MATLAB Function: '<S3>/MATLAB Function3' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation9,
    &px4demo_attitude_control20190_B.sf_MATLABFunction3);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Delay: '<Root>/Delay1'
   *  Inport: '<Root>/P'
   *  Inport: '<Root>/Q'
   *  Inport: '<Root>/pitch'
   *  Inport: '<Root>/roll'
   */
  if (px4demo_attitude_control2019_DW.Delay1_DSTATE) {
    rtb_Saturation9 = 0.0F;
    rtb_Switch1_idx_1 = 0.0F;
    rtb_Switch1_idx_2 = 0.0F;
    rtb_Switch1_idx_3 = 0.0F;
  } else {
    rtb_Saturation9 = px4demo_attitude_control20190_U.phi;
    rtb_Switch1_idx_1 = px4demo_attitude_control20190_U.theta;
    rtb_Switch1_idx_2 = (real32_T)px4demo_attitude_control20190_U.P;
    rtb_Switch1_idx_3 = (real32_T)px4demo_attitude_control20190_U.Q;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function4' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  px4demo_attitud_MATLABFunction1(rtb_Saturation9,
    &px4demo_attitude_control20190_B.sf_MATLABFunction4);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Delay: '<Root>/Delay1'
   */
  if (px4demo_attitude_control2019_DW.Delay1_DSTATE) {
    tmp = px4demo_attitude_control_ConstB.Gain3;
  } else {
    tmp = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Sum1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain2'
   */
  px4demo_attitude_control20190_B.Sum1 = ((real_T)(1.0F *
    px4demo_attitude_control20190_B.sf_MATLABFunction3.y) -
    px4demo_attitude_control20190_B.sf_MATLABFunction4.y) + tmp;

  /* Sum: '<S16>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S16>/Integrator'
   *  Gain: '<S16>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum = 1.10009301262288 *
    px4demo_attitude_control20190_B.Sum1 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE;

  /* Saturate: '<S16>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum > 1.0) {
    px4demo_attitude_control20190_B.Saturate = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate =
      px4demo_attitude_control20190_B.Sum;
  }

  /* End of Saturate: '<S16>/Saturate' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  px4demo_attitude_control20190_B.Sum2 =
    px4demo_attitude_control20190_B.Saturate - rtb_Switch1_idx_2;

  /* Sum: '<S17>/Sum' incorporates:
   *  DiscreteIntegrator: '<S17>/Integrator'
   *  Gain: '<S17>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum_j = 0.0549143230570902 *
    px4demo_attitude_control20190_B.Sum2 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_g;

  /* Saturate: '<S17>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_j > 1.0) {
    px4demo_attitude_control20190_B.Saturate_o = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_j < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate_o = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate_o =
      px4demo_attitude_control20190_B.Sum_j;
  }

  /* End of Saturate: '<S17>/Saturate' */

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation8,
    &px4demo_attitude_control20190_B.sf_MATLABFunction2);

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  px4demo_attitud_MATLABFunction1(rtb_Switch1_idx_1,
    &px4demo_attitude_control20190_B.sf_MATLABFunction1);

  /* Sum: '<S3>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Gain: '<S3>/Gain'
   */
  rtb_Sum_gx = 1.0F * px4demo_attitude_control20190_B.sf_MATLABFunction2.y -
    px4demo_attitude_control20190_B.sf_MATLABFunction1.y;

  /* Sum: '<S15>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  DiscreteIntegrator: '<S15>/Integrator'
   *  Gain: '<S15>/Proportional Gain'
   *  Gain: '<S3>/Gain'
   *  Sum: '<S3>/Sum'
   */
  px4demo_attitude_control20190_B.Sum_m = (1.0F *
    px4demo_attitude_control20190_B.sf_MATLABFunction2.y -
    px4demo_attitude_control20190_B.sf_MATLABFunction1.y) * 1.8545410952272 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_n;

  /* Saturate: '<S15>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_m > 1.0) {
    px4demo_attitude_control20190_B.Saturate_d = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_m < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate_d = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate_d =
      px4demo_attitude_control20190_B.Sum_m;
  }

  /* End of Saturate: '<S15>/Saturate' */

  /* Sum: '<S3>/Sum3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   */
  px4demo_attitude_control20190_B.Sum3 =
    px4demo_attitude_control20190_B.Saturate_d - rtb_Switch1_idx_3;

  /* Sum: '<S14>/Sum' incorporates:
   *  DiscreteIntegrator: '<S14>/Integrator'
   *  Gain: '<S14>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum_f = 0.92594405565099358 *
    px4demo_attitude_control20190_B.Sum3 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_k;

  /* Saturate: '<S14>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_f > 1.0) {
    rtb_Saturate_l = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_f < (-1.0)) {
    rtb_Saturate_l = (-1.0);
  } else {
    rtb_Saturate_l = px4demo_attitude_control20190_B.Sum_f;
  }

  /* End of Saturate: '<S14>/Saturate' */
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain5' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion11'
     *  UnitDelay: '<S3>/Unit Delay4'
     */
    px4demo_attitude_control20190_B.Gain5 = 1.0F * (real32_T)
      px4demo_attitude_control2019_DW.UnitDelay4_DSTATE;
  }

  /* MATLAB Function: '<Root>/pwm_out1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   */
  px4demo_attitude_contr_pwm_out1((-1.0F) * (real32_T)
    px4demo_attitude_control20190_B.Saturate_o, (-1.0F) * (real32_T)
    rtb_Saturate_l, px4demo_attitude_control20190_B.Gain5, rtb_Saturation10,
    &px4demo_attitude_control20190_B.sf_pwm_out1);

  /* Switch: '<Root>/Switch' incorporates:
   *  Delay: '<Root>/Delay1'
   *  Saturate: '<Root>/Output_Limits1'
   */
  if (px4demo_attitude_control2019_DW.Delay1_DSTATE) {
    /* Saturate: '<Root>/Output_Limits2' */
    if (px4demo_attitude_control20190_B.sf_pwm_out2.M1 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[0] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out2.M1 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[0] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[0] =
        px4demo_attitude_control20190_B.sf_pwm_out2.M1;
    }

    if (px4demo_attitude_control20190_B.sf_pwm_out2.M2 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out2.M2 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] =
        px4demo_attitude_control20190_B.sf_pwm_out2.M2;
    }

    if (px4demo_attitude_control20190_B.sf_pwm_out2.M3 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out2.M3 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] =
        px4demo_attitude_control20190_B.sf_pwm_out2.M3;
    }

    if (px4demo_attitude_control20190_B.sf_pwm_out2.M4 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out2.M4 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] =
        px4demo_attitude_control20190_B.sf_pwm_out2.M4;
    }

    /* End of Saturate: '<Root>/Output_Limits2' */
  } else {
    if (px4demo_attitude_control20190_B.sf_pwm_out1.M1 > ((uint16_T)2000U)) {
      /* Saturate: '<Root>/Output_Limits1' incorporates:
       *  Outport: '<Root>/PWM'
       */
      px4demo_attitude_control20190_Y.PWM[0] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out1.M1 < ((uint16_T)1000U))
    {
      /* Saturate: '<Root>/Output_Limits1' incorporates:
       *  Outport: '<Root>/PWM'
       */
      px4demo_attitude_control20190_Y.PWM[0] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' incorporates:
       *  Saturate: '<Root>/Output_Limits1'
       */
      px4demo_attitude_control20190_Y.PWM[0] =
        px4demo_attitude_control20190_B.sf_pwm_out1.M1;
    }

    /* Saturate: '<Root>/Output_Limits1' */
    if (px4demo_attitude_control20190_B.sf_pwm_out1.M2 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out1.M2 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[1] =
        px4demo_attitude_control20190_B.sf_pwm_out1.M2;
    }

    if (px4demo_attitude_control20190_B.sf_pwm_out1.M3 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out1.M3 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[2] =
        px4demo_attitude_control20190_B.sf_pwm_out1.M3;
    }

    if (px4demo_attitude_control20190_B.sf_pwm_out1.M4 > ((uint16_T)2000U)) {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] = ((uint16_T)2000U);
    } else if (px4demo_attitude_control20190_B.sf_pwm_out1.M4 < ((uint16_T)1000U))
    {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] = ((uint16_T)1000U);
    } else {
      /* Outport: '<Root>/PWM' */
      px4demo_attitude_control20190_Y.PWM[3] =
        px4demo_attitude_control20190_B.sf_pwm_out1.M4;
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outport: '<Root>/rollout' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  px4demo_attitude_control20190_Y.rollout = (real32_T)
    px4demo_attitude_control20190_B.Saturate_o;

  /* Outport: '<Root>/pitchout' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  px4demo_attitude_control20190_Y.pitchout = (real32_T)rtb_Saturate_l;

  /* Outport: '<Root>/mode' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  px4demo_attitude_control20190_Y.mode =
    px4demo_attitude_control2019_DW.Delay1_DSTATE;
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<S3>/MATLAB Function6' */
    px4demo_attitud_MATLABFunction2(rtb_Saturation7,
      &px4demo_attitude_control20190_B.sf_MATLABFunction6);

    /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion9'
     *  Gain: '<S3>/Gain1'
     */
    rtb_DataTypeConversion10 = 1.0F *
      px4demo_attitude_control20190_B.sf_MATLABFunction6.y;

    /* Update for UnitDelay: '<S3>/Unit Delay4' */
    px4demo_attitude_control2019_DW.UnitDelay4_DSTATE = rtb_DataTypeConversion10;
  }

  /* Outport: '<Root>/ARM_Control' incorporates:
   *  Delay: '<Root>/Delay'
   */
  px4demo_attitude_control20190_Y.ARM_Control =
    px4demo_attitude_control2019_DW.Delay_DSTATE;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/ch6'
   *  RelationalOperator: '<S8>/Compare'
   */
  px4demo_attitude_control2019_DW.Delay1_DSTATE =
    (px4demo_attitude_control20190_U.ch6 >= ((uint16_T)1300U));

  /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  Gain: '<S16>/Integral Gain'
   *  Gain: '<S16>/Kb'
   *  Sum: '<S16>/SumI1'
   *  Sum: '<S16>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE +=
    ((px4demo_attitude_control20190_B.Saturate -
      px4demo_attitude_control20190_B.Sum) * 1.0 + 0.0135349169634299 *
     px4demo_attitude_control20190_B.Sum1) * 0.004;

  /* Update for DiscreteIntegrator: '<S17>/Integrator' incorporates:
   *  Gain: '<S17>/Integral Gain'
   *  Gain: '<S17>/Kb'
   *  Sum: '<S17>/SumI1'
   *  Sum: '<S17>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_g +=
    ((px4demo_attitude_control20190_B.Saturate_o -
      px4demo_attitude_control20190_B.Sum_j) * 1.0 + 1.1637891162682 *
     px4demo_attitude_control20190_B.Sum2) * 0.004;

  /* Update for DiscreteIntegrator: '<S15>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  Gain: '<S15>/Integral Gain'
   *  Gain: '<S15>/Kb'
   *  Sum: '<S15>/SumI1'
   *  Sum: '<S15>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_n +=
    ((px4demo_attitude_control20190_B.Saturate_d -
      px4demo_attitude_control20190_B.Sum_m) * 1.0 + 2.0387841436751 *
     rtb_Sum_gx) * 0.004;

  /* Update for DiscreteIntegrator: '<S14>/Integrator' incorporates:
   *  Gain: '<S14>/Integral Gain'
   *  Gain: '<S14>/Kb'
   *  Sum: '<S14>/SumI1'
   *  Sum: '<S14>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_k += ((rtb_Saturate_l -
    px4demo_attitude_control20190_B.Sum_f) * 1.0 + 0.746476159593003 *
    px4demo_attitude_control20190_B.Sum3) * 0.004;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/ch5'
   *  RelationalOperator: '<S7>/Compare'
   */
  px4demo_attitude_control2019_DW.Delay_DSTATE =
    (px4demo_attitude_control20190_U.ch5 >= ((uint16_T)1500U));
  rate_scheduler();
}

/* Model initialize function */
void px4demo_attitude_control20190311roll_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)px4demo_attitude_control2019_M, 0,
                sizeof(RT_MODEL_px4demo_attitude_con_T));

  /* block I/O */
  (void) memset(((void *) &px4demo_attitude_control20190_B), 0,
                sizeof(B_px4demo_attitude_control201_T));

  /* states (dwork) */
  (void) memset((void *)&px4demo_attitude_control2019_DW, 0,
                sizeof(DW_px4demo_attitude_control20_T));

  /* external inputs */
  (void)memset((void *)&px4demo_attitude_control20190_U, 0, sizeof
               (ExtU_px4demo_attitude_control_T));

  /* external outputs */
  (void) memset((void *)&px4demo_attitude_control20190_Y, 0,
                sizeof(ExtY_px4demo_attitude_control_T));

  /* ConstCode for Outport: '<Root>/q1' incorporates:
   *  Constant: '<S3>/Constant7'
   */
  px4demo_attitude_control20190_Y.q1 = 520.0;

  /* ConstCode for Outport: '<Root>/q' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  px4demo_attitude_control20190_Y.q = 520.0;

  /* ConstCode for Outport: '<Root>/y_out' incorporates:
   *  Constant: '<S3>/Constant'
   */
  px4demo_attitude_control20190_Y.y_out = 520.0;

  /* ConstCode for Outport: '<Root>/lat_out' incorporates:
   *  Constant: '<S3>/Constant8'
   */
  px4demo_attitude_control20190_Y.lat_out = 520.0;

  /* ConstCode for Outport: '<Root>/long_out' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  px4demo_attitude_control20190_Y.long_out = 520.0;

  /* ConstCode for Outport: '<Root>/waypoint' incorporates:
   *  Constant: '<S3>/Constant5'
   */
  px4demo_attitude_control20190_Y.waypoint = 520.0;

  /* ConstCode for Outport: '<Root>/distance' incorporates:
   *  Constant: '<S3>/Constant6'
   */
  px4demo_attitude_control20190_Y.distance = 520.0;
}

/* Model terminate function */
void px4demo_attitude_control20190311roll_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
