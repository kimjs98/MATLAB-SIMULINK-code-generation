/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_test.c
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

#include "sf_test.h"
#include "sf_test_private.h"

/* Named constants for Chart: '<S2>/cruise_flowchart' */
#define sf_tes_IN_calculate_speed_logic ((uint8_T)1U)
#define sf_test_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define sf_test_IN_decision_init       ((uint8_T)2U)
#define sf_test_IN_fast_speed_state    ((uint8_T)3U)
#define sf_test_IN_front_car_decision  ((uint8_T)1U)
#define sf_test_IN_low_speed_state     ((uint8_T)4U)
#define sf_test_IN_normal_run          ((uint8_T)2U)

/* Named constants for Chart: '<S3>/submission_flowchart' */
#define sf_test_IN_NO_ACTIVE_CHILD_j   ((uint8_T)0U)
#define sf_test_IN_accident_func       ((uint8_T)1U)
#define sf_test_IN_bad_lane_func       ((uint8_T)2U)
#define sf_test_IN_init                ((uint8_T)1U)
#define sf_test_IN_init_func           ((uint8_T)3U)
#define sf_test_IN_lane_change_func    ((uint8_T)4U)
#define sf_test_IN_local_variable_init ((uint8_T)2U)

const CAM sf_test_rtZCAM = { 0.0,      /* input_CAM_line_angle */
  0U,                                  /* input_CAM_object_angle */
  0U,                                  /* input_CAM_accident_location */
  0U,                                  /* input_CAM_bad_lane_flag */
  0U,                                  /* input_CAM_accident_flag */
  0U                                   /* input_CAM_car_check_flag */
};

const CONTROL sf_test_rtZCONTROL = { 0.0,/* input_CTR_prev_speed */
  0.0                                  /* input_CTR_next_speed */
};

const LIDAR sf_test_rtZLIDAR = { 0.0,  /* input_LIDAR_angle_fov */
  0.0,                                 /* input_LIDAR_dist_fov */
  0.0,                                 /* input_LIDAR_angle_nfov */
  0.0                                  /* input_LIDAR_dist_nfov */
};

/* System initialize for atomic system: '<S2>/cruise_flowchart' */
void sf_test_cruise_flowchart_Init(DW_cruise_flowchart_sf_test_T *localDW)
{
  localDW->is_front_car_decision = sf_test_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c3_sf_test = 0U;
  localDW->is_c3_sf_test = sf_test_IN_NO_ACTIVE_CHILD;
}

