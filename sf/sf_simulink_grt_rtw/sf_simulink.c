/*
 * sf_simulink.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sf_simulink".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Jun 22 15:35:32 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sf_simulink.h"
#include "sf_simulink_private.h"

const OUTPUT sf_simulink_rtZOUTPUT = {
  0.0,                                 /* steering_angle */
  0.0,                                 /* next_vel */
  0.0,                                 /* front_car_vel */
  0U,                                  /* lane_change_flag */
  0U,                                  /* overfast_flag */
  0U,                                  /* bad_lane_flag */
  0U                                   /* accident_flag */
} ;                                    /* OUTPUT ground */

/* Model step function */
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);
  ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
    sf_simulink_M->inputs;
  ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
    sf_simulink_M->outputs;

  /* Chart: '<S2>/cruser chart' */
  if (sf_simulink_DW->is_active_c3_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c3_sf_simulink = 1U;

    /* Outport: '<Root>/Output' incorporates:
     *  Inport: '<Root>/Input'
     */
    /* local */
    /* output */
    sf_simulink_Y->Output.steering_angle = sf_simulink_U->Input.line_angle;
    sf_simulink_Y->Output.next_vel = 0.0;
    sf_simulink_Y->Output.front_car_vel = 0.0;
    sf_simulink_Y->Output.lane_change_flag = 0U;
  } else {
    /* Outport: '<Root>/Output' incorporates:
     *  Inport: '<Root>/Input'
     */
    /* local */
    /* output */
    sf_simulink_Y->Output.steering_angle = sf_simulink_U->Input.line_angle;
    sf_simulink_Y->Output.next_vel = 0.0;
    sf_simulink_Y->Output.front_car_vel = 0.0;
    sf_simulink_Y->Output.lane_change_flag = 0U;
  }

  /* End of Chart: '<S2>/cruser chart' */

  /* Chart: '<S2>/check speed chart' */
  if (sf_simulink_DW->is_active_c1_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c1_sf_simulink = 1U;

    /* Outport: '<Root>/Output' */
    /* local */
    /* output */
    sf_simulink_Y->Output.overfast_flag = 0U;
  } else {
    /* Outport: '<Root>/Output' */
    /* local */
    /* output */
    sf_simulink_Y->Output.overfast_flag = 0U;
  }

  /* End of Chart: '<S2>/check speed chart' */

  /* Chart: '<S3>/bad lane' */
  if (sf_simulink_DW->is_active_c4_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c4_sf_simulink = 1U;

    /* Outport: '<Root>/Output' incorporates:
     *  Inport: '<Root>/Input'
     */
    sf_simulink_Y->Output.bad_lane_flag = sf_simulink_U->Input.bad_lane_flag;
  } else {
    /* Outport: '<Root>/Output' incorporates:
     *  Inport: '<Root>/Input'
     */
    sf_simulink_Y->Output.bad_lane_flag = sf_simulink_U->Input.bad_lane_flag;
  }

  /* End of Chart: '<S3>/bad lane' */

  /* Chart: '<S3>/acceident' */
  if (sf_simulink_DW->is_active_c2_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c2_sf_simulink = 1U;

    /* Outport: '<Root>/Output' incorporates:
     *  BusCreator: '<S3>/Bus Creator'
     *  Inport: '<Root>/Input'
     */
    /* local
       accident_flag = bus_accident.accident_flag; */
    /* output */
    sf_simulink_Y->Output.accident_flag = sf_simulink_U->Input.accident_flag;
  } else {
    /* Outport: '<Root>/Output' incorporates:
     *  BusCreator: '<S3>/Bus Creator'
     *  Inport: '<Root>/Input'
     */
    /* local
       accident_flag = bus_accident.accident_flag; */
    /* output */
    sf_simulink_Y->Output.accident_flag = sf_simulink_U->Input.accident_flag;
  }

  /* End of Chart: '<S3>/acceident' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(sf_simulink_M->rtwLogInfo,
                      (&sf_simulink_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(sf_simulink_M)!=-1) &&
        !((rtmGetTFinal(sf_simulink_M)-sf_simulink_M->Timing.taskTime0) >
          sf_simulink_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sf_simulink_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sf_simulink_M->Timing.clockTick0)) {
    ++sf_simulink_M->Timing.clockTickH0;
  }

  sf_simulink_M->Timing.taskTime0 = sf_simulink_M->Timing.clockTick0 *
    sf_simulink_M->Timing.stepSize0 + sf_simulink_M->Timing.clockTickH0 *
    sf_simulink_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);

  /* SystemInitialize for Chart: '<S2>/cruser chart' */
  sf_simulink_DW->is_active_c3_sf_simulink = 0U;

  /* SystemInitialize for Chart: '<S2>/check speed chart' */
  sf_simulink_DW->is_active_c1_sf_simulink = 0U;

  /* SystemInitialize for Chart: '<S3>/bad lane' */
  sf_simulink_DW->is_active_c4_sf_simulink = 0U;

  /* SystemInitialize for Chart: '<S3>/acceident' */
  sf_simulink_DW->is_active_c2_sf_simulink = 0U;
}

