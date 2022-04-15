/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'sf_test'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr 16 03:16:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "sf_test.h"                   /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_sf_test_T sf_test_M_;
static RT_MODEL_sf_test_T *const sf_test_MPtr = &sf_test_M_;/* Real-time model */
static DW_sf_test_T sf_test_DW;        /* Observable states */

/* '<Root>/LIDAR_INPUT' */
static LIDAR sf_test_U_LIDAR_INPUT;

/* '<Root>/CAM_INPUT' */
static CAM sf_test_U_CAM_INPUT;

/* '<Root>/CONTROL_INPUT' */
static CONTROL sf_test_U_CONTROL_INPUT;

/* '<Root>/db_steering_angle' */
static real_T sf_test_Y_db_steering_angle;

/* '<Root>/front_car_speed' */
static real_T sf_test_Y_front_car_speed;

/* '<Root>/lane_change_flag' */
static real_T sf_test_Y_lane_change_flag;

/* '<Root>/overfast_flag' */
static real_T sf_test_Y_overfast_flag;

/* '<Root>/uint16_normal_run_speed' */
static uint16_T sf_test_Y_uint16_normal_run_speed;

/* '<Root>/bad_lane_flag' */
static real_T sf_test_Y_bad_lane_flag;

/* '<Root>/accident_flag' */
static real_T sf_test_Y_accident_flag;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_sf_test_T *const sf_test_M);
void rt_OneStep(RT_MODEL_sf_test_T *const sf_test_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(sf_test_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  sf_test_step(sf_test_M, &sf_test_Y_db_steering_angle,
               &sf_test_Y_front_car_speed, &sf_test_Y_lane_change_flag,
               &sf_test_Y_overfast_flag, &sf_test_Y_uint16_normal_run_speed,
               &sf_test_Y_bad_lane_flag, &sf_test_Y_accident_flag);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_sf_test_T *const sf_test_M = sf_test_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  sf_test_M->dwork = &sf_test_DW;

  /* Initialize model */
  sf_test_initialize(sf_test_M, &sf_test_U_LIDAR_INPUT, &sf_test_U_CAM_INPUT,
                     &sf_test_U_CONTROL_INPUT, &sf_test_Y_db_steering_angle,
                     &sf_test_Y_front_car_speed, &sf_test_Y_lane_change_flag,
                     &sf_test_Y_overfast_flag,
                     &sf_test_Y_uint16_normal_run_speed,
                     &sf_test_Y_bad_lane_flag, &sf_test_Y_accident_flag);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.2 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(sf_test_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(sf_test_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  sf_test_terminate(sf_test_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
