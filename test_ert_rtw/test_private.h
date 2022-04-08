/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_private.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Mar 30 02:20:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_private_h_
#define RTW_HEADER_test_private_h_
#include "rtwtypes.h"
#include "test.h"

extern void test_cruise_mode_stateflow_Init(real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_stateflow_test_T *localDW);
extern void test_cruise_mode_stateflow(real_T rtu_cam_object_angle, real_T
  rtu_Iidar_angle_fov, real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_stateflow_test_T *localDW);
extern void test_cruise_mode_Init(real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_test_T *localDW);
extern void test_cruise_mode(real_T rtu_cam_object_angle, real_T
  rtu_Iidar_angle_fov, real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_test_T *localDW);
extern void test_call_sensor_fusion_Init(real_T *rty_speed, real_T *rty_angle,
  DW_call_sensor_fusion_test_T *localDW);
extern void test_call_sensor_fusion(real_T rtu_cam_object_angle, real_T
  rtu_Iidar_angle_fov, real_T *rty_speed, real_T *rty_angle,
  DW_call_sensor_fusion_test_T *localDW);

#endif                                 /* RTW_HEADER_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
