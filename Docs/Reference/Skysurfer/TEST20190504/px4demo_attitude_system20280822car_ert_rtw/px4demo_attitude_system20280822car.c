/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_system20280822car.c
 *
 * Code generated for Simulink model 'px4demo_attitude_system20280822car'.
 *
 * Model version                  : 1.157
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jul 30 11:31:40 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_system20280822car.h"
#include "px4demo_attitude_system20280822car_private.h"
#define px4demo_attitude_system20_block (true)

const char *g_pwm_device = PWM_OUTPUT0_DEVICE_PATH;
int g_pwm_fd = -1;
bool g_pwm_enabled = false;
rtTimingBridge px4demo_attitude_sys_TimingBrdg;
const real_T px4demo_attitude_system20280822car_RGND = 0.0;/* real_T ground */
const real32_T px4demo_attitude_system20280822car_R32GND = 0.0F;/* real32_T ground */
const uint8_T px4demo_attitude_system20280822car_U8GND = 0U;/* uint8_T ground */

/* Block signals (auto storage) */
B_px4demo_attitude_system2028_T px4demo_attitude_system202808_B;

/* Block states (auto storage) */
DW_px4demo_attitude_system202_T px4demo_attitude_system20280_DW;

/* Real-time model */
RT_MODEL_px4demo_attitude_sys_T px4demo_attitude_system20280_M_;
RT_MODEL_px4demo_attitude_sys_T *const px4demo_attitude_system20280_M =
  &px4demo_attitude_system20280_M_;
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
  (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_attitude_system20280_M->Timing.TaskCounters.TID[1]) > 24) {/* Sample time: [0.1s, 0.0s] */
    px4demo_attitude_system20280_M->Timing.TaskCounters.TID[1] = 0;
  }

  (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[2])++;
  if ((px4demo_attitude_system20280_M->Timing.TaskCounters.TID[2]) > 74) {/* Sample time: [0.3s, 0.0s] */
    px4demo_attitude_system20280_M->Timing.TaskCounters.TID[2] = 0;
  }

  (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[3])++;
  if ((px4demo_attitude_system20280_M->Timing.TaskCounters.TID[3]) > 124) {/* Sample time: [0.5s, 0.0s] */
    px4demo_attitude_system20280_M->Timing.TaskCounters.TID[3] = 0;
  }

  (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[4])++;
  if ((px4demo_attitude_system20280_M->Timing.TaskCounters.TID[4]) > 4999) {/* Sample time: [20.0s, 0.0s] */
    px4demo_attitude_system20280_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Model step function */
void px4demo_attitude_system20280822car_step(void)
{
  /* S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20280_DW.input_rc_input_rc_fd.fd, &updated);
    if (updated) {
      struct rc_input_values pwm_inputs;

      /* copy input_rc raw data into local buffer (uint16)*/
      orb_copy(ORB_ID(input_rc),
               px4demo_attitude_system20280_DW.input_rc_input_rc_fd.fd,
               &pwm_inputs);
      px4demo_attitude_system202808_B.input_rc_o1 = pwm_inputs.values[0];
      px4demo_attitude_system202808_B.input_rc_o2 = pwm_inputs.values[1];
      px4demo_attitude_system202808_B.input_rc_o3 = pwm_inputs.values[2];
      px4demo_attitude_system202808_B.input_rc_o4 = pwm_inputs.values[3];
      px4demo_attitude_system202808_B.input_rc_o5 = pwm_inputs.values[4];
      px4demo_attitude_system202808_B.input_rc_o6 = pwm_inputs.values[5];
    }
  }

  /* S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
  {
    int poll_ret;
    bool updated;
    orb_check(px4demo_attitude_system20280_DW.vehicle_gps_gps_fd.fd, &updated);
    if (updated) {
      /* obtained GPS data */
      struct vehicle_gps_position_s raw;

      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(vehicle_gps_position),
               px4demo_attitude_system20280_DW.vehicle_gps_gps_fd.fd, &raw);

      /* read out Lat/Lon Values */
      px4demo_attitude_system202808_B.vehicle_gps_o1 = raw.lat;
      px4demo_attitude_system202808_B.vehicle_gps_o2 = raw.lon;

      /* Altitude in 1E-3 meters (millimeters) above MSL  */
      px4demo_attitude_system202808_B.vehicle_gps_o3 = raw.alt;

      /* 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.   */
      px4demo_attitude_system202808_B.vehicle_gps_o4 = raw.fix_type;

      /* Number of satellites used  */
      px4demo_attitude_system202808_B.vehicle_gps_o5 = raw.satellites_used;
    }
  }

  /* ModelReference: '<Root>/ControlSubsystem' */
  px4demo_attitude_control2018082((real32_T*)
    &px4demo_attitude_system20280822car_R32GND, (real32_T*)
    &px4demo_attitude_system20280822car_R32GND,
    &px4demo_attitude_system202808_B.input_rc_o1,
    &px4demo_attitude_system202808_B.input_rc_o2,
    &px4demo_attitude_system202808_B.input_rc_o3,
    &px4demo_attitude_system202808_B.input_rc_o4,
    &px4demo_attitude_system202808_B.input_rc_o5,
    &px4demo_attitude_system202808_B.input_rc_o6,
    &px4demo_attitude_system202808_B.vehicle_gps_o1,
    &px4demo_attitude_system202808_B.vehicle_gps_o2, (real32_T*)
    &px4demo_attitude_system20280822car_R32GND, (real32_T*)
    &px4demo_attitude_system20280822car_R32GND,
    &px4demo_attitude_system202808_B.ControlSubsystem_o1[0],
    &px4demo_attitude_system202808_B.ControlSubsystem_o2,
    &px4demo_attitude_system202808_B.ControlSubsystem_o3,
    &px4demo_attitude_system202808_B.ControlSubsystem_o4,
    &px4demo_attitude_system202808_B.ControlSubsystem_o5,
    &px4demo_attitude_system202808_B.ControlSubsystem_o6,
    &px4demo_attitude_system202808_B.ControlSubsystem_o7,
    &px4demo_attitude_system202808_B.ControlSubsystem_o8,
    &px4demo_attitude_system202808_B.ControlSubsystem_o9,
    &px4demo_attitude_system202808_B.ControlSubsystem_o10,
    &px4demo_attitude_system202808_B.ControlSubsystem_o11,
    &px4demo_attitude_system202808_B.ControlSubsystem_o12,
    &(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtdw));

  /* S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
  if (px4demo_attitude_system202808_B.ControlSubsystem_o2 == true) {
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
          px4demo_attitude_system202808_B.ControlSubsystem_o1[0]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(1), (unsigned int)
          px4demo_attitude_system202808_B.ControlSubsystem_o1[1]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(2), (unsigned int)
          px4demo_attitude_system202808_B.ControlSubsystem_o1[2]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(3), (unsigned int)
          px4demo_attitude_system202808_B.ControlSubsystem_o1[3]);
  }

  if (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[3] == 0) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  Switch: '<S2>/Switch1'
     */
    if (px4demo_attitude_system202808_B.ControlSubsystem_o2) {
      px4demo_attitude_system202808_B.Switch = MODE_BLINK_FAST;
      px4demo_attitude_system202808_B.Switch1 = COLOR_RED;
    } else {
      px4demo_attitude_system202808_B.Switch = MODE_BREATHE;
      px4demo_attitude_system202808_B.Switch1 = COLOR_GREEN;
    }

    /* End of Switch: '<S2>/Switch' */

    /* S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
          px4demo_attitude_system202808_B.Switch);
    ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
          px4demo_attitude_system202808_B.Switch1);
  }

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/ARM_Tune'
   *  Constant: '<S3>/ARM_Tune1'
   */
  if (px4demo_attitude_system202808_B.ControlSubsystem_o2) {
    px4demo_attitude_system202808_B.Switch1_i = ARMING_WARNING_TUNE;
  } else {
    px4demo_attitude_system202808_B.Switch1_i = NOTIFY_POSITIVE_TUNE;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Logic: '<S3>/Logical Operator'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  px4demo_attitude_system202808_B.DataTypeConversion = (uint8_T)((int8_T)
    px4demo_attitude_system20280_DW.UnitDelay_DSTATE ^ (int8_T)
    px4demo_attitude_system202808_B.ControlSubsystem_o2);

  /* S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd == -1) {
    px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    if ((px4demo_attitude_system202808_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system202808_B.DataTypeConversion !=
         px4demo_attitude_system20280_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system202808_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system202808_B.Switch1_i);
      } else if (px4demo_attitude_system202808_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20280822car_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20280_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system202808_B.DataTypeConversion;
  } else {
    if ((px4demo_attitude_system202808_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system202808_B.DataTypeConversion !=
         px4demo_attitude_system20280_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system202808_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system202808_B.Switch1_i);
      } else if (px4demo_attitude_system202808_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20280822car_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20280_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system202808_B.DataTypeConversion;
  }

  /* MATLAB Function 'MATLAB Function7': '<S1>:1' */

  /* S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude1' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20280_DW.vehicle_attitude1_vehicle_attit.fd,
              &updated);
    if (updated) {
      struct vehicle_attitude_s raw;
      orb_copy(ORB_ID(vehicle_attitude),
               px4demo_attitude_system20280_DW.vehicle_attitude1_vehicle_attit.fd,
               &raw);

      /* read out the Roll value */
      px4demo_attitude_system202808_B.vehicle_attitude1_o1 = raw.roll;// phi

      /* read out the Pitch value */
      px4demo_attitude_system202808_B.vehicle_attitude1_o2 = raw.pitch;// theta

      /* read out the Yaw value */
      px4demo_attitude_system202808_B.vehicle_attitude1_o3 = raw.yaw;// psi
    }
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  if (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[2] == 0) {
    px4demo_attitude_system202808_B.RateTransition1_m[0] =
      px4demo_attitude_system202808_B.vehicle_attitude1_o1;
    px4demo_attitude_system202808_B.RateTransition1_m[1] =
      px4demo_attitude_system202808_B.vehicle_attitude1_o2;
    px4demo_attitude_system202808_B.RateTransition1_m[2] =
      px4demo_attitude_system202808_B.vehicle_attitude1_o3;

    /* Start for MATLABSystem: '<Root>/Serial1' incorporates:
     *  MATLABSystem: '<Root>/Serial1'
     */
    MW_writeSerial(px4demo_attitude_system20280_DW.obj.fh_index,
                   px4demo_attitude_system202808_B.RateTransition1_m, 12U);
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* RateTransition: '<Root>/Rate Transition' */
  if (px4demo_attitude_system20280_M->Timing.TaskCounters.TID[3] == 0) {
    /* Start for MATLABSystem: '<Root>/Serial' incorporates:
     *  MATLABSystem: '<Root>/Serial'
     */
    MW_writeSerial(px4demo_attitude_system20280_DW.obj_a.fh_index, (real_T*)
                   &px4demo_attitude_system20280822car_RGND, 8U);
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  px4demo_attitude_system20280_DW.UnitDelay_DSTATE =
    px4demo_attitude_system202808_B.ControlSubsystem_o2;
  rate_scheduler();
}

/* Model initialize function */
void px4demo_attitude_system20280822car_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)px4demo_attitude_system20280_M, 0,
                sizeof(RT_MODEL_px4demo_attitude_sys_T));

  /* block I/O */
  (void) memset(((void *) &px4demo_attitude_system202808_B), 0,
                sizeof(B_px4demo_attitude_system2028_T));

  {
    px4demo_attitude_system202808_B.Switch = MODE_OFF;
    px4demo_attitude_system202808_B.Switch1 = COLOR_OFF;
    px4demo_attitude_system202808_B.Switch1_i = STOP_TUNE;
  }

  /* states (dwork) */
  (void) memset((void *)&px4demo_attitude_system20280_DW, 0,
                sizeof(DW_px4demo_attitude_system202_T));

  {
    static uint32_T *taskCounterPtrs;
    px4demo_attitude_sys_TimingBrdg.nTasks = 5;
    px4demo_attitude_sys_TimingBrdg.clockTick = (NULL);
    px4demo_attitude_sys_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(px4demo_attitude_system20280_M->Timing.TaskCounters.TID
                        [0]);
    px4demo_attitude_sys_TimingBrdg.taskCounter = taskCounterPtrs;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/ControlSubsystem' */
  px4demo_attitude_con_initialize(rtmGetErrorStatusPointer
    (px4demo_attitude_system20280_M), &px4demo_attitude_sys_TimingBrdg, 0, 1, 4,
    &(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtm),
    &(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtdw));

  {
    uint8_T devName[11];
    int32_T fh_index_tmp;
    static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U,
      121U, 83U, 49U, 0U };

    /* Start for S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
    {
      /* S-Function Block: <Root>/input_rc */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(input_rc));
      px4demo_attitude_system20280_DW.input_rc_input_rc_fd.fd = fd;
      px4demo_attitude_system20280_DW.input_rc_input_rc_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to input_rc topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
    {
      /* S-Function Block: <Root>/vehicle_gps */
      /* subscribe to gps topic */
      int fd = orb_subscribe(ORB_ID(vehicle_gps_position));
      px4demo_attitude_system20280_DW.vehicle_gps_gps_fd.fd = fd;
      px4demo_attitude_system20280_DW.vehicle_gps_gps_fd.events = POLLIN;
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
      //px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd = open("/dev/rgbled0", 0);
      px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd = open
        (RGBLED0_DEVICE_PATH, 0);
      ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
            RGBLED_MODE_OFF);
      ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
            RGBLED_COLOR_OFF);
    }

    /* Start for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */

    // enable tune driver
    // #define TONEALARM_DEVICE_PATH "/dev/tone_alarm"
    px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    ioctl(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STARTUP_TUNE);
    close(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd);// close here since this may be used in another thread
    px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd = -1;

    /* Start for S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude1' */
    {
      /* S-Function Block: <Root>/vehicle_attitude1 */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(vehicle_attitude));
      px4demo_attitude_system20280_DW.vehicle_attitude1_vehicle_attit.fd = fd;
      px4demo_attitude_system20280_DW.vehicle_attitude1_vehicle_attit.events =
        POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to vehicle_attitude topic (fd = %d)*\n", fd);
    }

    /* Start for MATLABSystem: '<Root>/Serial1' */
    px4demo_attitude_system20280_DW.obj.isInitialized = 0;
    px4demo_attitude_system20280_DW.obj.isInitialized = 1;
    for (fh_index_tmp = 0; fh_index_tmp < 11; fh_index_tmp++) {
      devName[fh_index_tmp] = tmp[fh_index_tmp];
    }

    MW_openSerialPort(devName, 57600U, px4demo_attitude_system20_block,
                      &fh_index_tmp);
    px4demo_attitude_system20280_DW.obj.fh_index = fh_index_tmp;

    /* End of Start for MATLABSystem: '<Root>/Serial1' */

    /* Start for MATLABSystem: '<Root>/Serial' */
    px4demo_attitude_system20280_DW.obj_a.isInitialized = 0;
    px4demo_attitude_system20280_DW.obj_a.isInitialized = 1;
    for (fh_index_tmp = 0; fh_index_tmp < 11; fh_index_tmp++) {
      devName[fh_index_tmp] = tmp[fh_index_tmp];
    }

    MW_openSerialPort(devName, 57600U, px4demo_attitude_system20_block,
                      &fh_index_tmp);
    px4demo_attitude_system20280_DW.obj_a.fh_index = fh_index_tmp;

    /* End of Start for MATLABSystem: '<Root>/Serial' */

    /* SystemInitialize for ModelReference: '<Root>/ControlSubsystem' */
    px4demo_attitude_control20_Init
      (&(px4demo_attitude_system20280_DW.ControlSubsystem_DWORK1.rtdw));
  }
}