/* Output and update for atomic system: '<S2>/cruise_flowchart' */
void sf_test_cruise_flowchart(real_T rtu_cam_line_angle, real_T
  rtu_cam_car_check_flag, real_T rtu_prev_speed, real_T rtu_next_speed, real_T
  *rty_steering_angle, real_T *rty_front_car_speed, real_T *rty_lane_change_flag,
  real_T *rty_overfast_flag, uint16_T *rty_normal_run_speed,
  DW_cruise_flowchart_sf_test_T *localDW)
{
  /* Chart: '<S2>/cruise_flowchart' */
  /* Gateway: sensor_fusion/cruise_mode/cruise_flowchart */
  /* During: sensor_fusion/cruise_mode/cruise_flowchart */
  if (localDW->is_active_c3_sf_test == 0U) {
    /* Entry: sensor_fusion/cruise_mode/cruise_flowchart */
    localDW->is_active_c3_sf_test = 1U;

    /* Entry Internal: sensor_fusion/cruise_mode/cruise_flowchart */
    /* Transition: '<S4>:9' */
    localDW->is_c3_sf_test = sf_test_IN_normal_run;

    /* Entry 'normal_run': '<S4>:8' */
    *rty_steering_angle = rtu_cam_line_angle;
    *rty_front_car_speed = 0.0;
    localDW->car_check = 1.0;
  } else if (localDW->is_c3_sf_test == sf_test_IN_front_car_decision) {
    /* During 'front_car_decision': '<S4>:12' */
    switch (localDW->is_front_car_decision) {
     case sf_tes_IN_calculate_speed_logic:
      /* During 'calculate_speed_logic': '<S4>:23' */
      if (*rty_front_car_speed > localDW->local_current_speed_avr) {
        /* Transition: '<S4>:31' */
        localDW->is_front_car_decision = sf_test_IN_fast_speed_state;

        /* Entry 'fast_speed_state': '<S4>:30' */
        *rty_overfast_flag = 1.0;
      } else {
        if (*rty_front_car_speed < localDW->local_current_speed_avr) {
          /* Transition: '<S4>:33' */
          localDW->is_front_car_decision = sf_test_IN_low_speed_state;

          /* Entry 'low_speed_state': '<S4>:32' */
          *rty_lane_change_flag = 1.0;
        }
      }
      break;

     case sf_test_IN_decision_init:
      /* During 'decision_init': '<S4>:18' */
      /* Transition: '<S4>:24' */
      /* Exit 'decision_init': '<S4>:18' */
      printf("%s\n", "decision_init_exit");
      fflush(stdout);
      localDW->is_front_car_decision = sf_tes_IN_calculate_speed_logic;

      /* Entry 'calculate_speed_logic': '<S4>:23' */
      *rty_steering_angle = localDW->local_line_angle;
      break;

     case sf_test_IN_fast_speed_state:
      *rty_overfast_flag = 1.0;

      /* During 'fast_speed_state': '<S4>:30' */
      break;

     default:
      *rty_lane_change_flag = 1.0;

      /* During 'low_speed_state': '<S4>:32' */
      break;
    }
  } else {
    /* During 'normal_run': '<S4>:8' */
    if ((rtu_cam_car_check_flag == 1.0) || (localDW->car_check == 1.0)) {
      /* Transition: '<S4>:15' */
      /* Transition: '<S4>:43' */
      /* Exit 'normal_run': '<S4>:8' */
      *rty_normal_run_speed = 1000U;
      printf("%s\n", "normal_run exit");
      fflush(stdout);
      localDW->is_c3_sf_test = sf_test_IN_front_car_decision;

      /* Entry 'front_car_decision': '<S4>:12' */
      /* Entry Internal 'front_car_decision': '<S4>:12' */
      /* Transition: '<S4>:19' */
      localDW->is_front_car_decision = sf_test_IN_decision_init;

      /* Entry 'decision_init': '<S4>:18' */
      localDW->local_line_angle = rtu_cam_line_angle;
      localDW->local_current_speed_avr = (rtu_prev_speed + rtu_next_speed) / 2.0;
    }
  }

  /* End of Chart: '<S2>/cruise_flowchart' */
}

/* System initialize for atomic system: '<S1>/cruise_mode' */
void sf_test_cruise_mode_Init(DW_cruise_mode_sf_test_T *localDW)
{
  /* SystemInitialize for Chart: '<S2>/cruise_flowchart' */
  sf_test_cruise_flowchart_Init(&localDW->sf_cruise_flowchart);
}

/* Output and update for atomic system: '<S1>/cruise_mode' */
void sf_test_cruise_mode(real_T rtu_cam_line_angle, real_T
  rtu_cam_car_check_flag, real_T rtu_prev_speed, real_T rtu_next_speed, real_T
  *rty_steering_angle, real_T *rty_front_car_speed, real_T *rty_lane_change_flag,
  real_T *rty_overfast_flag, uint16_T *rty_normal_run_speed,
  DW_cruise_mode_sf_test_T *localDW)
{
  /* Chart: '<S2>/cruise_flowchart' */
  sf_test_cruise_flowchart(rtu_cam_line_angle, rtu_cam_car_check_flag,
    rtu_prev_speed, rtu_next_speed, rty_steering_angle, rty_front_car_speed,
    rty_lane_change_flag, rty_overfast_flag, rty_normal_run_speed,
    &localDW->sf_cruise_flowchart);
}

/* System initialize for atomic system: '<S3>/submission_flowchart' */
void sf_te_submission_flowchart_Init(DW_submission_flowchart_sf_te_T *localDW)
{
  localDW->is_init_func = sf_test_IN_NO_ACTIVE_CHILD_j;
  localDW->is_active_c1_sf_test = 0U;
  localDW->is_c1_sf_test = sf_test_IN_NO_ACTIVE_CHILD_j;
}

