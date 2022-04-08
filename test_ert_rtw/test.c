/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
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

#include "test.h"
#include "test_private.h"

/* Named constants for Chart: '<S2>/cruise_mode_stateflow' */
#define test_IN_Init                   ((uint8_T)1U)
#define test_IN_NO_ACTIVE_CHILD        ((uint8_T)0U)
#define test_IN_State                  ((uint8_T)2U)

/* System initialize for atomic system: '<S2>/cruise_mode_stateflow' */
void test_cruise_mode_stateflow_Init(real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_stateflow_test_T *localDW)
{
  localDW->is_active_c3_test = 0U;
  localDW->is_c3_test = test_IN_NO_ACTIVE_CHILD;
  localDW->local_data = 0.0;
  *rty_speed = 0.0;
  *rty_angle = 0.0;
}

/* Output and update for atomic system: '<S2>/cruise_mode_stateflow' */
void test_cruise_mode_stateflow(real_T rtu_cam_object_angle, 
								real_T rtu_Iidar_angle_fov, 
								real_T *rty_speed, 
								real_T *rty_angle,
  								DW_cruise_mode_stateflow_test_T *localDW)
{
  /* Chart: '<S2>/cruise_mode_stateflow' */
	if (localDW->is_active_c3_test == 0U) 
	{
    	localDW->is_active_c3_test = 1U;
    	localDW->is_c3_test = test_IN_Init;
    	localDW->local_data = 0.0;
	}
	else if (localDW->is_c3_test == test_IN_Init) 
	{
   		if (localDW->local_data > 5.0)
		{
    		localDW->is_c3_test = test_IN_State;
    		*rty_speed = rtu_cam_object_angle;
    		*rty_angle = rtu_Iidar_angle_fov;
    	} 
		else 
		{
    		localDW->local_data++;
    	}
	} 
	else 
	{
    	/* case IN_State: */
    	localDW->is_c3_test = test_IN_Init;
    	localDW->local_data = 0.0;
  	}
  /* End of Chart: '<S2>/cruise_mode_stateflow' */
}

/* System initialize for atomic system: '<S1>/cruise_mode' */
void test_cruise_mode_Init(real_T *rty_speed, real_T *rty_angle,
  DW_cruise_mode_test_T *localDW)
{
  /* SystemInitialize for Chart: '<S2>/cruise_mode_stateflow' */
  test_cruise_mode_stateflow_Init(rty_speed, rty_angle,
    &localDW->sf_cruise_mode_stateflow);
}

/* Output and update for atomic system: '<S1>/cruise_mode' */
void test_cruise_mode(real_T rtu_cam_object_angle, real_T rtu_Iidar_angle_fov,
                      real_T *rty_speed, real_T *rty_angle,
                      DW_cruise_mode_test_T *localDW)
{
  /* Chart: '<S2>/cruise_mode_stateflow' */
  test_cruise_mode_stateflow(rtu_cam_object_angle, rtu_Iidar_angle_fov,
    rty_speed, rty_angle, &localDW->sf_cruise_mode_stateflow);
}

/* System initialize for atomic system: '<Root>/call_sensor_fusion' */
void test_call_sensor_fusion_Init(real_T *rty_speed, real_T *rty_angle,
  DW_call_sensor_fusion_test_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/cruise_mode' */
  test_cruise_mode_Init(rty_speed, rty_angle, &localDW->cruise_mode);

  /* End of SystemInitialize for SubSystem: '<S1>/cruise_mode' */
}

/* Output and update for atomic system: '<Root>/call_sensor_fusion' */
void test_call_sensor_fusion(real_T rtu_cam_object_angle, real_T
  rtu_Iidar_angle_fov, real_T *rty_speed, real_T *rty_angle,
  DW_call_sensor_fusion_test_T *localDW)
{
  /* Outputs for Atomic SubSystem: '<S1>/cruise_mode' */
  test_cruise_mode(rtu_cam_object_angle, rtu_Iidar_angle_fov, rty_speed,
                   rty_angle, &localDW->cruise_mode);

  /* End of Outputs for SubSystem: '<S1>/cruise_mode' */
}

/* Model step function */
void test_step(RT_MODEL_test_T *const test_M, real_T test_U_cam_object_angle,
               real_T test_U_Iidar_angle_fov)
{
  DW_test_T *test_DW = ((DW_test_T *) test_M->dwork);
  real_T speed;
  real_T angle;

  /* Outputs for Atomic SubSystem: '<Root>/call_sensor_fusion' */

  /* Inport: '<Root>/cam_object_angle' incorporates:
   *  Inport: '<Root>/Iidar_angle_fov'
   */
  test_call_sensor_fusion(test_U_cam_object_angle, test_U_Iidar_angle_fov,
    &speed, &angle, &test_DW->call_sensor_fusion);

  /* End of Outputs for SubSystem: '<Root>/call_sensor_fusion' */
}

/* Model initialize function */
void test_initialize(RT_MODEL_test_T *const test_M, real_T
                     *test_U_cam_line_angle, real_T *test_U_cam_object_angle,
                     real_T *test_U_Iidar_angle_fov, real_T
                     *test_U_Iidar_dist_fov, real_T *test_U_bad_lane_flag,
                     real_T *test_U_accident_flag, real_T
                     *test_U_accident_location_angle, real_T
                     *test_U_Iidar_angle_nfov, real_T *test_U_Iidar_dist_nfov)
{
  DW_test_T *test_DW = ((DW_test_T *) test_M->dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)test_DW, 0,
                sizeof(DW_test_T));

  /* external inputs */
  *test_U_cam_line_angle = 0.0;
  *test_U_cam_object_angle = 0.0;
  *test_U_Iidar_angle_fov = 0.0;
  *test_U_Iidar_dist_fov = 0.0;
  *test_U_bad_lane_flag = 0.0;
  *test_U_accident_flag = 0.0;
  *test_U_accident_location_angle = 0.0;
  *test_U_Iidar_angle_nfov = 0.0;
  *test_U_Iidar_dist_nfov = 0.0;

  {
    real_T speed;
    real_T angle;

    /* SystemInitialize for Atomic SubSystem: '<Root>/call_sensor_fusion' */
    test_call_sensor_fusion_Init(&speed, &angle, &test_DW->call_sensor_fusion);

    /* End of SystemInitialize for SubSystem: '<Root>/call_sensor_fusion' */
  }
}

/* Model terminate function */
void test_terminate(RT_MODEL_test_T *const test_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(test_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
