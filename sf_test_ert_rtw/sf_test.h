/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_test.h
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

#ifndef RTW_HEADER_sf_test_h_
#define RTW_HEADER_sf_test_h_
#include <string.h>
#ifndef sf_test_COMMON_INCLUDES_
# define sf_test_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#endif                                 /* sf_test_COMMON_INCLUDES_ */

#include "sf_test_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S2>/cruise_flowchart' */
typedef struct {
  real_T local_line_angle;             /* '<S2>/cruise_flowchart' */
  real_T local_current_speed_avr;      /* '<S2>/cruise_flowchart' */
  real_T car_check;                    /* '<S2>/cruise_flowchart' */
  uint8_T is_active_c3_sf_test;        /* '<S2>/cruise_flowchart' */
  uint8_T is_c3_sf_test;               /* '<S2>/cruise_flowchart' */
  uint8_T is_front_car_decision;       /* '<S2>/cruise_flowchart' */
} DW_cruise_flowchart_sf_test_T;

/* Block states (default storage) for system '<S1>/cruise_mode' */
typedef struct {
  DW_cruise_flowchart_sf_test_T sf_cruise_flowchart;/* '<S2>/cruise_flowchart' */
} DW_cruise_mode_sf_test_T;

/* Block states (default storage) for system '<S3>/submission_flowchart' */
typedef struct {
  uint8_T is_active_c1_sf_test;        /* '<S3>/submission_flowchart' */
  uint8_T is_c1_sf_test;               /* '<S3>/submission_flowchart' */
  uint8_T is_init_func;                /* '<S3>/submission_flowchart' */
} DW_submission_flowchart_sf_te_T;

/* Block states (default storage) for system '<S1>/submission_mode' */
typedef struct {
  DW_submission_flowchart_sf_te_T sf_submission_flowchart;/* '<S3>/submission_flowchart' */
} DW_submission_mode_sf_test_T;

/* Block states (default storage) for system '<Root>/sensor_fusion' */
typedef struct {
  DW_submission_mode_sf_test_T submission_mode;/* '<S1>/submission_mode' */
  DW_cruise_mode_sf_test_T cruise_mode;/* '<S1>/cruise_mode' */
} DW_sensor_fusion_sf_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_sensor_fusion_sf_test_T sensor_fusion;/* '<Root>/sensor_fusion' */
} DW_sf_test_T;

/* Real-time Model Data Structure */
struct tag_RTM_sf_test_T {
  const char_T * volatile errorStatus;
  DW_sf_test_T *dwork;
};

/* External data declarations for dependent source files */
extern const LIDAR sf_test_rtZLIDAR;   /* LIDAR ground */
extern const CAM sf_test_rtZCAM;       /* CAM ground */
extern const CONTROL sf_test_rtZCONTROL;/* CONTROL ground */

/* Model entry point functions */
extern void sf_test_initialize(RT_MODEL_sf_test_T *const sf_test_M, LIDAR
  *sf_test_U_LIDAR_INPUT, CAM *sf_test_U_CAM_INPUT, CONTROL
  *sf_test_U_CONTROL_INPUT, real_T *sf_test_Y_db_steering_angle, real_T
  *sf_test_Y_front_car_speed, real_T *sf_test_Y_lane_change_flag, real_T
  *sf_test_Y_overfast_flag, uint16_T *sf_test_Y_uint16_normal_run_speed, real_T *
  sf_test_Y_bad_lane_flag, real_T *sf_test_Y_accident_flag);
extern void sf_test_step(RT_MODEL_sf_test_T *const sf_test_M, real_T
  *sf_test_Y_db_steering_angle, real_T *sf_test_Y_front_car_speed, real_T
  *sf_test_Y_lane_change_flag, real_T *sf_test_Y_overfast_flag, uint16_T
  *sf_test_Y_uint16_normal_run_speed, real_T *sf_test_Y_bad_lane_flag, real_T
  *sf_test_Y_accident_flag);
extern void sf_test_terminate(RT_MODEL_sf_test_T *const sf_test_M);

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
 * '<Root>' : 'sf_test'
 * '<S1>'   : 'sf_test/sensor_fusion'
 * '<S2>'   : 'sf_test/sensor_fusion/cruise_mode'
 * '<S3>'   : 'sf_test/sensor_fusion/submission_mode'
 * '<S4>'   : 'sf_test/sensor_fusion/cruise_mode/cruise_flowchart'
 * '<S5>'   : 'sf_test/sensor_fusion/submission_mode/submission_flowchart'
 */
#endif                                 /* RTW_HEADER_sf_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
