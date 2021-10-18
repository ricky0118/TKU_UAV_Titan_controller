/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_system20190504_pitch.c
 *
 * Code generated for Simulink model 'px4demo_attitude_system20190504_pitch'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 13 18:39:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_system20190504_pitch.h"
#include "px4demo_attitude_system20190504_pitch_private.h"
#define px4demo_attitude_system20_block (true)

const char *g_pwm_device = PWM_OUTPUT0_DEVICE_PATH;
int g_pwm_fd = -1;
bool g_pwm_enabled = false;
rtTimingBridge px4demo_attitude_sys_TimingBrdg;
const uint8_T px4demo_attitude_system20190504_pitch_U8GND = 0U;/* uint8_T ground */

/* Block signals (auto storage) */
B_px4demo_attitude_system2019_T px4demo_attitude_system201905_B;

/* Block states (auto storage) */
DW_px4demo_attitude_system201_T px4demo_attitude_system20190_DW;

/* Real-time model */
RT_MODEL_px4demo_attitude_sys_T px4demo_attitude_system20190_M_;
RT_MODEL_px4demo_attitude_sys_T *const px4demo_attitude_system20190_M =
  &px4demo_attitude_system20190_M_;
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
  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1]) > 24) {/* Sample time: [0.1s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2]) > 74) {/* Sample time: [0.3s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3]) > 124) {/* Sample time: [0.5s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4]) > 2499) {/* Sample time: [10.0s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Model step function */
void px4demo_attitude_system20190504_pitch_step(void)
{
  static const char_T mlStrVer[8] = { 'M', 'W', 'L', 'O', 'G', 'V', '0', '1' };

  static const char_T b[28] = { 'C', 'L', 'O', 'S', 'I', 'N', 'G', ' ', 'f', 'i',
    'l', 'e', '.', ' ', 'c', 'o', 'u', 'n', 't', ' ', '=', ' ', '%', 'd', ' ',
    '%', 'c', '\x00' };

  static const char_T c[56] = { 'O', 'P', 'E', 'N', 'I', 'N', 'G', ' ', 'f', 'i',
    'l', 'e', ' ', '%', 's', ' ', 'v', 'e', 'c', 't', '_', 's', 'i', 'z', 'e',
    ' ', '%', 'd', ' ', 'e', 'l', 'e', 'm', '_', 's', 'i', 'z', 'e', ' ', '%',
    'd', ' ', 'n', 'u', 'm', 'R', 'e', 'c', 's', ' ', '%', 'd', ' ', '%', 'c',
    '\x00' };

  static const char_T e[15] = { '/', 'f', 's', '/', 'm', 'i', 'c', 'r', 'o', 's',
    'd', '/', 'l', 'o', 'g' };

  /* S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd,
              &updated);
    if (updated) {
      struct vehicle_attitude_s raw;
      orb_copy(ORB_ID(vehicle_attitude),
               px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd,
               &raw);

      /* read out the Roll value */
      px4demo_attitude_system201905_B.phi = raw.roll;// phi

      /* read out the Pitch value */
      px4demo_attitude_system201905_B.theta = raw.pitch;// theta

      /* read out the Yaw value */
      px4demo_attitude_system201905_B.vehicle_attitude_o3 = raw.yaw;// psi
    }
  }

  /* S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd, &updated);
    if (updated) {
      struct rc_input_values pwm_inputs;

      /* copy input_rc raw data into local buffer (uint16)*/
      orb_copy(ORB_ID(input_rc),
               px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd,
               &pwm_inputs);
      px4demo_attitude_system201905_B.input_rc_o1 = pwm_inputs.values[0];
      px4demo_attitude_system201905_B.input_rc_o2 = pwm_inputs.values[1];
      px4demo_attitude_system201905_B.input_rc_o3 = pwm_inputs.values[2];
      px4demo_attitude_system201905_B.input_rc_o4 = pwm_inputs.values[3];
      px4demo_attitude_system201905_B.input_rc_o5 = pwm_inputs.values[4];
      px4demo_attitude_system201905_B.input_rc_o6 = pwm_inputs.values[5];
    }
  }

  /* S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
  {
    int poll_ret;
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd, &updated);
    if (updated) {
      /* obtained GPS data */
      struct vehicle_gps_position_s raw;

      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(vehicle_gps_position),
               px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd, &raw);

      /* read out Lat/Lon Values */
      px4demo_attitude_system201905_B.vehicle_gps_o1 = raw.lat;
      px4demo_attitude_system201905_B.vehicle_gps_o2 = raw.lon;
    }
  }

  /* ModelReference: '<Root>/ControlSubsystem' */
  px4demo_attitude_control2019031(&px4demo_attitude_system201905_B.phi,
    &px4demo_attitude_system201905_B.theta,
    &px4demo_attitude_system201905_B.input_rc_o1,
    &px4demo_attitude_system201905_B.input_rc_o2,
    &px4demo_attitude_system201905_B.input_rc_o3,
    &px4demo_attitude_system201905_B.input_rc_o4,
    &px4demo_attitude_system201905_B.input_rc_o5,
    &px4demo_attitude_system201905_B.input_rc_o6,
    &px4demo_attitude_system201905_B.vehicle_gps_o1,
    &px4demo_attitude_system201905_B.vehicle_gps_o2,
    &px4demo_attitude_system201905_B.ControlSubsystem_o1[0],
    &px4demo_attitude_system201905_B.ControlSubsystem_o2,
    &px4demo_attitude_system201905_B.ControlSubsystem_o10,
    &px4demo_attitude_system201905_B.ControlSubsystem_o11,
    &px4demo_attitude_system201905_B.ControlSubsystem_o12,
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtdw));

  /* S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
  if (px4demo_attitude_system201905_B.ControlSubsystem_o2 == true) {
    if (g_pwm_enabled == false) {
      int rc;

      /* arm system */
      rc = ioctl(g_pwm_fd, PWM_SERVO_ARM, 0);
      if (rc != OK)
        err(1,"PWM_SERVO_ARM");
      else {
        ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
        g_pwm_enabled = true;
        printf("***ARMED*** PWM fd = %d\n", g_pwm_fd);
      }
    }
  } else {
    if (g_pwm_enabled == true) {
      int rc;

      /* disarm system if enabled */
      ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
      rc = ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
      g_pwm_enabled = false;
      if (rc != OK)
        err(1, "PWM_SERVO_DISARM");
      else
        printf("***DISARMED*** PWM fd = %d\n", g_pwm_fd);
    }
  }

  if (g_pwm_enabled) {
    /* output the PWM signals */
    ioctl(g_pwm_fd, PWM_SERVO_SET(0), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[0]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(1), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[1]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(2), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[2]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(3), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[3]);
  }

  if (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3] == 0) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  Switch: '<S2>/Switch1'
     */
    if (px4demo_attitude_system201905_B.ControlSubsystem_o2) {
      px4demo_attitude_system201905_B.Switch = MODE_BLINK_FAST;
      px4demo_attitude_system201905_B.Switch1 = COLOR_RED;
    } else {
      px4demo_attitude_system201905_B.Switch = MODE_BREATHE;
      px4demo_attitude_system201905_B.Switch1 = COLOR_GREEN;
    }

    /* End of Switch: '<S2>/Switch' */

    /* S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
          px4demo_attitude_system201905_B.Switch);
    ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
          px4demo_attitude_system201905_B.Switch1);
  }

  /* S-Function (sfun_px4_sensor_combined): '<Root>/sensor_combined' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd,
              &updated);
    if (updated) {
      /* obtained data sensor combined */
      struct sensor_combined_s raw;

      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(sensor_combined),
               px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd,
               &raw);

      /* read out the baro altimeter */
      px4demo_attitude_system201905_B.sensor_combined = (float)
        raw.baro_alt_meter[0];
    }
  }

  /* Gain: '<Root>/Gain3' */
  px4demo_attitude_system201905_B.Gain3 = 57.2957802F *
    px4demo_attitude_system201905_B.phi;

  /* Gain: '<Root>/Gain2' */
  px4demo_attitude_system201905_B.Gain2 = 57.2957802F *
    px4demo_attitude_system201905_B.theta;

  /* Gain: '<Root>/Gain1' */
  px4demo_attitude_system201905_B.Gain1 = 57.2957802F *
    px4demo_attitude_system201905_B.vehicle_attitude_o3;

  /* MATLAB Function: '<Root>/MATLAB Function7' */
  /* MATLAB Function 'MATLAB Function7': '<S1>:1' */
  if (px4demo_attitude_system201905_B.Gain1 <= 0.0F) {
    /* '<S1>:1:2' */
    /* '<S1>:1:3' */
    px4demo_attitude_system201905_B.Gain1 += 360.0F;
  } else {
    /* '<S1>:1:5' */
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function7' */

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  if (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2] == 0) {
    px4demo_attitude_system201905_B.RateTransition_m[0] = (real32_T)
      px4demo_attitude_system201905_B.vehicle_gps_o1;
    px4demo_attitude_system201905_B.RateTransition_m[1] = (real32_T)
      px4demo_attitude_system201905_B.vehicle_gps_o2;
    px4demo_attitude_system201905_B.RateTransition_m[2] =
      px4demo_attitude_system201905_B.sensor_combined;
    px4demo_attitude_system201905_B.RateTransition_m[3] =
      px4demo_attitude_system2_ConstB.DataTypeConversion4;
    px4demo_attitude_system201905_B.RateTransition_m[4] =
      px4demo_attitude_system2_ConstB.DataTypeConversion5;
    px4demo_attitude_system201905_B.RateTransition_m[5] =
      px4demo_attitude_system201905_B.Gain3;
    px4demo_attitude_system201905_B.RateTransition_m[6] =
      px4demo_attitude_system201905_B.Gain2;
    px4demo_attitude_system201905_B.RateTransition_m[7] =
      px4demo_attitude_system201905_B.Gain1;

    /* Start for MATLABSystem: '<Root>/Serial' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  MATLABSystem: '<Root>/Serial'
     */
    MW_writeSerial(px4demo_attitude_system20190_DW.obj.fh_index,
                   px4demo_attitude_system201905_B.RateTransition_m, 32U);
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/ARM_Tune'
   *  Constant: '<S3>/ARM_Tune1'
   */
  if (px4demo_attitude_system201905_B.ControlSubsystem_o2) {
    px4demo_attitude_system201905_B.Switch1_i = ARMING_WARNING_TUNE;
  } else {
    px4demo_attitude_system201905_B.Switch1_i = NOTIFY_POSITIVE_TUNE;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Logic: '<S3>/Logical Operator'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  px4demo_attitude_system201905_B.DataTypeConversion = (uint8_T)((int8_T)
    px4demo_attitude_system20190_DW.UnitDelay_DSTATE ^ (int8_T)
    px4demo_attitude_system201905_B.ControlSubsystem_o2);

  /* S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd == -1) {
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    if ((px4demo_attitude_system201905_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system201905_B.DataTypeConversion !=
         px4demo_attitude_system20190_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system201905_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system201905_B.Switch1_i);
      } else if (px4demo_attitude_system201905_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20190504_pitch_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20190_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system201905_B.DataTypeConversion;
  } else {
    if ((px4demo_attitude_system201905_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system201905_B.DataTypeConversion !=
         px4demo_attitude_system20190_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system201905_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system201905_B.Switch1_i);
      } else if (px4demo_attitude_system201905_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20190504_pitch_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20190_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system201905_B.DataTypeConversion;
  }

  if (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4] == 0) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    px4demo_attitude_system201905_B.PulseGenerator =
      ((px4demo_attitude_system20190_DW.clockTickCounter < 5) &&
       (px4demo_attitude_system20190_DW.clockTickCounter >= 0));
    if (px4demo_attitude_system20190_DW.clockTickCounter >= 9) {
      px4demo_attitude_system20190_DW.clockTickCounter = 0;
    } else {
      px4demo_attitude_system20190_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* DataTypeConversion: '<Root>/Data Type Conversion15' */
    px4demo_attitude_system201905_B.DataTypeConversion15 =
      (px4demo_attitude_system201905_B.PulseGenerator != 0);
  }

  /* S-Function (sfun_px4_uorb_read_topic): '<Root>/uORB Read // Function-Call Trigger' */
  {
    //interval val: 1
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.uORBReadFunctionCallTrigger_uOR.fd,
              &updated);
    if (updated) {
      /* obtained uorb data */
      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(airspeed),
               px4demo_attitude_system20190_DW.uORBReadFunctionCallTrigger_uOR.fd,
               &px4demo_attitude_system201905_B.uORBReadFunctionCallTrigger);
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   *  MATLAB Function: '<S4>/binary_logger1'
   */
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[0] =
    px4demo_attitude_system201905_B.Gain3;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[1] =
    px4demo_attitude_system201905_B.Gain2;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[2] =
    px4demo_attitude_system201905_B.Gain1;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[3] =
    px4demo_attitude_system201905_B.uORBReadFunctionCallTrigger.true_airspeed_m_s;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[4] =
    px4demo_attitude_system201905_B.uORBReadFunctionCallTrigger.indicated_airspeed_m_s;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct[5] =
    px4demo_attitude_system201905_B.ControlSubsystem_o12;

  /* MATLAB Function: '<S4>/binary_logger1' */
  /* MATLAB Function 'binary_logger/binary_logger1': '<S5>:1' */
  /* '<S5>:1:39' */
  /* '<S5>:1:87' */
  /* '<S5>:1:47' */
  /* '<S5>:1:40' */
  /* '<S5>:1:39' */
  /* '<S5>:1:38' */
  /*  Binary Logger */
  /*  Note: All data needs to be of the same type (e.g. double) */
  /*  Header information format: */
  /*            String "MWLOGV##" */
  /*            Time/Date 4 bytes (time()) */
  /*            Number of Signals per record Logged 1 byte (256 max) */
  /*            Data Type of Signals Logged  1 byte (1-10) */
  /*            Number of bytes per record 2 bytes (65535 max) */
  /*  This does NOT include the number of data sets logged.   */
  /*  i.e. The Reader is responsible for reading until EOF. */
  /*  MathWorks Pilot Engineering 2015 */
  /*  Steve Kuznicki */
  if (px4demo_attitude_system201905_B.DataTypeConversion15) {
    /* '<S5>:1:32' */
    if (!px4demo_attitude_system20190_DW.isopen) {
      /* '<S5>:1:33' */
      /* '<S5>:1:35' */
      px4demo_attitude_system20190_DW.elem_size = 4U;

      /* '<S5>:1:36' */
      px4demo_attitude_system201905_B.elem_type = 2U;

      /* '<S5>:1:37' */
      px4demo_attitude_system20190_DW.vect_size = 6U;
      for (px4demo_attitude_system201905_B.PulseGenerator = 0;
           px4demo_attitude_system201905_B.PulseGenerator < 56;
           px4demo_attitude_system201905_B.PulseGenerator++) {
        px4demo_attitude_system201905_B.c[px4demo_attitude_system201905_B.PulseGenerator]
          = c[px4demo_attitude_system201905_B.PulseGenerator];
      }

      for (px4demo_attitude_system201905_B.PulseGenerator = 0;
           px4demo_attitude_system201905_B.PulseGenerator < 15;
           px4demo_attitude_system201905_B.PulseGenerator++) {
        px4demo_attitude_system201905_B.e[px4demo_attitude_system201905_B.PulseGenerator]
          = e[px4demo_attitude_system201905_B.PulseGenerator];
      }

      px4demo_attitude_system201905_B.e[15] = '_';
      px4demo_attitude_system201905_B.e[16] = (char_T)
        px4demo_attitude_system20190_DW.lognumstr;
      px4demo_attitude_system201905_B.e[17] = '.';
      px4demo_attitude_system201905_B.e[18] = 'b';
      px4demo_attitude_system201905_B.e[19] = 'i';
      px4demo_attitude_system201905_B.e[20] = 'n';
      px4demo_attitude_system201905_B.e[21] = '\x00';
      printf(px4demo_attitude_system201905_B.c,
             px4demo_attitude_system201905_B.e, (uint32_T)
             px4demo_attitude_system20190_DW.vect_size, (uint32_T)
             px4demo_attitude_system20190_DW.elem_size, 1000U, 10U);

      /* '<S5>:1:40' */
      for (px4demo_attitude_system201905_B.PulseGenerator = 0;
           px4demo_attitude_system201905_B.PulseGenerator < 15;
           px4demo_attitude_system201905_B.PulseGenerator++) {
        px4demo_attitude_system201905_B.e[px4demo_attitude_system201905_B.PulseGenerator]
          = e[px4demo_attitude_system201905_B.PulseGenerator];
      }

      px4demo_attitude_system201905_B.e[15] = '_';
      px4demo_attitude_system201905_B.e[16] = (char_T)
        px4demo_attitude_system20190_DW.lognumstr;
      px4demo_attitude_system201905_B.e[17] = '.';
      px4demo_attitude_system201905_B.e[18] = 'b';
      px4demo_attitude_system201905_B.e[19] = 'i';
      px4demo_attitude_system201905_B.e[20] = 'n';
      px4demo_attitude_system201905_B.e[21] = '\x00';
      px4demo_attitude_system201905_B.d[0] = 'w';
      px4demo_attitude_system201905_B.d[1] = 'b';
      px4demo_attitude_system201905_B.d[2] = '\x00';
      px4demo_attitude_system20190_DW.fp = fopen
        (px4demo_attitude_system201905_B.e, px4demo_attitude_system201905_B.d);

      /* '<S5>:1:41' */
      px4demo_attitude_system20190_DW.lognumstr++;

      /* '<S5>:1:42' */
      px4demo_attitude_system20190_DW.isflushed = false;

      /* '<S5>:1:43' */
      px4demo_attitude_system20190_DW.count = 0U;

      /* '<S5>:1:44' */
      px4demo_attitude_system20190_DW.isopen = true;

      /*  Write header information here */
      /*  header token + version */
      /* '<S5>:1:47' */
      fwrite(mlStrVer, 1U, 8.0, px4demo_attitude_system20190_DW.fp);

      /*  date/time */
      /* '<S5>:1:52' */
      px4demo_attitude_system201905_B.tm = time
        (&px4demo_attitude_system201905_B.tmptr);
      fwrite(&px4demo_attitude_system201905_B.tm, 4U, 1U,
             px4demo_attitude_system20190_DW.fp);

      /*  number of elements in each record */
      fwrite(&px4demo_attitude_system20190_DW.vect_size, 1U, 1U,
             px4demo_attitude_system20190_DW.fp);

      /*  data type of the elements */
      fwrite(&px4demo_attitude_system201905_B.elem_type, 1U, 1U,
             px4demo_attitude_system20190_DW.fp);

      /*  size of each record in bytes */
      /* '<S5>:1:59' */
      px4demo_attitude_system201905_B.tmptr = (uint32_T)
        px4demo_attitude_system20190_DW.elem_size *
        px4demo_attitude_system20190_DW.vect_size;
      if (px4demo_attitude_system201905_B.tmptr > 65535U) {
        px4demo_attitude_system201905_B.tmptr = 65535U;
      }

      px4demo_attitude_system201905_B.recSize = (uint16_T)
        px4demo_attitude_system201905_B.tmptr;
      fwrite(&px4demo_attitude_system201905_B.recSize, 2U, 1U,
             px4demo_attitude_system20190_DW.fp);
    }

    /*  cache data in memory or use fwrite */
    fwrite(px4demo_attitude_system201905_B.TmpSignalConversionAtSFunct,
           px4demo_attitude_system20190_DW.elem_size,
           px4demo_attitude_system20190_DW.vect_size,
           px4demo_attitude_system20190_DW.fp);

    /* '<S5>:1:72' */
    px4demo_attitude_system201905_B.tmptr =
      px4demo_attitude_system20190_DW.count + 1U;
    if (px4demo_attitude_system201905_B.tmptr <
        px4demo_attitude_system20190_DW.count) {
      px4demo_attitude_system201905_B.tmptr = MAX_uint32_T;
    }

    px4demo_attitude_system20190_DW.count =
      px4demo_attitude_system201905_B.tmptr;

    /*  check for data count limit */
    if (px4demo_attitude_system20190_DW.count >= 1000U) {
      /* '<S5>:1:74' */
      fflush(px4demo_attitude_system20190_DW.fp);

      /* '<S5>:1:81' */
      px4demo_attitude_system20190_DW.isflushed = false;

      /* '<S5>:1:82' */
      px4demo_attitude_system20190_DW.count = 0U;
    }
  } else {
    if (px4demo_attitude_system20190_DW.isopen) {
      /* '<S5>:1:85' */
      if (!px4demo_attitude_system20190_DW.isflushed) {
        /* '<S5>:1:86' */
        for (px4demo_attitude_system201905_B.PulseGenerator = 0;
             px4demo_attitude_system201905_B.PulseGenerator < 28;
             px4demo_attitude_system201905_B.PulseGenerator++) {
          px4demo_attitude_system201905_B.b[px4demo_attitude_system201905_B.PulseGenerator]
            = b[px4demo_attitude_system201905_B.PulseGenerator];
        }

        printf(px4demo_attitude_system201905_B.b,
               px4demo_attitude_system20190_DW.count, 10U);
        fflush(px4demo_attitude_system20190_DW.fp);

        /* '<S5>:1:95' */
        px4demo_attitude_system20190_DW.isflushed = true;
      }

      fclose(px4demo_attitude_system20190_DW.fp);
    }

    /* '<S5>:1:99' */
    px4demo_attitude_system20190_DW.isopen = false;

    /* '<S5>:1:100' */
    px4demo_attitude_system20190_DW.count = 0U;
  }

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  px4demo_attitude_system20190_DW.UnitDelay_DSTATE =
    px4demo_attitude_system201905_B.ControlSubsystem_o2;
  rate_scheduler();
}

