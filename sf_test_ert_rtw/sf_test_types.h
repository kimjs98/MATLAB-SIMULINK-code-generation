/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_test_types.h
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

#ifndef RTW_HEADER_sf_test_types_h_
#define RTW_HEADER_sf_test_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_LIDAR_
#define DEFINED_TYPEDEF_FOR_LIDAR_

typedef struct {
  real_T input_LIDAR_angle_fov;
  real_T input_LIDAR_dist_fov;
  real_T input_LIDAR_angle_nfov;
  real_T input_LIDAR_dist_nfov;
} LIDAR;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAM_
#define DEFINED_TYPEDEF_FOR_CAM_

typedef struct {
  real_T input_CAM_line_angle;
  uint16_T input_CAM_object_angle;
  uint16_T input_CAM_accident_location;
  uint16_T input_CAM_bad_lane_flag;
  uint16_T input_CAM_accident_flag;
  uint16_T input_CAM_car_check_flag;
} CAM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CONTROL_
#define DEFINED_TYPEDEF_FOR_CONTROL_

typedef struct {
  real_T input_CTR_prev_speed;
  real_T input_CTR_next_speed;
} CONTROL;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_sf_test_T RT_MODEL_sf_test_T;

#endif                                 /* RTW_HEADER_sf_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
