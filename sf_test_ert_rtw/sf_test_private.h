/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_test_private.h
 *
 * Code generated for Simulink model 'sf_test'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Apr 18 21:15:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sf_test_private_h_
#define RTW_HEADER_sf_test_private_h_
#include "rtwtypes.h"
#include "sf_test.h"

extern void sf_test_cruise_flowchart_Init(DW_cruise_flowchart_sf_test_T *localDW);
extern void sf_test_cruise_flowchart(real_T rtu_cam_line_angle, uint16_T
  rtu_cam_car_check_flag, real_T rtu_prev_speed, real_T rtu_next_speed, real_T
  *rty_steering_angle, real_T *rty_front_car_speed, real_T *rty_lane_change_flag,
  real_T *rty_overfast_flag, uint16_T *rty_normal_run_speed,
  DW_cruise_flowchart_sf_test_T *localDW);
extern void sf_test_cruise_mode_Init(DW_cruise_mode_sf_test_T *localDW);
extern void sf_test_cruise_mode(real_T rtu_input_CAM_VALUE, uint16_T
  rtu_input_CAM_car_check_flag, real_T rtu_input_CONTROL_VEL, real_T
  rtu_input_CONTROL_VEL_j, real_T *rty_Output, real_T *rty_Output1, real_T
  *rty_Output2, real_T *rty_Output3, uint16_T *rty_Output4,
  DW_cruise_mode_sf_test_T *localDW);
extern void sf_te_submission_flowchart_Init(DW_submission_flowchart_sf_te_T
  *localDW);
extern void sf_test_submission_flowchart(uint16_T rtu_cam_bad_lane_flag,
  uint16_T rtu_cam_car_check_flag, uint16_T rtu_cam_accident_flag, real_T
  rtu_lane_change_flag, real_T *rty_bad_lane_flag, real_T *rty_accident_flag,
  DW_submission_flowchart_sf_te_T *localDW);
extern void sf_test_submission_mode_Init(DW_submission_mode_sf_test_T *localDW);
extern void sf_test_submission_mode(uint16_T rtu_input_CAM_FLAG, uint16_T
  rtu_input_CAM_FLAG_p, uint16_T rtu_input_CAM_FLAG_j, real_T
  rtu_lane_change_flag, real_T *rty_bad_lane_flag, real_T *rty_accident_flag,
  DW_submission_mode_sf_test_T *localDW);
extern void sf_test_sensor_fusion_Init(DW_sensor_fusion_sf_test_T *localDW);
extern void sf_test_sensor_fusion(real_T rtu_In1, uint16_T rtu_In2, uint16_T
  rtu_In2_k, uint16_T rtu_In2_l, real_T rtu_In5, real_T rtu_In5_k, real_T
  *rty_steering_angle, real_T *rty_front_car_speed, real_T *rty_lane_change_flag,
  real_T *rty_overfast_flag, uint16_T *rty_normal_run_speed, real_T
  *rty_bad_lane_flag, real_T *rty_accident_flag, DW_sensor_fusion_sf_test_T
  *localDW);

#endif                                 /* RTW_HEADER_sf_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
