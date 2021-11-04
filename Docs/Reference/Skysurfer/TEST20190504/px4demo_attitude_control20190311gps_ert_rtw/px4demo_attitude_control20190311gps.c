/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311gps.c
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311gps'.
 *
 * Model version                  : 1.388
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sun May 12 00:42:13 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_control20190311gps.h"
#include "px4demo_attitude_control20190311gps_private.h"

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

  (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[2])++;
  if ((px4demo_attitude_control2019_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [20.0s, 0.0s] */
    px4demo_attitude_control2019_M->Timing.TaskCounters.TID[2] = 0;
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
  /* MATLAB Function 'AttitudeControl/MATLAB Function1': '<S10>:1' */
  /* '<S10>:1:3' */
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
  /* MATLAB Function 'AttitudeControl/MATLAB Function2': '<S12>:1' */
  /* '<S12>:1:3' */
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
void px4demo_attitude_control20190311gps_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Saturation7;
  static const int32_T position[4] = { 251981990, 251989590, 1214213880,
    1214219020 };

  real32_T rtb_Switch;
  real32_T rtb_Sum1;
  real32_T rtb_Switch2;
  real32_T rtb_y_l;
  int32_T rtb_y;
  int32_T rtb_y1;
  real32_T rtb_y_a;
  real32_T rtb_dif_thera;
  real32_T rtb_Saturation9;
  real32_T rtb_Saturation8;
  real32_T rtb_Saturation10;
  real32_T rtb_Switch1_idx_1;
  real32_T rtb_Switch1_idx_2;
  real32_T rtb_Switch1_idx_3;

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
    rtb_Switch1_idx_2 = px4demo_attitude_control20190_U.P;
    rtb_Switch1_idx_3 = px4demo_attitude_control20190_U.Q;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function4' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  px4demo_attitud_MATLABFunction1(rtb_Saturation9,
    &px4demo_attitude_control20190_B.sf_MATLABFunction4);

  /* Gain: '<S3>/Gain3' incorporates:
   *  Inport: '<Root>/yaw'
   */
  px4demo_attitude_control20190_B.Gain3_m = 57.2957802F *
    px4demo_attitude_control20190_U.yaw;

  /* MATLAB Function: '<S3>/MATLAB Function7' */
  /* MATLAB Function 'AttitudeControl/MATLAB Function7': '<S17>:1' */
  if (px4demo_attitude_control20190_B.Gain3_m <= 0.0F) {
    /* '<S17>:1:2' */
    /* '<S17>:1:3' */
    rtb_y_a = 360.0F + px4demo_attitude_control20190_B.Gain3_m;
  } else {
    /* '<S17>:1:5' */
    rtb_y_a = px4demo_attitude_control20190_B.Gain3_m;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function7' */

  /* DataTypeConversion: '<S3>/Data Type Conversion17' incorporates:
   *  Inport: '<Root>/lat'
   */
  px4demo_attitude_control20190_B.DataTypeConversion17 =
    px4demo_attitude_control20190_U.lat;

  /* DataTypeConversion: '<S3>/Data Type Conversion18' incorporates:
   *  Inport: '<Root>/long'
   */
  px4demo_attitude_control20190_B.DataTypeConversion18 =
    px4demo_attitude_control20190_U.long_e;
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S3>/Unit Delay2' */
    px4demo_attitude_control20190_B.y_f =
      px4demo_attitude_control2019_DW.UnitDelay2_DSTATE;

    /* MATLAB Function: '<S3>/MATLAB Function5' incorporates:
     *  UnitDelay: '<S3>/Unit Delay2'
     *  UnitDelay: '<S3>/Unit Delay3'
     */
    /* MATLAB Function 'AttitudeControl/MATLAB Function5': '<S15>:1' */
    /* '<S15>:1:1' */
    if ((px4demo_attitude_control2019_DW.UnitDelay3_DSTATE == 1.0) &&
        (px4demo_attitude_control2019_DW.UnitDelay2_DSTATE <= 3.0)) {
      /* '<S15>:1:2' */
      /* '<S15>:1:3' */
      px4demo_attitude_control20190_B.y_f =
        px4demo_attitude_control2019_DW.UnitDelay2_DSTATE + 1.0;
    }

    if (px4demo_attitude_control20190_B.y_f == 3.0) {
      /* '<S15>:1:5' */
      /* '<S15>:1:6' */
      px4demo_attitude_control20190_B.y_f = 1.0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function5' */

    /* Outport: '<Root>/waypoint' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion14'
     */
    px4demo_attitude_control20190_Y.waypoint = (real32_T)
      px4demo_attitude_control20190_B.y_f;
  }

  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'AttitudeControl/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  /* '<S9>:1:6' */
  /* '<S9>:1:7' */
  /* '<S9>:1:8' */
  /* '<S9>:1:9' */
  /* '<S9>:1:10' */
  /* '<S9>:1:11' */
  /* '<S9>:1:12' */
  rtb_Saturation9 = (real32_T)position[(int32_T)
    px4demo_attitude_control20190_Y.waypoint - 1] -
    px4demo_attitude_control20190_B.DataTypeConversion17;
  px4demo_attitude_control20190_B.b_a = (real32_T)position[(int32_T)
    px4demo_attitude_control20190_Y.waypoint + 1] -
    px4demo_attitude_control20190_B.DataTypeConversion18;

  /* thera=acosd(dot(vector_a,vector_b)/(distance_a*distance_b)) */
  /* thera_new=acosd(dot(vector_a,vector_b)/(distance_a*distance_b)) */
  /* '<S9>:1:17' */
  /* '<S9>:1:18' */
  /* '<S9>:1:20' */
  rtb_Saturation9 = (real32_T)sqrt(rtb_Saturation9 * rtb_Saturation9 +
    px4demo_attitude_control20190_B.b_a * px4demo_attitude_control20190_B.b_a) /
    1000.0F;

  /* vector_a_y=(position(x,1)-latitutde); */
  /* vector_a_x=(position(x,2)-longitude); */
  /* '<S9>:1:24' */
  px4demo_attitude_control20190_B.b_a = (real32_T)atan(((real32_T)position
    [(int32_T)px4demo_attitude_control20190_Y.waypoint + 1] -
    px4demo_attitude_control20190_B.DataTypeConversion18) / ((real32_T)position
    [(int32_T)px4demo_attitude_control20190_Y.waypoint - 1] -
    px4demo_attitude_control20190_B.DataTypeConversion17)) * 57.2957802F;
  if (((real_T)position[(int32_T)px4demo_attitude_control20190_Y.waypoint - 1] >=
       px4demo_attitude_control20190_B.DataTypeConversion17) && ((real_T)
       position[(int32_T)px4demo_attitude_control20190_Y.waypoint + 1] >=
       px4demo_attitude_control20190_B.DataTypeConversion18)) {
    /* '<S9>:1:26' */
    /* '<S9>:1:27' */
    px4demo_attitude_control20190_B.b_a = (real32_T)fabs
      (px4demo_attitude_control20190_B.b_a);

    /* '<S9>:1:28' */
    px4demo_attitude_control20190_B.q = 1;
  } else if (((real_T)position[(int32_T)px4demo_attitude_control20190_Y.waypoint
              - 1] <= px4demo_attitude_control20190_B.DataTypeConversion17) &&
             ((real_T)position[(int32_T)px4demo_attitude_control20190_Y.waypoint
              + 1] >= px4demo_attitude_control20190_B.DataTypeConversion18)) {
    /* '<S9>:1:29' */
    /* '<S9>:1:30' */
    px4demo_attitude_control20190_B.b_a = (px4demo_attitude_control20190_B.b_a +
      90.0F) + 90.0F;

    /* '<S9>:1:31' */
    px4demo_attitude_control20190_B.q = 2;
  } else if (((real_T)position[(int32_T)px4demo_attitude_control20190_Y.waypoint
              - 1] <= px4demo_attitude_control20190_B.DataTypeConversion17) &&
             ((real_T)position[(int32_T)px4demo_attitude_control20190_Y.waypoint
              + 1] <= px4demo_attitude_control20190_B.DataTypeConversion18)) {
    /* '<S9>:1:32' */
    /* '<S9>:1:33' */
    px4demo_attitude_control20190_B.b_a += 180.0F;

    /* '<S9>:1:34' */
    px4demo_attitude_control20190_B.q = 3;
  } else {
    /* '<S9>:1:36' */
    px4demo_attitude_control20190_B.b_a = (px4demo_attitude_control20190_B.b_a +
      90.0F) + 270.0F;

    /* '<S9>:1:37' */
    px4demo_attitude_control20190_B.q = 4;
  }

  if ((rtb_y_a <= 90.0F) && (rtb_y_a > 0.0F)) {
    /* '<S9>:1:39' */
    /* '<S9>:1:40' */
    px4demo_attitude_control20190_B.q1 = 1;
  } else if ((rtb_y_a <= 180.0F) && (rtb_y_a > 90.0F)) {
    /* '<S9>:1:41' */
    /* '<S9>:1:42' */
    px4demo_attitude_control20190_B.q1 = 2;
  } else if ((rtb_y_a <= 270.0F) && (rtb_y_a > 180.0F)) {
    /* '<S9>:1:43' */
    /* '<S9>:1:44' */
    px4demo_attitude_control20190_B.q1 = 3;
  } else {
    /* '<S9>:1:46' */
    px4demo_attitude_control20190_B.q1 = 4;
  }

  /* '<S9>:1:48' */
  rtb_dif_thera = px4demo_attitude_control20190_B.b_a - rtb_y_a;
  if ((px4demo_attitude_control20190_B.q == 4) &&
      (px4demo_attitude_control20190_B.q1 == 1)) {
    /* '<S9>:1:49' */
    /* '<S9>:1:50' */
    px4demo_attitude_control20190_B.y_n = -0.4;

    /* '<S9>:1:51' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 4) &&
             (px4demo_attitude_control20190_B.q1 == 2)) {
    /* '<S9>:1:52' */
    /* '<S9>:1:53' */
    px4demo_attitude_control20190_B.y_n = -1.0;

    /* '<S9>:1:54' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 4) &&
             (px4demo_attitude_control20190_B.q1 == 3)) {
    /* '<S9>:1:55' */
    /* '<S9>:1:56' */
    px4demo_attitude_control20190_B.y_n = 0.4;

    /* '<S9>:1:57' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 3) &&
             (px4demo_attitude_control20190_B.q1 == 4)) {
    /* '<S9>:1:59' */
    /*  */
    /* '<S9>:1:60' */
    px4demo_attitude_control20190_B.y_n = -0.4;

    /* '<S9>:1:61' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 3) &&
             (px4demo_attitude_control20190_B.q1 == 1)) {
    /* '<S9>:1:62' */
    /* '<S9>:1:63' */
    px4demo_attitude_control20190_B.y_n = -1.0;

    /* '<S9>:1:64' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 3) &&
             (px4demo_attitude_control20190_B.q1 == 2)) {
    /* '<S9>:1:65' */
    /* '<S9>:1:66' */
    px4demo_attitude_control20190_B.y_n = 0.4;

    /* '<S9>:1:67' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 2) &&
             (px4demo_attitude_control20190_B.q1 == 4)) {
    /* '<S9>:1:69' */
    /*  */
    /* '<S9>:1:70' */
    px4demo_attitude_control20190_B.y_n = -1.0;

    /* '<S9>:1:71' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 2) &&
             (px4demo_attitude_control20190_B.q1 == 1)) {
    /* '<S9>:1:72' */
    /* '<S9>:1:73' */
    px4demo_attitude_control20190_B.y_n = 0.4;

    /* '<S9>:1:74' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 2) &&
             (px4demo_attitude_control20190_B.q1 == 3)) {
    /* '<S9>:1:75' */
    /* '<S9>:1:76' */
    px4demo_attitude_control20190_B.y_n = -0.4;

    /* '<S9>:1:77' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 1) &&
             (px4demo_attitude_control20190_B.q1 == 4)) {
    /* '<S9>:1:79' */
    /*  */
    /* '<S9>:1:80' */
    px4demo_attitude_control20190_B.y_n = 0.4;

    /* '<S9>:1:81' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 1) &&
             (px4demo_attitude_control20190_B.q1 == 2)) {
    /* '<S9>:1:82' */
    /* '<S9>:1:83' */
    px4demo_attitude_control20190_B.y_n = -0.4;

    /* '<S9>:1:84' */
    rtb_y1 = 1;
  } else if ((px4demo_attitude_control20190_B.q == 1) &&
             (px4demo_attitude_control20190_B.q1 == 3)) {
    /* '<S9>:1:85' */
    /* '<S9>:1:86' */
    px4demo_attitude_control20190_B.y_n = -1.0;

    /* '<S9>:1:87' */
    rtb_y1 = 1;
  } else if (px4demo_attitude_control20190_B.q ==
             px4demo_attitude_control20190_B.q1) {
    /* '<S9>:1:88' */
    /* '<S9>:1:89' */
    rtb_y1 = 0;

    /* '<S9>:1:90' */
    px4demo_attitude_control20190_B.y_n = 0.0;
  } else if (px4demo_attitude_control20190_B.b_a == 90.0F) {
    /* '<S9>:1:92' */
    /* '<S9>:1:93' */
    px4demo_attitude_control20190_B.y_n = 0.0;

    /* '<S9>:1:94' */
    rtb_y1 = 1;
  } else if (px4demo_attitude_control20190_B.b_a == 180.0F) {
    /* '<S9>:1:95' */
    /* '<S9>:1:96' */
    px4demo_attitude_control20190_B.y_n = 0.0;

    /* '<S9>:1:97' */
    rtb_y1 = 1;
  } else if (px4demo_attitude_control20190_B.b_a == 270.0F) {
    /* '<S9>:1:98' */
    /* '<S9>:1:99' */
    px4demo_attitude_control20190_B.y_n = 0.0;

    /* '<S9>:1:100' */
    rtb_y1 = 1;
  } else if (px4demo_attitude_control20190_B.b_a == 270.0F) {
    /* '<S9>:1:101' */
    /* '<S9>:1:102' */
    px4demo_attitude_control20190_B.y_n = 0.0;

    /* '<S9>:1:103' */
    rtb_y1 = 1;

    /* elseif(q==q1 & dif_thera <79 & dif_thera>=69) */
    /*     y=0.8 */
    /* elseif(q==q1 & dif_thera <69 & dif_thera>=59) */
    /*     y=0.7 */
    /* elseif(q==q1 & dif_thera <59 & dif_thera>=49) */
    /*     y=0.6 */
    /* elseif(q==q1 & dif_thera <49 & dif_thera>=39) */
    /*     y=0.5 */
    /* elseif(q==q1 & dif_thera <39 & dif_thera>=29) */
    /*     y=0.4 */
    /* elseif(q==q1 & dif_thera <29 & dif_thera>=19) */
    /*     y=0.3 */
    /* elseif(q==q1 & dif_thera <19 & dif_thera>=9) */
    /*    y=0.2 */
    /* elseif(q==q1 & dif_thera <9 & dif_thera >=0) */
    /*    y=0 */
    /*  */
    /* elseif(q==q1 & dif_thera <-89 & dif_thera>=-79) */
    /*     y=-0.9 */
    /* elseif(q==q1 & dif_thera <-79 & dif_thera>=-69) */
    /*     y=-0.8 */
    /* elseif(q==q1 & dif_thera <-69 & dif_thera>=-59) */
    /*     y=-0.7 */
    /* elseif(q==q1 & dif_thera <-59 & dif_thera>=-49) */
    /*     y=-0.6 */
    /* elseif(q==q1 & dif_thera <-49 & dif_thera>=-39) */
    /*     y=-0.5 */
    /* elseif(q==q1 & dif_thera <-39 & dif_thera>=-29) */
    /*     y=-0.4 */
    /* elseif(q==q1 & dif_thera <-29 & dif_thera>=-19) */
    /*     y=-0.3 */
    /* elseif(q==q1 & dif_thera <-19 & dif_thera>=-9) */
    /*     y=-0.2 */
    /* elseif(q==q1 & dif_thera <-9 & dif_thera > 0) */
    /*     y=-0 */
  } else {
    /* '<S9>:1:140' */
    px4demo_attitude_control20190_B.y_n = 0.0;

    /* '<S9>:1:141' */
    rtb_y1 = 1;
  }

  /* dif_thera=thera_new2-yaw; */
  /* if(vector_a_y>=0 && vector_a_x >=0) */
  /*     thera_new1=abs(thera_new1) */
  /* elseif(vector_a_y>=0 && vector_a_x <=0) */
  /*     thera_new1=thera_new1+90 */
  /*     elseif(vector_a_y<=0 && vector_a_x <=0) */
  /*     thera_new1=thera_new1+180 */
  /*     elseif(vector_a_y<=0 && vector_a_x >=0) */
  /*     thera_new1=thera_new1+270 */
  /* end */
  /* dif_thera=(thera_new1-yaw)+360 */
  /* if(dif_thera>=360) */
  /*     dif_thera=dif_thera-360 */
  /* end */
  /* '<S9>:1:166' */
  /* '<S9>:1:168' */
  /* '<S9>:1:169' */
  /* if((latitutdeold-latitutde)==0 && (longitudeold-longitude)==0 ) */
  /* yaw_pwm=single(180) */
  /* elseif(pn(1,3)>0) */
  /*  yaw_pwm=-(single(thera)) */
  /* else */
  /* yaw_pwm=single(thera) */
  /* end */
  if (rtb_Saturation9 < 2.0F) {
    /* '<S9>:1:190' */
    /* '<S9>:1:191' */
    px4demo_attitude_control20190_B.arrival = 1;
  } else {
    /* '<S9>:1:193' */
    px4demo_attitude_control20190_B.arrival = 0;
  }

  /* MATLAB Function: '<S3>/MATLAB Function10' */
  /* && distance_a > 0.002 */
  /* if(x == 3 && distance_a < 0.08)  */
  /*  reset=round(-3) */
  /* else */
  /*  reset=round(0) */
  /* end */
  /* MATLAB Function 'AttitudeControl/MATLAB Function10': '<S11>:1' */
  if ((rtb_dif_thera < 89.0F) && (rtb_dif_thera >= 79.0F)) {
    /* '<S11>:1:3' */
    /* '<S11>:1:4' */
    px4demo_attitude_control20190_B.y_h = 0.9;
  } else if ((rtb_dif_thera < 79.0F) && (rtb_dif_thera >= 69.0F)) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    px4demo_attitude_control20190_B.y_h = 0.8;
  } else if ((rtb_dif_thera < 69.0F) && (rtb_dif_thera >= 59.0F)) {
    /* '<S11>:1:7' */
    /* '<S11>:1:8' */
    px4demo_attitude_control20190_B.y_h = 0.7;
  } else if ((rtb_dif_thera < 59.0F) && (rtb_dif_thera >= 49.0F)) {
    /* '<S11>:1:9' */
    /* '<S11>:1:10' */
    px4demo_attitude_control20190_B.y_h = 0.6;
  } else if ((rtb_dif_thera < 49.0F) && (rtb_dif_thera >= 39.0F)) {
    /* '<S11>:1:11' */
    /* '<S11>:1:12' */
    px4demo_attitude_control20190_B.y_h = 0.5;
  } else if ((rtb_dif_thera < 39.0F) && (rtb_dif_thera >= 29.0F)) {
    /* '<S11>:1:13' */
    /* '<S11>:1:14' */
    px4demo_attitude_control20190_B.y_h = 0.4;
  } else if ((rtb_dif_thera < 29.0F) && (rtb_dif_thera >= 19.0F)) {
    /* '<S11>:1:15' */
    /* '<S11>:1:16' */
    px4demo_attitude_control20190_B.y_h = 0.3;
  } else if ((rtb_dif_thera < 19.0F) && (rtb_dif_thera >= 9.0F)) {
    /* '<S11>:1:17' */
    /* '<S11>:1:18' */
    px4demo_attitude_control20190_B.y_h = 0.2;
  } else if ((rtb_dif_thera < 9.0F) && (rtb_dif_thera >= 0.0F)) {
    /* '<S11>:1:19' */
    /* '<S11>:1:20' */
    px4demo_attitude_control20190_B.y_h = 0.0;
  } else if ((rtb_dif_thera > -89.0F) && (rtb_dif_thera <= -79.0F)) {
    /* '<S11>:1:22' */
    /*  */
    /* '<S11>:1:23' */
    px4demo_attitude_control20190_B.y_h = -0.9;
  } else if ((rtb_dif_thera > -79.0F) && (rtb_dif_thera <= -69.0F)) {
    /* '<S11>:1:24' */
    /* '<S11>:1:25' */
    px4demo_attitude_control20190_B.y_h = -0.8;
  } else if ((rtb_dif_thera > -69.0F) && (rtb_dif_thera <= -59.0F)) {
    /* '<S11>:1:26' */
    /* '<S11>:1:27' */
    px4demo_attitude_control20190_B.y_h = -0.7;
  } else if ((rtb_dif_thera > -59.0F) && (rtb_dif_thera <= -49.0F)) {
    /* '<S11>:1:28' */
    /* '<S11>:1:29' */
    px4demo_attitude_control20190_B.y_h = -0.6;
  } else if ((rtb_dif_thera > -49.0F) && (rtb_dif_thera <= -39.0F)) {
    /* '<S11>:1:30' */
    /* '<S11>:1:31' */
    px4demo_attitude_control20190_B.y_h = -0.5;
  } else if ((rtb_dif_thera > -39.0F) && (rtb_dif_thera <= -29.0F)) {
    /* '<S11>:1:32' */
    /* '<S11>:1:33' */
    px4demo_attitude_control20190_B.y_h = -0.4;
  } else if ((rtb_dif_thera > -29.0F) && (rtb_dif_thera <= -19.0F)) {
    /* '<S11>:1:34' */
    /* '<S11>:1:35' */
    px4demo_attitude_control20190_B.y_h = -0.3;
  } else if ((rtb_dif_thera > -19.0F) && (rtb_dif_thera <= -9.0F)) {
    /* '<S11>:1:36' */
    /* '<S11>:1:37' */
    px4demo_attitude_control20190_B.y_h = -0.2;
  } else if ((rtb_dif_thera > -9.0F) && (rtb_dif_thera < 0.0F)) {
    /* '<S11>:1:38' */
    /* '<S11>:1:39' */
    px4demo_attitude_control20190_B.y_h = -0.0;
  } else {
    /* '<S11>:1:41' */
    px4demo_attitude_control20190_B.y_h = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function10' */

  /* Switch: '<S3>/Switch' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion15'
   *  DataTypeConversion: '<S3>/Data Type Conversion16'
   */
  if (rtb_y1 > 0.0) {
    rtb_Switch = (real32_T)px4demo_attitude_control20190_B.y_n;
  } else {
    rtb_Switch = (real32_T)px4demo_attitude_control20190_B.y_h;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Sum1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   */
  rtb_Sum1 = (1.0F * px4demo_attitude_control20190_B.sf_MATLABFunction3.y -
              px4demo_attitude_control20190_B.sf_MATLABFunction4.y) + 1.0F *
    rtb_Switch;

  /* Sum: '<S22>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S22>/Integrator'
   *  Gain: '<S22>/Proportional Gain'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   *  Sum: '<S3>/Sum1'
   */
  px4demo_attitude_control20190_B.Sum = ((1.0F *
    px4demo_attitude_control20190_B.sf_MATLABFunction3.y -
    px4demo_attitude_control20190_B.sf_MATLABFunction4.y) + 1.0F * rtb_Switch) *
    1.10009301262288 + px4demo_attitude_control2019_DW.Integrator_DSTATE;

  /* Saturate: '<S22>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum > 1.0) {
    px4demo_attitude_control20190_B.Saturate = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate =
      px4demo_attitude_control20190_B.Sum;
  }

  /* End of Saturate: '<S22>/Saturate' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  px4demo_attitude_control20190_B.Sum2 =
    px4demo_attitude_control20190_B.Saturate - rtb_Switch1_idx_2;

  /* Sum: '<S23>/Sum' incorporates:
   *  DiscreteIntegrator: '<S23>/Integrator'
   *  Gain: '<S23>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum_j = 0.0549143230570902 *
    px4demo_attitude_control20190_B.Sum2 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_g;

  /* Saturate: '<S23>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_j > 1.0) {
    px4demo_attitude_control20190_B.Saturate_o = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_j < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate_o = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate_o =
      px4demo_attitude_control20190_B.Sum_j;
  }

  /* End of Saturate: '<S23>/Saturate' */

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation8,
    &px4demo_attitude_control20190_B.sf_MATLABFunction2);

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  px4demo_attitud_MATLABFunction1(rtb_Switch1_idx_1,
    &px4demo_attitude_control20190_B.sf_MATLABFunction1);

  /* Switch: '<Root>/Switch2' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay2'
   *  Delay: '<Root>/Delay3'
   */
  if (px4demo_attitude_control2019_DW.Delay_DSTATE) {
    rtb_Switch2 = px4demo_attitude_control2019_DW.Delay2_DSTATE;
  } else {
    rtb_Switch2 = px4demo_attitude_control2019_DW.Delay3_DSTATE;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* MATLAB Function: '<S3>/MATLAB Function9' incorporates:
   *  Inport: '<Root>/attin1'
   *  Sum: '<Root>/Sum'
   */
  /* MATLAB Function 'AttitudeControl/MATLAB Function9': '<S19>:1' */
  /* '<S19>:1:3' */
  rtb_y_l = rt_roundf_snf(px4demo_attitude_control20190_U.attin1 - rtb_Switch2);

  /* MATLAB Function: '<S3>/MATLAB Function8' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion19'
   */
  /* MATLAB Function 'AttitudeControl/MATLAB Function8': '<S18>:1' */
  /* '<S18>:1:2' */
  /* '<S18>:1:3' */
  if (rtb_y_l <= 70.0 - 2.0) {
    /* '<S18>:1:4' */
    /* '<S18>:1:5' */
    rtb_y = 1;
  } else if (rtb_y_l >= 70.0 + 2.0) {
    /* '<S18>:1:6' */
    /* '<S18>:1:7' */
    rtb_y = -1;
  } else {
    /* '<S18>:1:9' */
    rtb_y = 0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function8' */

  /* Sum: '<S3>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain5'
   */
  px4demo_attitude_control20190_B.Sum_e = ((real_T)(1.0F *
    px4demo_attitude_control20190_B.sf_MATLABFunction2.y) -
    px4demo_attitude_control20190_B.sf_MATLABFunction1.y) + 0.25 * (real_T)rtb_y;

  /* Sum: '<S21>/Sum' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  DiscreteIntegrator: '<S21>/Integrator'
   *  Gain: '<S21>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum_m = 1.8545410952272 *
    px4demo_attitude_control20190_B.Sum_e +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_n;

  /* Saturate: '<S21>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_m > 1.0) {
    px4demo_attitude_control20190_B.Saturate_d = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_m < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate_d = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate_d =
      px4demo_attitude_control20190_B.Sum_m;
  }

  /* End of Saturate: '<S21>/Saturate' */

  /* Sum: '<S3>/Sum3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   */
  px4demo_attitude_control20190_B.Sum3 =
    px4demo_attitude_control20190_B.Saturate_d - rtb_Switch1_idx_3;

  /* Sum: '<S20>/Sum' incorporates:
   *  DiscreteIntegrator: '<S20>/Integrator'
   *  Gain: '<S20>/Proportional Gain'
   */
  px4demo_attitude_control20190_B.Sum_f = 0.92594405565099358 *
    px4demo_attitude_control20190_B.Sum3 +
    px4demo_attitude_control2019_DW.Integrator_DSTATE_k;

  /* Saturate: '<S20>/Saturate' */
  if (px4demo_attitude_control20190_B.Sum_f > 1.0) {
    px4demo_attitude_control20190_B.Saturate_h = 1.0;
  } else if (px4demo_attitude_control20190_B.Sum_f < (-1.0)) {
    px4demo_attitude_control20190_B.Saturate_h = (-1.0);
  } else {
    px4demo_attitude_control20190_B.Saturate_h =
      px4demo_attitude_control20190_B.Sum_f;
  }

  /* End of Saturate: '<S20>/Saturate' */
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
    px4demo_attitude_control20190_B.Saturate_h,
    px4demo_attitude_control20190_B.Gain5, rtb_Saturation10,
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

  /* Outport: '<Root>/ARM_Control' incorporates:
   *  Delay: '<Root>/Delay'
   */
  px4demo_attitude_control20190_Y.ARM_Control =
    px4demo_attitude_control2019_DW.Delay_DSTATE;

  /* Outport: '<Root>/q1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  px4demo_attitude_control20190_Y.q1 = px4demo_attitude_control20190_B.q1;

  /* Outport: '<Root>/q' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  px4demo_attitude_control20190_Y.q = px4demo_attitude_control20190_B.q;

  /* Outport: '<Root>/y_out' */
  px4demo_attitude_control20190_Y.y_out = rtb_Switch;

  /* Outport: '<Root>/lat_out' */
  px4demo_attitude_control20190_Y.lat_out =
    px4demo_attitude_control20190_B.DataTypeConversion17;

  /* Outport: '<Root>/long_out' */
  px4demo_attitude_control20190_Y.long_out =
    px4demo_attitude_control20190_B.DataTypeConversion18;

  /* Outport: '<Root>/distance' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  px4demo_attitude_control20190_Y.distance = rtb_Saturation9;

  /* Outport: '<Root>/rollout' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  px4demo_attitude_control20190_Y.rollout = (real32_T)
    px4demo_attitude_control20190_B.Saturate_o;

  /* Outport: '<Root>/pitchout' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  px4demo_attitude_control20190_Y.pitchout = (real32_T)
    px4demo_attitude_control20190_B.Saturate_h;

  /* Outport: '<Root>/mode' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  px4demo_attitude_control20190_Y.mode =
    px4demo_attitude_control2019_DW.Delay1_DSTATE;
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<S3>/MATLAB Function6' */
    px4demo_attitud_MATLABFunction2(rtb_Saturation7,
      &px4demo_attitude_control20190_B.sf_MATLABFunction6);

    /* Gain: '<S3>/Gain1' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion9'
     */
    px4demo_attitude_control20190_B.Gain1 = 1.0F *
      px4demo_attitude_control20190_B.sf_MATLABFunction6.y;

    /* Update for UnitDelay: '<S3>/Unit Delay2' */
    px4demo_attitude_control2019_DW.UnitDelay2_DSTATE =
      px4demo_attitude_control20190_B.y_f;

    /* Update for UnitDelay: '<S3>/Unit Delay3' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    px4demo_attitude_control2019_DW.UnitDelay3_DSTATE =
      px4demo_attitude_control20190_B.arrival;
  }

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/ch6'
   *  RelationalOperator: '<S8>/Compare'
   */
  px4demo_attitude_control2019_DW.Delay1_DSTATE =
    (px4demo_attitude_control20190_U.ch6 >= ((uint16_T)1300U));

  /* Update for DiscreteIntegrator: '<S22>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  Gain: '<S22>/Integral Gain'
   *  Gain: '<S22>/Kb'
   *  Sum: '<S22>/SumI1'
   *  Sum: '<S22>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE +=
    ((px4demo_attitude_control20190_B.Saturate -
      px4demo_attitude_control20190_B.Sum) * 1.0 + 0.0135349169634299 * rtb_Sum1)
    * 0.004;

  /* Update for DiscreteIntegrator: '<S23>/Integrator' incorporates:
   *  Gain: '<S23>/Integral Gain'
   *  Gain: '<S23>/Kb'
   *  Sum: '<S23>/SumI1'
   *  Sum: '<S23>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_g +=
    ((px4demo_attitude_control20190_B.Saturate_o -
      px4demo_attitude_control20190_B.Sum_j) * 1.0 + 1.1637891162682 *
     px4demo_attitude_control20190_B.Sum2) * 0.004;

  /* Update for Delay: '<Root>/Delay2' */
  px4demo_attitude_control2019_DW.Delay2_DSTATE = rtb_Switch2;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/ch5'
   *  RelationalOperator: '<S7>/Compare'
   */
  px4demo_attitude_control2019_DW.Delay_DSTATE =
    (px4demo_attitude_control20190_U.ch5 >= ((uint16_T)1500U));

  /* Update for Delay: '<Root>/Delay3' incorporates:
   *  Update for Inport: '<Root>/attin1'
   */
  px4demo_attitude_control2019_DW.Delay3_DSTATE =
    px4demo_attitude_control20190_U.attin1;

  /* Update for DiscreteIntegrator: '<S21>/Integrator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  Gain: '<S21>/Integral Gain'
   *  Gain: '<S21>/Kb'
   *  Sum: '<S21>/SumI1'
   *  Sum: '<S21>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_n +=
    ((px4demo_attitude_control20190_B.Saturate_d -
      px4demo_attitude_control20190_B.Sum_m) * 1.0 + 2.0387841436751 *
     px4demo_attitude_control20190_B.Sum_e) * 0.004;

  /* Update for DiscreteIntegrator: '<S20>/Integrator' incorporates:
   *  Gain: '<S20>/Integral Gain'
   *  Gain: '<S20>/Kb'
   *  Sum: '<S20>/SumI1'
   *  Sum: '<S20>/SumI2'
   */
  px4demo_attitude_control2019_DW.Integrator_DSTATE_k +=
    ((px4demo_attitude_control20190_B.Saturate_h -
      px4demo_attitude_control20190_B.Sum_f) * 1.0 + 0.746476159593003 *
     px4demo_attitude_control20190_B.Sum3) * 0.004;
  if (px4demo_attitude_control2019_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S3>/Unit Delay4' incorporates:
     *  Sum: '<S3>/Sum4'
     */
    px4demo_attitude_control2019_DW.UnitDelay4_DSTATE =
      px4demo_attitude_control20190_B.Gain1 - rtb_Switch;
  }

  rate_scheduler();
}

/* Model initialize function */
void px4demo_attitude_control20190311gps_initialize(void)
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

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  px4demo_attitude_control2019_DW.UnitDelay2_DSTATE = 1.0;
}

/* Model terminate function */
void px4demo_attitude_control20190311gps_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