/* Model initialize function */
void px4demo_attitude_system20190504_pitch_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)px4demo_attitude_system20190_M, 0,
                sizeof(RT_MODEL_px4demo_attitude_sys_T));

  /* block I/O */
  (void) memset(((void *) &px4demo_attitude_system201905_B), 0,
                sizeof(B_px4demo_attitude_system2019_T));

  {
    px4demo_attitude_system201905_B.Switch = MODE_OFF;
    px4demo_attitude_system201905_B.Switch1 = COLOR_OFF;
    px4demo_attitude_system201905_B.Switch1_i = STOP_TUNE;
    px4demo_attitude_system201905_B.ControlSubsystem_o3 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o4 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o5 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o6 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o7 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o8 = 520.0;
    px4demo_attitude_system201905_B.ControlSubsystem_o9 = 520.0;
  }

  /* states (dwork) */
  (void) memset((void *)&px4demo_attitude_system20190_DW, 0,
                sizeof(DW_px4demo_attitude_system201_T));

  {
    static uint32_T *taskCounterPtrs;
    px4demo_attitude_sys_TimingBrdg.nTasks = 5;
    px4demo_attitude_sys_TimingBrdg.clockTick = (NULL);
    px4demo_attitude_sys_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(px4demo_attitude_system20190_M->Timing.TaskCounters.TID
                        [0]);
    px4demo_attitude_sys_TimingBrdg.taskCounter = taskCounterPtrs;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/ControlSubsystem' */
  px4demo_attitude_con_initialize(rtmGetErrorStatusPointer
    (px4demo_attitude_system20190_M), &px4demo_attitude_sys_TimingBrdg, 0, 1,
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtm),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtdw));

  {
    uint8_T devName[11];
    int32_T fh_index_tmp;
    static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U,
      121U, 83U, 49U, 0U };

    /* Start for S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude' */
    {
      /* S-Function Block: <Root>/vehicle_attitude */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(vehicle_attitude));
      px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd = fd;
      px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.events =
        POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to vehicle_attitude topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
    {
      /* S-Function Block: <Root>/input_rc */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(input_rc));
      px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd = fd;
      px4demo_attitude_system20190_DW.input_rc_input_rc_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to input_rc topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
    {
      /* S-Function Block: <Root>/vehicle_gps */
      /* subscribe to gps topic */
      int fd = orb_subscribe(ORB_ID(vehicle_gps_position));
      px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd = fd;
      px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to gps topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
    {
      int rc;
      int pwm_rate = 400;              /* default PWM Rate is 400Hz */
      int chMask = 0x00;               /* change channel mask based on which are used */

      /* channel group 0 */
      chMask |= 0x03;

      /* channel group 2 */
      chMask |= 0x0C;

      /* set PWM update rate to 50Hz */
      pwm_rate = 50;

      /* enable pwm outputs, set to disarm  */
      g_pwm_fd = open(g_pwm_device, 0);
      printf("OPEN PWM fd = %d\n", g_pwm_fd);
      rc = ioctl(g_pwm_fd, PWM_SERVO_SET_UPDATE_RATE, pwm_rate);
      if (rc != OK)
        err(1, "PWM_SERVO_SET_UPDATE_RATE");
      if (chMask > 0) {
        rc = ioctl(g_pwm_fd, PWM_SERVO_SET_SELECT_UPDATE_RATE, chMask);
        if (rc != OK) {
          err(1, "PWM_SERVO_SET_SELECT_UPDATE_RATE");
        }

        printf("Set SERVO Rate (%dHz) Channel Mask:0x%08X\n", pwm_rate, chMask);
      }

      /* tell safety that its ok to disable it with the switch */
      rc = ioctl(g_pwm_fd, PWM_SERVO_SET_ARM_OK, 0);
      if (rc != OK)
        err(1, "PWM_SERVO_SET_ARM_OK");
      rc = ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
      if (rc != OK)
        err(1, "PWM_SERVO_DISARM");
      g_pwm_enabled = false;
    }

    /* Start for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    {
      // enable RGBLED, set intitial mode and color
      // more devices will be 1, 2, etc
      // #define RGBLED0_DEVICE_PATH "/dev/rgbled0"
      //px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd = open("/dev/rgbled0", 0);
      px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd = open
        (RGBLED0_DEVICE_PATH, 0);
      ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
            RGBLED_MODE_OFF);
      ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
            RGBLED_COLOR_OFF);
    }

    /* Start for S-Function (sfun_px4_sensor_combined): '<Root>/sensor_combined' */
    {
      /* S-Function Block: <Root>/sensor_combined */
      /* subscribe to sensor_combined topic */
      int fd = orb_subscribe(ORB_ID(sensor_combined));
      px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd = fd;
      px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to sensor_combined topic (fd = %d)*\n", fd);
    }

    /* Start for MATLABSystem: '<Root>/Serial' */
    px4demo_attitude_system20190_DW.obj.isInitialized = 0;
    px4demo_attitude_system20190_DW.obj.isInitialized = 1;
    for (fh_index_tmp = 0; fh_index_tmp < 11; fh_index_tmp++) {
      devName[fh_index_tmp] = tmp[fh_index_tmp];
    }

    MW_openSerialPort(devName, 57600U, px4demo_attitude_system20_block,
                      &fh_index_tmp);
    px4demo_attitude_system20190_DW.obj.fh_index = fh_index_tmp;

    /* End of Start for MATLABSystem: '<Root>/Serial' */
    /* Start for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */

    // enable tune driver
    // #define TONEALARM_DEVICE_PATH "/dev/tone_alarm"
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STARTUP_TUNE);
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// close here since this may be used in another thread
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = -1;

    /* Start for S-Function (sfun_px4_uorb_read_topic): '<Root>/uORB Read // Function-Call Trigger' */
    {
      /* S-Function Block: <Root>/uORB Read // Function-Call Trigger */
      /* subscribe to airspeed topic */
      int fd = orb_subscribe(ORB_ID(airspeed));
      px4demo_attitude_system20190_DW.uORBReadFunctionCallTrigger_uOR.fd = fd;
      px4demo_attitude_system20190_DW.uORBReadFunctionCallTrigger_uOR.events =
        POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to topic: airspeed (fd = %d)*\n", fd);
    }

    /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    px4demo_attitude_system20190_DW.clockTickCounter = 0;

    /* SystemInitialize for MATLAB Function: '<S4>/binary_logger1' */
    px4demo_attitude_system20190_DW.count = 0U;
    px4demo_attitude_system20190_DW.lognumstr = 65.0;
    px4demo_attitude_system20190_DW.isopen = false;
    px4demo_attitude_system20190_DW.fp = NULL;
    px4demo_attitude_system20190_DW.isflushed = false;
    px4demo_attitude_system20190_DW.elem_size = 1U;
    px4demo_attitude_system20190_DW.vect_size = 6U;
  }
}