/* Output and update for atomic system: '<S3>/submission_flowchart' */
void sf_test_submission_flowchart(real_T rtu_cam_bad_lane_flag, real_T
  rtu_cam_car_check_flag, real_T rtu_cam_accident_flag, real_T
  rtu_lane_change_flag, real_T *rty_bad_lane_flag, real_T *rty_accident_flag,
  DW_submission_flowchart_sf_te_T *localDW)
{
  /* Chart: '<S3>/submission_flowchart' */
  /* Gateway: sensor_fusion/submission_mode/submission_flowchart */
  /* During: sensor_fusion/submission_mode/submission_flowchart */
  if (localDW->is_active_c1_sf_test == 0U) {
    /* Entry: sensor_fusion/submission_mode/submission_flowchart */
    localDW->is_active_c1_sf_test = 1U;

    /* Entry Internal: sensor_fusion/submission_mode/submission_flowchart */
    /* Transition: '<S5>:44' */
    localDW->is_c1_sf_test = sf_test_IN_init_func;

    /* Entry 'init_func': '<S5>:11' */
    /* Entry Internal 'init_func': '<S5>:11' */
    /* Transition: '<S5>:36' */
    localDW->is_init_func = sf_test_IN_init;
  } else {
    switch (localDW->is_c1_sf_test) {
     case sf_test_IN_accident_func:
      *rty_accident_flag = 1.0;

      /* During 'accident_func': '<S5>:15' */
      break;

     case sf_test_IN_bad_lane_func:
      *rty_bad_lane_flag = 1.0;

      /* During 'bad_lane_func': '<S5>:17' */
      break;

     case sf_test_IN_init_func:
      /* During 'init_func': '<S5>:11' */
      if (localDW->is_init_func == sf_test_IN_init) {
        /* During 'init': '<S5>:35' */
        if (rtu_cam_car_check_flag == 1.0) {
          /* Transition: '<S5>:38' */
          localDW->is_init_func = sf_test_IN_local_variable_init;

          /* Entry 'local_variable_init': '<S5>:37' */
        } else {
          if (rtu_cam_bad_lane_flag == 1.0) {
            /* Transition: '<S5>:20' */
            localDW->is_init_func = sf_test_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c1_sf_test = sf_test_IN_bad_lane_func;

            /* Entry 'bad_lane_func': '<S5>:17' */
            *rty_bad_lane_flag = 1.0;
          }
        }
      } else {
        /* During 'local_variable_init': '<S5>:37' */
        if (rtu_cam_accident_flag == 1.0) {
          /* Transition: '<S5>:19' */
          localDW->is_init_func = sf_test_IN_NO_ACTIVE_CHILD_j;
          localDW->is_c1_sf_test = sf_test_IN_accident_func;

          /* Entry 'accident_func': '<S5>:15' */
          *rty_accident_flag = 1.0;
        } else {
          if (rtu_lane_change_flag == 1.0) {
            /* Transition: '<S5>:21' */
            localDW->is_init_func = sf_test_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c1_sf_test = sf_test_IN_lane_change_func;

            /* Entry 'lane_change_func': '<S5>:18' */
          }
        }
      }
      break;

     default:
      /* During 'lane_change_func': '<S5>:18' */
      break;
    }
  }

  /* End of Chart: '<S3>/submission_flowchart' */
}

/* System initialize for atomic system: '<S1>/submission_mode' */
void sf_test_submission_mode_Init(DW_submission_mode_sf_test_T *localDW)
{
  /* SystemInitialize for Chart: '<S3>/submission_flowchart' */
  sf_te_submission_flowchart_Init(&localDW->sf_submission_flowchart);
}

/* Output and update for atomic system: '<S1>/submission_mode' */
void sf_test_submission_mode(real_T rtu_cam_bad_lane_flag, real_T
  rtu_cam_car_check_flag, real_T rtu_cam_accident_flag, real_T
  rtu_lane_change_flag, real_T *rty_bad_lane_flag, real_T *rty_accident_flag,
  DW_submission_mode_sf_test_T *localDW)
{
  /* Chart: '<S3>/submission_flowchart' */
  sf_test_submission_flowchart(rtu_cam_bad_lane_flag, rtu_cam_car_check_flag,
    rtu_cam_accident_flag, rtu_lane_change_flag, rty_bad_lane_flag,
    rty_accident_flag, &localDW->sf_submission_flowchart);
}

/* System initialize for atomic system: '<Root>/sensor_fusion' */
void sf_test_sensor_fusion_Init(DW_sensor_fusion_sf_test_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/cruise_mode' */
  sf_test_cruise_mode_Init(&localDW->cruise_mode);

  /* End of SystemInitialize for SubSystem: '<S1>/cruise_mode' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/submission_mode' */
  sf_test_submission_mode_Init(&localDW->submission_mode);

  /* End of SystemInitialize for SubSystem: '<S1>/submission_mode' */
}