/* Model terminate function */
void sf_simulink_terminate(RT_MODEL_sf_simulink_T * sf_simulink_M)
{
  /* model code */
  rt_FREE(sf_simulink_M->inputs);
  rt_FREE(sf_simulink_M->outputs);
  rt_FREE(sf_simulink_M->dwork);

  {
    void *xptr = (void *) rtliGetLogXSignalPtrs(sf_simulink_M->rtwLogInfo);
    void *yptr = (void *) rtliGetLogYSignalPtrs(sf_simulink_M->rtwLogInfo);
    rt_FREE(xptr);
    rt_FREE(yptr);
  }

  rt_FREE(sf_simulink_M->rtwLogInfo);
  rt_FREE(sf_simulink_M);
}

/* Model data allocation function */
RT_MODEL_sf_simulink_T *sf_simulink(void)
{
  RT_MODEL_sf_simulink_T *sf_simulink_M;
  sf_simulink_M = (RT_MODEL_sf_simulink_T *) malloc(sizeof
    (RT_MODEL_sf_simulink_T));
  if (sf_simulink_M == NULL) {
    return NULL;
  }

  (void) memset((char *)sf_simulink_M, 0,
                sizeof(RT_MODEL_sf_simulink_T));

  /* Setup for data logging */
  {
    RTWLogInfo *rt_DataLoggingInfo = (RTWLogInfo *) malloc(sizeof(RTWLogInfo));
    rt_VALIDATE_MEMORY(sf_simulink_M,rt_DataLoggingInfo);
    rt_DataLoggingInfo->loggingInterval = NULL;
    sf_simulink_M->rtwLogInfo = rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sf_simulink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sf_simulink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalInfo(sf_simulink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(sf_simulink_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  {
    DW_sf_simulink_T *dwork = (DW_sf_simulink_T *) malloc(sizeof
      (DW_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,dwork);
    sf_simulink_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *) malloc(sizeof
      (ExtU_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,sf_simulink_U);
    sf_simulink_M->inputs = (((ExtU_sf_simulink_T *) sf_simulink_U));
  }

  /* external outputs */
  {
    ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *) malloc(sizeof
      (ExtY_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,sf_simulink_Y);
    sf_simulink_M->outputs = (sf_simulink_Y);
  }

  {
    DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *)
      sf_simulink_M->dwork);
    ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
      sf_simulink_M->inputs;
    ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
      sf_simulink_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtmSetTFinal(sf_simulink_M, 10.0);
    sf_simulink_M->Timing.stepSize0 = 0.2;

    /* Setup for data logging */
    {
      rtliSetLogT(sf_simulink_M->rtwLogInfo, "tout");
      rtliSetLogX(sf_simulink_M->rtwLogInfo, "");
      rtliSetLogXFinal(sf_simulink_M->rtwLogInfo, "");
      rtliSetLogVarNameModifier(sf_simulink_M->rtwLogInfo, "rt_");
      rtliSetLogFormat(sf_simulink_M->rtwLogInfo, 4);
      rtliSetLogMaxRows(sf_simulink_M->rtwLogInfo, 0);
      rtliSetLogDecimation(sf_simulink_M->rtwLogInfo, 1);
      rtliSetLogY(sf_simulink_M->rtwLogInfo, "");
    }

    sf_simulink_M->Timing.stepSize = (0.2);

    /* states (dwork) */
    (void) memset((void *)sf_simulink_DW, 0,
                  sizeof(DW_sf_simulink_T));

    /* external inputs */
    (void)memset(sf_simulink_U, 0, sizeof(ExtU_sf_simulink_T));

    /* external outputs */
    sf_simulink_Y->Output = sf_simulink_rtZOUTPUT;
  }

  return sf_simulink_M;
}