/* Model terminate function */
void px4demo_attitude_system20190504_pitch_terminate(void)
{
  uint8_T devName[11];
  static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U, 121U,
    83U, 49U, 0U };

  int32_T i;

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_attitude */
  close(px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd);

  /* Close uORB service used in the S-Function Block: <Root>/input_rc */
  close(px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd);

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_gps */
  close(px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd);

  /* Terminate for S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
  /* disable pwm outputs */
  ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
  ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
  g_pwm_enabled = false;

  /* Close handle used in the S-Function Block: <Root>/PWM_output */
  close(g_pwm_fd);

  /* Terminate for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
  ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
        RGBLED_COLOR_OFF);
  ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
        RGBLED_MODE_OFF);
  usleep(100);

  /* Close uORB service used in the S-Function Block: <Root>/RGB_LED */
  close(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd);

  /* Close uORB service used in the S-Function Block: <Root>/sensor_combined */
  close(px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd);

  /* Start for MATLABSystem: '<Root>/Serial' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial'
   */
  if (px4demo_attitude_system20190_DW.obj.isInitialized == 1) {
    px4demo_attitude_system20190_DW.obj.isInitialized = 2;
    for (i = 0; i < 11; i++) {
      devName[i] = tmp[i];
    }

    MW_closeSerialPort(devName, px4demo_attitude_system20190_DW.obj.fh_index);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial' */
  /* Terminate for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd != -1) {
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// this may be open in a different thread. close first.
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);// re-open
    ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STOP_TUNE);

    /* Close service used in the S-Function Block: <Root>/Speaker_Tune */
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// finally close device here
  }

  /* Close uORB service used in the S-Function Block: <Root>/uORB Read // Function-Call Trigger */
  close(px4demo_attitude_system20190_DW.uORBReadFunctionCallTrigger_uOR.fd);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