/* Output and update for atomic system: '<Root>/sensor_fusion' */
void sf_test_sensor_fusion(real_T *rty_steering_angle, real_T
  *rty_front_car_speed, real_T *rty_lane_change_flag, real_T *rty_overfast_flag,
  uint16_T *rty_normal_run_speed, real_T *rty_bad_lane_flag, real_T
  *rty_accident_flag, DW_sensor_fusion_sf_test_T *localDW)
{
  /* Outputs for Atomic SubSystem: '<S1>/cruise_mode' */
  sf_test_cruise_mode(0.0, 0.0, 0.0, 0.0, rty_steering_angle,
                      rty_front_car_speed, rty_lane_change_flag,
                      rty_overfast_flag, rty_normal_run_speed,
                      &localDW->cruise_mode);

  /* End of Outputs for SubSystem: '<S1>/cruise_mode' */

  /* Outputs for Atomic SubSystem: '<S1>/submission_mode' */
  sf_test_submission_mode(0.0, 0.0, 0.0, *rty_lane_change_flag,
    rty_bad_lane_flag, rty_accident_flag, &localDW->submission_mode);

  /* End of Outputs for SubSystem: '<S1>/submission_mode' */
}

/* Model step function */
void sf_test_step(RT_MODEL_sf_test_T *const sf_test_M, real_T
                  *sf_test_Y_db_steering_angle, real_T
                  *sf_test_Y_front_car_speed, real_T *sf_test_Y_lane_change_flag,
                  real_T *sf_test_Y_overfast_flag, uint16_T
                  *sf_test_Y_uint16_normal_run_speed, real_T
                  *sf_test_Y_bad_lane_flag, real_T *sf_test_Y_accident_flag)
{
  DW_sf_test_T *sf_test_DW = ((DW_sf_test_T *) sf_test_M->dwork);

  /* Outputs for Atomic SubSystem: '<Root>/sensor_fusion' */

  /* Outport: '<Root>/db_steering_angle' incorporates:
   *  Outport: '<Root>/accident_flag'
   *  Outport: '<Root>/bad_lane_flag'
   *  Outport: '<Root>/front_car_speed'
   *  Outport: '<Root>/lane_change_flag'
   *  Outport: '<Root>/overfast_flag'
   *  Outport: '<Root>/uint16_normal_run_speed'
   */
  sf_test_sensor_fusion(sf_test_Y_db_steering_angle, sf_test_Y_front_car_speed,
                        sf_test_Y_lane_change_flag, sf_test_Y_overfast_flag,
                        sf_test_Y_uint16_normal_run_speed,
                        sf_test_Y_bad_lane_flag, sf_test_Y_accident_flag,
                        &sf_test_DW->sensor_fusion);

  /* End of Outputs for SubSystem: '<Root>/sensor_fusion' */
}

/* Model initialize function */
void sf_test_initialize(RT_MODEL_sf_test_T *const sf_test_M, LIDAR
  *sf_test_U_LIDAR_INPUT, CAM *sf_test_U_CAM_INPUT, CONTROL
  *sf_test_U_CONTROL_INPUT, real_T *sf_test_Y_db_steering_angle, real_T
  *sf_test_Y_front_car_speed, real_T *sf_test_Y_lane_change_flag, real_T
  *sf_test_Y_overfast_flag, uint16_T *sf_test_Y_uint16_normal_run_speed, real_T *
  sf_test_Y_bad_lane_flag, real_T *sf_test_Y_accident_flag)
{
  DW_sf_test_T *sf_test_DW = ((DW_sf_test_T *) sf_test_M->dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)sf_test_DW, 0,
                sizeof(DW_sf_test_T));

  /* external inputs */
  *sf_test_U_LIDAR_INPUT = sf_test_rtZLIDAR;
  *sf_test_U_CAM_INPUT = sf_test_rtZCAM;
  *sf_test_U_CONTROL_INPUT = sf_test_rtZCONTROL;

  /* external outputs */
  (*sf_test_Y_db_steering_angle) = 0.0;
  (*sf_test_Y_front_car_speed) = 0.0;
  (*sf_test_Y_lane_change_flag) = 0.0;
  (*sf_test_Y_overfast_flag) = 0.0;
  (*sf_test_Y_uint16_normal_run_speed) = 0U;
  (*sf_test_Y_bad_lane_flag) = 0.0;
  (*sf_test_Y_accident_flag) = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/sensor_fusion' */
  sf_test_sensor_fusion_Init(&sf_test_DW->sensor_fusion);

  /* End of SystemInitialize for SubSystem: '<Root>/sensor_fusion' */
}

/* Model terminate function */
void sf_test_terminate(RT_MODEL_sf_test_T *const sf_test_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(sf_test_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
