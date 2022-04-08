/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'sf_test'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Apr  2 15:10:50 2022
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

/* '<Root>/cam_line_angle' */
static real_T sf_test_U_cam_line_angle;

/* '<Root>/cam_object_angle' */
static real_T sf_test_U_cam_object_angle;

/* '<Root>/Iidar_angle_fov' */
static real_T sf_test_U_Iidar_angle_fov;

/* '<Root>/Iidar_dist_fov' */
static real_T sf_test_U_Iidar_dist_fov;

/* '<Root>/cam_bad_lane_flag' */
static real_T sf_test_U_cam_bad_lane_flag;

/* '<Root>/cam_accident_flag' */
static real_T sf_test_U_cam_accident_flag;

/* '<Root>/cam_accident_location_angle' */
static real_T sf_test_U_cam_accident_location_angle;

/* '<Root>/Iidar_angle_nfov' */
static real_T sf_test_U_Iidar_angle_nfov;

/* '<Root>/Iidar_dist_nfov' */
static real_T sf_test_U_Iidar_dist_nfov;

/* '<Root>/cam_car_check_flag' */
static real_T sf_test_U_cam_car_check_flag;

/* '<Root>/prev_speed' */
static real_T sf_test_U_prev_speed;

/* '<Root>/next_speed' */
static real_T sf_test_U_next_speed;

/* '<Root>/steering_angle' */
static real_T sf_test_Y_steering_angle;

/* '<Root>/front_car_speed' */
static real_T sf_test_Y_front_car_speed;

/* '<Root>/lane_change_flag' */
static real_T sf_test_Y_lane_change_flag;

/* '<Root>/overfast_flag' */
static real_T sf_test_Y_overfast_flag;

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
  sf_test_step(sf_test_M, sf_test_U_cam_line_angle, sf_test_U_cam_bad_lane_flag,
               sf_test_U_cam_accident_flag, sf_test_U_cam_car_check_flag,
               sf_test_U_prev_speed, sf_test_U_next_speed,
               &sf_test_Y_steering_angle, &sf_test_Y_front_car_speed,
               &sf_test_Y_lane_change_flag, &sf_test_Y_overfast_flag);

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
  sf_test_initialize(sf_test_M, &sf_test_U_cam_line_angle,
                     &sf_test_U_cam_object_angle, &sf_test_U_Iidar_angle_fov,
                     &sf_test_U_Iidar_dist_fov, &sf_test_U_cam_bad_lane_flag,
                     &sf_test_U_cam_accident_flag,
                     &sf_test_U_cam_accident_location_angle,
                     &sf_test_U_Iidar_angle_nfov, &sf_test_U_Iidar_dist_nfov,
                     &sf_test_U_cam_car_check_flag, &sf_test_U_prev_speed,
                     &sf_test_U_next_speed, &sf_test_Y_steering_angle,
                     &sf_test_Y_front_car_speed, &sf_test_Y_lane_change_flag,
                     &sf_test_Y_overfast_flag);

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