/* Model terminate function */
void px4demo_attitude_system20280822car_terminate(void)
{
  uint8_T devName[11];
  static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U, 121U,
    83U, 49U, 0U };

  int32_T i;

  /* Close uORB service used in the S-Function Block: <Root>/input_rc */
  close(px4demo_attitude_system20280_DW.input_rc_input_rc_fd.fd);

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_gps */
  close(px4demo_attitude_system20280_DW.vehicle_gps_gps_fd.fd);

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
  ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
        RGBLED_COLOR_OFF);
  ioctl(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
        RGBLED_MODE_OFF);
  usleep(100);

  /* Close uORB service used in the S-Function Block: <Root>/RGB_LED */
  close(px4demo_attitude_system20280_DW.RGB_LED_rgbled_fd);

  /* Terminate for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd != -1) {
    close(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd);// this may be open in a different thread. close first.
    px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);// re-open
    ioctl(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STOP_TUNE);

    /* Close service used in the S-Function Block: <Root>/Speaker_Tune */
    close(px4demo_attitude_system20280_DW.Speaker_Tune_tune_fd);// finally close device here
  }

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_attitude1 */
  close(px4demo_attitude_system20280_DW.vehicle_attitude1_vehicle_attit.fd);

  /* Start for MATLABSystem: '<Root>/Serial1' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial1'
   */
  if (px4demo_attitude_system20280_DW.obj.isInitialized == 1) {
    px4demo_attitude_system20280_DW.obj.isInitialized = 2;
    for (i = 0; i < 11; i++) {
      devName[i] = tmp[i];
    }

    MW_closeSerialPort(devName, px4demo_attitude_system20280_DW.obj.fh_index);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial1' */

  /* Start for MATLABSystem: '<Root>/Serial' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial'
   */
  if (px4demo_attitude_system20280_DW.obj_a.isInitialized == 1) {
    px4demo_attitude_system20280_DW.obj_a.isInitialized = 2;
    for (i = 0; i < 11; i++) {
      devName[i] = tmp[i];
    }

    MW_closeSerialPort(devName, px4demo_attitude_system20280_DW.obj_a.fh_index);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
