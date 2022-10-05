/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.c
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.634
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Oct  5 22:50:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sf_simulink.h"
#include "sf_simulink_private.h"

/* Named constants for Chart: '<S2>/cruser and submission chart' */
#define sf_simulink_EXTRA_SPEED        (10.0)
#define sf_simulink_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define sf_simulink_IN_change_lane     ((uint8_T)1U)
#define sf_simulink_IN_init            ((uint8_T)2U)
#define sf_simulink_IN_normal_running  ((uint8_T)3U)
#define sf_simulink_STOP_DISTANCE      (0.5)
#define sf_simulink_TIME_UNIT          (1.0E+6)

/* Named constants for Chart: '<S2>/light on-off chart' */
#define sf_simulink_IN_init_l          ((uint8_T)1U)
#define sf_simulink_IN_running         ((uint8_T)2U)

/* Named constants for Chart: '<S1>/object fetch' */
#define sf_simulink_DIFF_ANGLE         (3)
#define sf_simulink_limit              (9)

/* Forward declaration for local functions */
static void sf_simulink_merge_m(int32_T idx[10], int32_T x[10], int32_T np,
  int32_T nq, int32_T iwork[10], int32_T xwork[10]);
static void sf_simulink_sort_k(int32_T x[10]);
static void sf_simulink_qsort(const int32_T x[10], int32_T y[10]);
static void sf_simulink_signal_processing(const CORE
  *BusConversion_InsertedFor_cru_l, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW);
static void sf_simulink_time_reprocessing(const CORE
  *BusConversion_InsertedFor_cru_l, DW_sf_simulink_T *sf_simulink_DW);
static uint8_T sf_simulink_nonzero_front(const OBJECT x[360]);
static void sf_simul_check_signal_violation(const SIGNAL
  *BusConversion_InsertedFor_cruse, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW);
static void sf_simulink_accelerator(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_brake(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_up_count(int32_T *cnt, int32_T limit);
static int32_T sf_simulink_search(const int32_T x[10], const int32_T y[10],
  int32_T val);
static void sf_simulink_merge(int32_T idx_data[], int32_T x_data[], int32_T
  offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T xwork_data[]);
static void sf_simulink_sort(int32_T x_data[], int32_T x_size[2]);
static int32_T sf_simulink_front_ele(const OBJECT x[360]);

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_merge_m(int32_T idx[10], int32_T x[10], int32_T np,
  int32_T nq, int32_T iwork[10], int32_T xwork[10])
{
  int32_T p;
  int32_T q;
  int32_T iout;
  int32_T offset1;
  int32_T exitg1;
  if ((np != 0) && (nq != 0)) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      iwork[p] = idx[p];
      xwork[p] = x[p];
    }

    p = 0;
    q = np;
    iout = -1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx[q] = iwork[p];
            x[q] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_sort_k(int32_T x[10])
{
  int32_T idx[10];
  int32_T iwork[10];
  int32_T xwork[10];
  int32_T x4[4];
  int8_T idx4[4];
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int8_T perm_idx_1;
  int8_T perm_idx_0;
  int8_T perm_idx_2;
  int8_T perm_idx_3;
  int32_T tmp;
  int32_T tmp_0;
  idx4[0] = 1;
  idx4[1] = 2;
  idx4[2] = 3;
  idx4[3] = 4;
  x4[0] = x[0];
  x4[1] = x[1];
  x4[2] = x[2];
  x4[3] = x[3];
  if (x[0] <= x[1]) {
    i1 = 1;
    i2 = 2;
  } else {
    i1 = 2;
    i2 = 1;
  }

  if (x[2] <= x[3]) {
    i3 = 3;
    i4 = 4;
  } else {
    i3 = 4;
    i4 = 3;
  }

  tmp = x4[i1 - 1];
  tmp_0 = x4[i3 - 1];
  if (tmp <= tmp_0) {
    tmp = x4[i2 - 1];
    if (tmp <= tmp_0) {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i2;
      perm_idx_2 = (int8_T)i3;
      perm_idx_3 = (int8_T)i4;
    } else if (tmp <= x4[i4 - 1]) {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i3;
      perm_idx_2 = (int8_T)i2;
      perm_idx_3 = (int8_T)i4;
    } else {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i3;
      perm_idx_2 = (int8_T)i4;
      perm_idx_3 = (int8_T)i2;
    }
  } else {
    tmp_0 = x4[i4 - 1];
    if (tmp <= tmp_0) {
      if (x4[i2 - 1] <= tmp_0) {
        perm_idx_0 = (int8_T)i3;
        perm_idx_1 = (int8_T)i1;
        perm_idx_2 = (int8_T)i2;
        perm_idx_3 = (int8_T)i4;
      } else {
        perm_idx_0 = (int8_T)i3;
        perm_idx_1 = (int8_T)i1;
        perm_idx_2 = (int8_T)i4;
        perm_idx_3 = (int8_T)i2;
      }
    } else {
      perm_idx_0 = (int8_T)i3;
      perm_idx_1 = (int8_T)i4;
      perm_idx_2 = (int8_T)i1;
      perm_idx_3 = (int8_T)i2;
    }
  }

  i1 = perm_idx_0 - 1;
  idx[0] = idx4[i1];
  i2 = perm_idx_1 - 1;
  idx[1] = idx4[i2];
  i3 = perm_idx_2 - 1;
  idx[2] = idx4[i3];
  i4 = perm_idx_3 - 1;
  idx[3] = idx4[i4];
  x[0] = x4[i1];
  x[1] = x4[i2];
  x[2] = x4[i3];
  x[3] = x4[i4];
  idx4[0] = 5;
  idx4[1] = 6;
  idx4[2] = 7;
  idx4[3] = 8;
  x4[0] = x[4];
  x4[1] = x[5];
  x4[2] = x[6];
  x4[3] = x[7];
  if (x[4] <= x[5]) {
    i1 = 1;
    i2 = 2;
  } else {
    i1 = 2;
    i2 = 1;
  }

  if (x[6] <= x[7]) {
    i3 = 3;
    i4 = 4;
  } else {
    i3 = 4;
    i4 = 3;
  }

  tmp = x4[i1 - 1];
  tmp_0 = x4[i3 - 1];
  if (tmp <= tmp_0) {
    tmp = x4[i2 - 1];
    if (tmp <= tmp_0) {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i2;
      perm_idx_2 = (int8_T)i3;
      perm_idx_3 = (int8_T)i4;
    } else if (tmp <= x4[i4 - 1]) {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i3;
      perm_idx_2 = (int8_T)i2;
      perm_idx_3 = (int8_T)i4;
    } else {
      perm_idx_0 = (int8_T)i1;
      perm_idx_1 = (int8_T)i3;
      perm_idx_2 = (int8_T)i4;
      perm_idx_3 = (int8_T)i2;
    }
  } else {
    tmp_0 = x4[i4 - 1];
    if (tmp <= tmp_0) {
      if (x4[i2 - 1] <= tmp_0) {
        perm_idx_0 = (int8_T)i3;
        perm_idx_1 = (int8_T)i1;
        perm_idx_2 = (int8_T)i2;
        perm_idx_3 = (int8_T)i4;
      } else {
        perm_idx_0 = (int8_T)i3;
        perm_idx_1 = (int8_T)i1;
        perm_idx_2 = (int8_T)i4;
        perm_idx_3 = (int8_T)i2;
      }
    } else {
      perm_idx_0 = (int8_T)i3;
      perm_idx_1 = (int8_T)i4;
      perm_idx_2 = (int8_T)i1;
      perm_idx_3 = (int8_T)i2;
    }
  }

  i1 = perm_idx_0 - 1;
  idx[4] = idx4[i1];
  i2 = perm_idx_1 - 1;
  idx[5] = idx4[i2];
  i3 = perm_idx_2 - 1;
  idx[6] = idx4[i3];
  i4 = perm_idx_3 - 1;
  idx[7] = idx4[i4];
  x[4] = x4[i1];
  x[5] = x4[i2];
  x[6] = x4[i3];
  x[7] = x4[i4];
  idx4[0] = 9;
  x4[0] = x[8];
  idx4[1] = 10;
  x4[1] = x[9];
  if (x[8] <= x[9]) {
    perm_idx_0 = 1;
    perm_idx_1 = 2;
  } else {
    perm_idx_0 = 2;
    perm_idx_1 = 1;
  }

  i1 = perm_idx_0 - 1;
  idx[8] = idx4[i1];
  x[8] = x4[i1];
  i1 = perm_idx_1 - 1;
  idx[9] = idx4[i1];
  x[9] = x4[i1];
  for (i1 = 0; i1 < 10; i1++) {
    xwork[i1] = 0;
    iwork[i1] = 0;
  }

  sf_simulink_merge_m(idx, x, 4, 4, iwork, xwork);
  sf_simulink_merge_m(idx, x, 8, 2, iwork, xwork);
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_qsort(const int32_T x[10], int32_T y[10])
{
  int32_T input[10];
  int32_T n;
  for (n = 0; n < 10; n++) {
    input[n] = x[n];
  }

  sf_simulink_sort_k(input);
  for (n = 0; n < 10; n++) {
    y[n] = input[n];
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_signal_processing(const CORE
  *BusConversion_InsertedFor_cru_l, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW)
{
  /*  yellow or red signal  */
  sf_simulink_B->steering_angle = sf_simulink_B->cruiser.line_angle;
  sf_simulink_DW->save_time = sf_simulink_DW->time;
  sf_simulink_DW->time = BusConversion_InsertedFor_cru_l->time;
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_time_reprocessing(const CORE
  *BusConversion_InsertedFor_cru_l, DW_sf_simulink_T *sf_simulink_DW)
{
  sf_simulink_DW->time = BusConversion_InsertedFor_cru_l->time;

  /*  time is mircoseconds.
     range is 0 ~ 999999 */
  if (sf_simulink_DW->time < sf_simulink_DW->save_time) {
    sf_simulink_DW->dt = (sf_simulink_TIME_UNIT - sf_simulink_DW->save_time) +
      sf_simulink_DW->time;
  } else {
    sf_simulink_DW->dt = sf_simulink_DW->time - sf_simulink_DW->save_time;
  }

  sf_simulink_DW->dt /= sf_simulink_TIME_UNIT;
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static uint8_T sf_simulink_nonzero_front(const OBJECT x[360])
{
  int32_T n;
  int32_T b_n;
  int32_T c_n;
  uint32_T tmp;
  uint32_T tmp_0;
  b_n = 0;
  c_n = 0;
  for (n = 0; n < 25; n++) {
    tmp_0 = x[n].id;
    if (x[n].id > 2147483647U) {
      tmp_0 = 2147483647U;
    }

    tmp = x[n + 335].id;
    if (tmp > 2147483647U) {
      tmp = 2147483647U;
    }

    if ((int32_T)tmp_0 != 0) {
      b_n++;
    }

    if ((int32_T)tmp != 0) {
      c_n++;
    }
  }

  if (b_n < 0) {
    b_n = 0;
  } else {
    if (b_n > 255) {
      b_n = 255;
    }
  }

  if (c_n < 0) {
    c_n = 0;
  } else {
    if (c_n > 255) {
      c_n = 255;
    }
  }

  b_n = (int32_T)((uint32_T)b_n + c_n);
  if ((uint32_T)b_n > 255U) {
    b_n = 255;
  }

  return (uint8_T)b_n;
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simul_check_signal_violation(const SIGNAL
  *BusConversion_InsertedFor_cruse, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW)
{
  sf_simulink_B->signal_violation_flag = (uint8_T)
    ((BusConversion_InsertedFor_cruse->sig_flag == 1) &&
     (sf_simulink_DW->each_obj.dist >
      BusConversion_InsertedFor_cruse->stop_line_dist * 100.0));
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_accelerator(B_sf_simulink_T *sf_simulink_B)
{
  int32_T tmp;
  tmp = sf_simulink_B->speed + (int32_T)sf_simulink_EXTRA_SPEED;
  if (tmp < 256) {
    sf_simulink_B->speed = (uint8_T)tmp;
  } else {
    sf_simulink_B->speed = MAX_uint8_T;
  }

  if (sf_simulink_B->speed > 50) {
    sf_simulink_B->speed = 50U;
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_brake(B_sf_simulink_T *sf_simulink_B)
{
  int32_T tmp;
  tmp = sf_simulink_B->speed - (int32_T)sf_simulink_EXTRA_SPEED;
  if (tmp >= 0) {
    sf_simulink_B->speed = (uint8_T)tmp;
  } else {
    sf_simulink_B->speed = 0U;
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B)
{
  /*  overfast checking  */
  sf_simulink_B->overfast_flag = (uint8_T)(sf_simulink_B->front_car_speed > 60.0);
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_up_count(int32_T *cnt, int32_T limit)
{
  if (*cnt < limit) {
    if (*cnt > 2147483646) {
      *cnt = MAX_int32_T;
    } else {
      (*cnt)++;
    }
  }
}

/* Function for Chart: '<S1>/object fetch' */
static int32_T sf_simulink_search(const int32_T x[10], const int32_T y[10],
  int32_T val)
{
  int32_T b_ii;
  int8_T ii_data_idx_0;
  boolean_T exitg1;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 10)) {
    if (x[b_ii] == val) {
      ii_data_idx_0 = (int8_T)(b_ii + 1);
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  return y[ii_data_idx_0 - 1];
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_merge(int32_T idx_data[], int32_T x_data[], int32_T
  offset, int32_T np, int32_T nq, int32_T iwork_data[], int32_T xwork_data[])
{
  int32_T p;
  int32_T q;
  int32_T iout;
  int32_T offset1;
  int32_T exitg1;
  if (nq != 0) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      q = offset + p;
      iwork_data[p] = idx_data[q];
      xwork_data[p] = x_data[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_sort(int32_T x_data[], int32_T x_size[2])
{
  int32_T idx_data[25];
  int32_T b_x_data[25];
  int32_T iwork_data[25];
  int32_T xwork_data[25];
  int32_T x4[4];
  int8_T idx4[4];
  int8_T perm[4];
  int32_T nQuartets;
  int32_T nLeft;
  int32_T tailOffset;
  int32_T nTail;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T b_x_size[2];
  int32_T tmp;
  int32_T tmp_0;
  if (x_size[1] != 0) {
    b_x_size[1] = x_size[1];
    nQuartets = x_size[0] * x_size[1] - 1;
    if (0 <= nQuartets) {
      memcpy(&b_x_data[0], &x_data[0], (nQuartets + 1) * sizeof(int32_T));
    }

    nQuartets = x_size[1] - 1;
    if (0 <= nQuartets) {
      memset(&idx_data[0], 0, (nQuartets + 1) * sizeof(int32_T));
    }

    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    nQuartets = x_size[1] >> 2;
    for (nLeft = 0; nLeft < nQuartets; nLeft++) {
      tailOffset = nLeft << 2;
      idx4[0] = (int8_T)(tailOffset + 1);
      idx4[1] = (int8_T)(tailOffset + 2);
      idx4[2] = (int8_T)(tailOffset + 3);
      idx4[3] = (int8_T)(tailOffset + 4);
      x4[0] = b_x_data[tailOffset];
      nTail = b_x_data[tailOffset + 1];
      x4[1] = nTail;
      i3 = b_x_data[tailOffset + 2];
      x4[2] = i3;
      i4 = b_x_data[tailOffset + 3];
      x4[3] = i4;
      if (b_x_data[tailOffset] <= nTail) {
        nTail = 1;
        i2 = 2;
      } else {
        nTail = 2;
        i2 = 1;
      }

      if (i3 <= i4) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      tmp = x4[nTail - 1];
      tmp_0 = x4[i3 - 1];
      if (tmp <= tmp_0) {
        tmp = x4[i2 - 1];
        if (tmp <= tmp_0) {
          perm[0] = (int8_T)nTail;
          perm[1] = (int8_T)i2;
          perm[2] = (int8_T)i3;
          perm[3] = (int8_T)i4;
        } else if (tmp <= x4[i4 - 1]) {
          perm[0] = (int8_T)nTail;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i2;
          perm[3] = (int8_T)i4;
        } else {
          perm[0] = (int8_T)nTail;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i4;
          perm[3] = (int8_T)i2;
        }
      } else {
        tmp_0 = x4[i4 - 1];
        if (tmp <= tmp_0) {
          if (x4[i2 - 1] <= tmp_0) {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)nTail;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)nTail;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)nTail;
          perm[3] = (int8_T)i2;
        }
      }

      nTail = perm[0] - 1;
      idx_data[tailOffset] = idx4[nTail];
      i2 = perm[1] - 1;
      idx_data[tailOffset + 1] = idx4[i2];
      i3 = perm[2] - 1;
      idx_data[tailOffset + 2] = idx4[i3];
      i4 = perm[3] - 1;
      idx_data[tailOffset + 3] = idx4[i4];
      b_x_data[tailOffset] = x4[nTail];
      b_x_data[tailOffset + 1] = x4[i2];
      b_x_data[tailOffset + 2] = x4[i3];
      b_x_data[tailOffset + 3] = x4[i4];
    }

    nQuartets <<= 2;
    nLeft = x_size[1] - nQuartets;
    if (nLeft > 0) {
      for (tailOffset = 0; tailOffset < nLeft; tailOffset++) {
        nTail = nQuartets + tailOffset;
        idx4[tailOffset] = (int8_T)(nTail + 1);
        x4[tailOffset] = b_x_data[nTail];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (nLeft == 1) {
        perm[0] = 1;
      } else if (nLeft == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (tailOffset = 0; tailOffset < nLeft; tailOffset++) {
        nTail = perm[tailOffset] - 1;
        i2 = nQuartets + tailOffset;
        idx_data[i2] = idx4[nTail];
        b_x_data[i2] = x4[nTail];
      }
    }

    if (x_size[1] > 1) {
      nQuartets = (int8_T)x_size[1];
      if (0 <= nQuartets - 1) {
        memset(&xwork_data[0], 0, nQuartets * sizeof(int32_T));
      }

      nQuartets = (int8_T)x_size[1];
      if (0 <= nQuartets - 1) {
        memset(&iwork_data[0], 0, nQuartets * sizeof(int32_T));
      }

      nLeft = x_size[1] >> 2;
      nQuartets = 4;
      while (nLeft > 1) {
        if ((nLeft & 1U) != 0U) {
          nLeft--;
          tailOffset = nQuartets * nLeft;
          nTail = x_size[1] - tailOffset;
          if (nTail > nQuartets) {
            sf_simulink_merge(idx_data, b_x_data, tailOffset, nQuartets, nTail -
                              nQuartets, iwork_data, xwork_data);
          }
        }

        tailOffset = nQuartets << 1;
        nLeft >>= 1;
        for (nTail = 0; nTail < nLeft; nTail++) {
          sf_simulink_merge(idx_data, b_x_data, nTail * tailOffset, nQuartets,
                            nQuartets, iwork_data, xwork_data);
        }

        nQuartets = tailOffset;
      }

      if (x_size[1] > nQuartets) {
        sf_simulink_merge(idx_data, b_x_data, 0, nQuartets, x_size[1] -
                          nQuartets, iwork_data, xwork_data);
      }
    }

    x_size[0] = 1;
    x_size[1] = b_x_size[1];
    nQuartets = b_x_size[1];
    if (0 <= nQuartets - 1) {
      memcpy(&x_data[0], &b_x_data[0], nQuartets * sizeof(int32_T));
    }
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static int32_T sf_simulink_front_ele(const OBJECT x[360])
{
  int32_T y;
  int32_T id[360];
  int32_T mx;
  int32_T ii_data[25];
  int32_T b_ii_data[25];
  boolean_T b_y;
  boolean_T b_x[2];
  int32_T k;
  int32_T idx;
  int32_T ii_size[2];
  int32_T b_ii_size[2];
  uint32_T tmp;
  boolean_T exitg1;
  for (idx = 0; idx < 360; idx++) {
    tmp = x[idx].id;
    if (x[idx].id > 2147483647U) {
      tmp = 2147483647U;
    }

    id[idx] = (int32_T)tmp;
  }

  idx = 0;
  ii_size[0] = 1;
  mx = 0;
  exitg1 = false;
  while ((!exitg1) && (mx < 25)) {
    if (id[mx] != 0) {
      idx++;
      ii_data[idx - 1] = mx + 1;
      if (idx >= 25) {
        exitg1 = true;
      } else {
        mx++;
      }
    } else {
      mx++;
    }
  }

  if (1 > idx) {
    ii_size[1] = 0;
  } else {
    ii_size[1] = idx;
  }

  idx = 0;
  b_ii_size[0] = 1;
  mx = 0;
  exitg1 = false;
  while ((!exitg1) && (mx < 25)) {
    if (id[mx + 335] != 0) {
      idx++;
      b_ii_data[idx - 1] = mx + 1;
      if (idx >= 25) {
        exitg1 = true;
      } else {
        mx++;
      }
    } else {
      mx++;
    }
  }

  if (1 > idx) {
    b_ii_size[1] = 0;
  } else {
    b_ii_size[1] = idx;
  }

  idx = 0;
  mx = 0;
  b_x[0] = true;
  b_x[1] = (ii_size[1] > 0);
  b_y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!b_x[k]) {
      b_y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_y) {
    sf_simulink_sort(ii_data, ii_size);
    idx = ii_data[0];
    for (k = 1; k < ii_size[1]; k++) {
      if (idx > ii_data[k]) {
        idx = ii_data[k];
      }
    }
  }

  b_x[0] = true;
  b_x[1] = (b_ii_size[1] > 0);
  b_y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!b_x[k]) {
      b_y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_y) {
    sf_simulink_sort(b_ii_data, b_ii_size);
    mx = b_ii_data[0];
    for (k = 1; k < b_ii_size[1]; k++) {
      if (mx < b_ii_data[k]) {
        mx = b_ii_data[k];
      }
    }
  }

  if (((idx == 0) || (mx == 0)) && (idx == 0)) {
    idx = mx;
  }

  if (idx < -2147483647) {
    y = MIN_int32_T;
  } else {
    y = idx - 1;
  }

  return y;
}

/* Model step function */
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);
  ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
    sf_simulink_M->inputs;
  ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
    sf_simulink_M->outputs;
  int32_T local_angle_cam[10];
  int32_T local_angle_lidar[10];
  int8_T c;
  int8_T l;
  int16_T i;
  uint32_T save_dist;
  real_T relative_velovity;
  SIGNAL BusConversion_InsertedFor_cruse;
  int32_T tmp[10];
  int32_T tmp_0[10];
  int32_T qY;
  int32_T qY_0;
  int32_T local_angle_cam_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T exitg1;

  /* Chart: '<S1>/object fetch' incorporates:
   *  BusCreator generated from: '<S1>/object fetch'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   * */
  if (sf_simulink_DW->is_active_c1_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c1_sf_simulink = 1U;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_init_l;
  } else if (sf_simulink_DW->is_c1_sf_simulink == sf_simulink_IN_init_l) {
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_running;
  } else {
    /* case IN_running: */
    /*  local data qsort  */
    for (qY_0 = 0; qY_0 < 10; qY_0++) {
      tmp[qY_0] = sf_simulink_U->Input.object_angle[qY_0];
    }

    sf_simulink_qsort(tmp, local_angle_cam);
    for (qY_0 = 0; qY_0 < 10; qY_0++) {
      tmp[qY_0] = sf_simulink_U->Input1.angle[qY_0];
    }

    sf_simulink_qsort(tmp, local_angle_lidar);
    i = 0;
    c = 0;
    l = 0;
    while (i < 360) {
      /* NEW_PATTERN */
      /*  each data is bigger than zero,
         the absolute value of diff between local angles is smaller than three.
         !!! used data is set minus one !!!
         data is existed, what...  */
      if ((local_angle_cam[c] >= 0) && (i < local_angle_cam[c] - MAX_int32_T)) {
        qY_0 = MAX_int32_T;
      } else if ((local_angle_cam[c] < 0) && (i > local_angle_cam[c] -
                  MIN_int32_T)) {
        qY_0 = MIN_int32_T;
      } else {
        qY_0 = local_angle_cam[c] - i;
      }

      if ((local_angle_lidar[l] >= 0) && (i < local_angle_lidar[l] - MAX_int32_T))
      {
        qY = MAX_int32_T;
      } else if ((local_angle_lidar[l] < 0) && (i > local_angle_lidar[l] -
                  MIN_int32_T)) {
        qY = MIN_int32_T;
      } else {
        qY = local_angle_lidar[l] - i;
      }

      if (qY_0 < 0) {
        if (qY_0 <= MIN_int32_T) {
          qY_0 = MAX_int32_T;
        } else {
          qY_0 = -qY_0;
        }
      }

      if (qY < 0) {
        if (qY <= MIN_int32_T) {
          qY = MAX_int32_T;
        } else {
          qY = -qY;
        }
      }

      if ((local_angle_cam[c] < 0) && (local_angle_lidar[l] < MIN_int32_T
           - local_angle_cam[c])) {
        local_angle_cam_0 = MIN_int32_T;
      } else if ((local_angle_cam[c] > 0) && (local_angle_lidar[l] > MAX_int32_T
                  - local_angle_cam[c])) {
        local_angle_cam_0 = MAX_int32_T;
      } else {
        local_angle_cam_0 = local_angle_cam[c] + local_angle_lidar[l];
      }

      if ((local_angle_cam[c] >= 0) && (local_angle_lidar[l] >= 0) && (qY_0 <
           sf_simulink_DIFF_ANGLE) && (qY < sf_simulink_DIFF_ANGLE) &&
          (local_angle_cam_0 / 2 == i)) {
        sf_simulink_DW->each_object.who = 3U;
        for (qY_0 = 0; qY_0 < 10; qY_0++) {
          tmp[qY_0] = sf_simulink_U->Input.object_angle[qY_0];
          tmp_0[qY_0] = sf_simulink_U->Input.object_id[qY_0];
        }

        qY_0 = sf_simulink_search(tmp, tmp_0, local_angle_cam[c]);
        if (qY_0 < 0) {
          qY_0 = 0;
        }

        sf_simulink_DW->each_object.id = (uint32_T)qY_0;
        for (qY_0 = 0; qY_0 < 10; qY_0++) {
          tmp[qY_0] = sf_simulink_U->Input1.angle[qY_0];
          tmp_0[qY_0] = sf_simulink_U->Input1.dist[qY_0];
        }

        qY_0 = sf_simulink_search(tmp, tmp_0, local_angle_lidar[l]);
        if (qY_0 < 0) {
          qY_0 = 0;
        }

        sf_simulink_DW->each_object.dist = (uint32_T)qY_0;
        sf_simulink_B->object[i] = sf_simulink_DW->each_object;
        qY_0 = c;
        sf_simulink_up_count(&qY_0, sf_simulink_limit);
        if (qY_0 > 127) {
          qY_0 = 127;
        } else {
          if (qY_0 < -128) {
            qY_0 = -128;
          }
        }

        c = (int8_T)qY_0;
        qY_0 = l;
        sf_simulink_up_count(&qY_0, sf_simulink_limit);
        if (qY_0 > 127) {
          qY_0 = 127;
        } else {
          if (qY_0 < -128) {
            qY_0 = -128;
          }
        }

        l = (int8_T)qY_0;
      } else {
        do {
          exitg1 = 0;
          qY_0 = i - 3;
          if ((local_angle_cam[c] < qY_0) && (c < sf_simulink_limit)) {
            qY_0 = c;
            sf_simulink_up_count(&qY_0, sf_simulink_limit);
            if (qY_0 > 127) {
              qY_0 = 127;
            } else {
              if (qY_0 < -128) {
                qY_0 = -128;
              }
            }

            c = (int8_T)qY_0;
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        while ((local_angle_lidar[l] < qY_0) && (l < sf_simulink_limit)) {
          qY = l;
          sf_simulink_up_count(&qY, sf_simulink_limit);
          if (qY > 127) {
            qY = 127;
          } else {
            if (qY < -128) {
              qY = -128;
            }
          }

          l = (int8_T)qY;
        }

        sf_simulink_DW->each_object.who = 0U;
        sf_simulink_DW->each_object.id = 0U;
        sf_simulink_DW->each_object.dist = 0U;
        sf_simulink_B->object[i] = sf_simulink_DW->each_object;
      }

      i++;
    }

    /*  data fetch */
    sf_simulink_B->cruiser.line_angle = sf_simulink_U->Input.line_angle;
    sf_simulink_B->cruiser.car_check_flag = sf_simulink_U->Input.car_check_flag;
    sf_simulink_B->cruiser.change_lane_dir =
      sf_simulink_U->Input.change_lane_dir;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_running;
  }

  /* End of Chart: '<S1>/object fetch' */

  /* BusCreator generated from: '<S2>/cruser and submission chart' incorporates:
   *  Inport: '<Root>/Input'
   */
  BusConversion_InsertedFor_cruse.sig_flag = sf_simulink_U->Input.sig_flag;
  BusConversion_InsertedFor_cruse.stop_line_dist =
    sf_simulink_U->Input.stop_line_dist;

  /* Chart: '<S2>/cruser and submission chart' incorporates:
   *  Inport: '<Root>/Input2'
   */
  if (sf_simulink_DW->is_active_c3_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c3_sf_simulink = 1U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_init;

    /* local */
    sf_simulink_DW->save_time = 0.0;
    sf_simulink_DW->time = sf_simulink_U->Input2.time;

    /* output */
    sf_simulink_B->steering_angle = sf_simulink_B->cruiser.line_angle;
    sf_simulink_B->speed = 0U;
    sf_simulink_B->front_car_speed = 0.0;
    sf_simulink_B->overfast_flag = 0U;
    sf_simulink_B->signal_violation_flag = 0U;
    sf_simulink_B->change_lane_flag = 0U;
  } else {
    guard1 = false;
    guard2 = false;
    switch (sf_simulink_DW->is_c3_sf_simulink) {
     case sf_simulink_IN_change_lane:
      sf_simulink_signal_processing(&sf_simulink_U->Input2, sf_simulink_B,
        sf_simulink_DW);
      sf_simulink_time_reprocessing(&sf_simulink_U->Input2, sf_simulink_DW);
      if (sf_simulink_DW->dt <= 2.0) {
        if (sf_simulink_DW->change_lane_dir == 2) {
          sf_simulink_B->steering_angle = 70U;
        } else {
          sf_simulink_B->steering_angle = 110U;
        }

        if (sf_simulink_DW->each_obj.dist > 50U) {
          sf_simulink_B->speed = 25U;
        } else {
          sf_simulink_brake(sf_simulink_B);
        }

        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
      } else {
        sf_simulink_B->change_lane_flag = 0U;

        /*  discover the car in front  */
        if ((sf_simulink_B->cruiser.car_check_flag == 1) &&
            (sf_simulink_nonzero_front(sf_simulink_B->object) != 0)) {
          save_dist = sf_simulink_DW->each_obj.dist;
          sf_simulink_DW->each_obj = sf_simulink_B->object[sf_simulink_front_ele
            (sf_simulink_B->object)];
          sf_simul_check_signal_violation(&BusConversion_InsertedFor_cruse,
            sf_simulink_B, sf_simulink_DW);
          sf_simulink_time_reprocessing(&sf_simulink_U->Input2, sf_simulink_DW);
          relative_velovity = ((real_T)sf_simulink_DW->each_obj.dist - (real_T)
                               save_dist) / sf_simulink_DW->dt;

          /*  speed unit and relative_velovity unit is centimeters per seconds  */
          sf_simulink_B->front_car_speed = (real_T)sf_simulink_B->speed +
            relative_velovity;
          sf_simulink_check_speeding(sf_simulink_B);

          /*  the front car is getting closer
             If the front car is already close, can't change lane  */
          if ((relative_velovity <= 0.0) && (sf_simulink_DW->each_obj.dist >
               100U)) {
            sf_simulink_DW->change_lane_dir =
              sf_simulink_B->cruiser.change_lane_dir;
            sf_simulink_B->change_lane_flag = 1U;
            sf_simulink_B->speed = 25U;
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
          } else {
            /*  the front car is close
               if it insisted accelerate */
            if (sf_simulink_DW->each_obj.dist < 50U) {
              guard2 = true;
            } else {
              sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
            }
          }
        } else {
          /*  undiscover the car in front  */
          /*  signal light color isn't yellow or red  */
          if (sf_simulink_U->Input.sig_flag != 1) {
            sf_simulink_accelerator(sf_simulink_B);
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
          } else {
            /*  stop line is close  */
            if (sf_simulink_U->Input.stop_line_dist < sf_simulink_STOP_DISTANCE)
            {
              guard2 = true;
            } else {
              sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
            }
          }
        }
      }
      break;

     case sf_simulink_IN_init:
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
      break;

     default:
      /* case IN_normal_running: */
      sf_simulink_signal_processing(&sf_simulink_U->Input2, sf_simulink_B,
        sf_simulink_DW);

      /*  discover the car in front  */
      if ((sf_simulink_B->cruiser.car_check_flag == 1) &&
          (sf_simulink_nonzero_front(sf_simulink_B->object) != 0)) {
        save_dist = sf_simulink_DW->each_obj.dist;
        sf_simulink_DW->each_obj = sf_simulink_B->object[sf_simulink_front_ele
          (sf_simulink_B->object)];
        sf_simul_check_signal_violation(&BusConversion_InsertedFor_cruse,
          sf_simulink_B, sf_simulink_DW);
        sf_simulink_time_reprocessing(&sf_simulink_U->Input2, sf_simulink_DW);
        relative_velovity = ((real_T)sf_simulink_DW->each_obj.dist - (real_T)
                             save_dist) / sf_simulink_DW->dt;

        /*  speed unit and relative_velovity unit is centimeters per seconds  */
        sf_simulink_B->front_car_speed = (real_T)sf_simulink_B->speed +
          relative_velovity;
        sf_simulink_check_speeding(sf_simulink_B);

        /*  the front car is getting closer
           If the front car is already close, can't change lane  */
        if ((relative_velovity <= 0.0) && (sf_simulink_DW->each_obj.dist > 100U))
        {
          sf_simulink_DW->change_lane_dir =
            sf_simulink_B->cruiser.change_lane_dir;
          sf_simulink_B->change_lane_flag = 1U;
          sf_simulink_B->speed = 25U;
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
        } else {
          /*  the front car is close
             if it insisted accelerate */
          if (sf_simulink_DW->each_obj.dist < 50U) {
            guard1 = true;
          } else {
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
          }
        }
      } else {
        /*  undiscover the car in front  */
        /*  signal light color isn't yellow or red  */
        if (sf_simulink_U->Input.sig_flag != 1) {
          sf_simulink_accelerator(sf_simulink_B);
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
        } else {
          /*  stop line is close  */
          if (sf_simulink_U->Input.stop_line_dist < sf_simulink_STOP_DISTANCE) {
            guard1 = true;
          } else {
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
          }
        }
      }
      break;
    }

    if (guard2) {
      sf_simulink_brake(sf_simulink_B);
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
    }

    if (guard1) {
      sf_simulink_brake(sf_simulink_B);
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
    }
  }

  /* End of Chart: '<S2>/cruser and submission chart' */

  /* BusCreator generated from: '<Root>/Output' incorporates:
   *  Inport: '<Root>/Input'
   *  Outport: '<Root>/Output'
   */
  sf_simulink_Y->Output.front_car_speed = sf_simulink_B->front_car_speed;
  sf_simulink_Y->Output.overfast_flag = sf_simulink_B->overfast_flag;
  sf_simulink_Y->Output.signal_violation_flag =
    sf_simulink_B->signal_violation_flag;
  sf_simulink_Y->Output.crack_flag = sf_simulink_U->Input.crack_flag;

  /* Chart: '<S2>/light on-off chart' */
  if (sf_simulink_DW->is_active_c2_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c2_sf_simulink = 1U;
    sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_init_l;
    sf_simulink_B->blinker_onoff = 0U;
    sf_simulink_B->blinker_dir = 0U;
  } else if (sf_simulink_DW->is_c2_sf_simulink == sf_simulink_IN_init_l) {
    sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_running;
  } else {
    /* case IN_running: */
    /*  lane change or not  */
    guard1 = false;
    guard2 = false;
    if (sf_simulink_B->change_lane_flag == 1) {
      if (sf_simulink_B->cruiser.change_lane_dir == 1) {
        guard1 = true;
      } else {
        guard2 = true;
      }
    } else {
      /*  turn left  */
      if (sf_simulink_B->cruiser.line_angle > 100) {
        guard2 = true;
      } else {
        /*  turn right  */
        if (sf_simulink_B->cruiser.line_angle < 80) {
          guard1 = true;
        } else {
          sf_simulink_B->blinker_onoff = 0U;
        }
      }
    }

    if (guard2) {
      sf_simulink_B->blinker_onoff = 1U;
      sf_simulink_B->blinker_dir = 1U;
    }

    if (guard1) {
      sf_simulink_B->blinker_onoff = 1U;
      sf_simulink_B->blinker_dir = 0U;
    }

    sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_running;
  }

  /* End of Chart: '<S2>/light on-off chart' */

  /* BusCreator generated from: '<Root>/Output1' incorporates:
   *  Outport: '<Root>/Output1'
   */
  sf_simulink_Y->Output1.steering_angle = sf_simulink_B->steering_angle;
  sf_simulink_Y->Output1.speed = sf_simulink_B->speed;
  sf_simulink_Y->Output1.blinker_onoff = sf_simulink_B->blinker_onoff;
  sf_simulink_Y->Output1.blinker_dir = sf_simulink_B->blinker_dir;
}

/* Model initialize function */
void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);

  {
    OBJECT struct_temp;
    int32_T i;

    /* SystemInitialize for Chart: '<S1>/object fetch' */
    sf_simulink_DW->is_active_c1_sf_simulink = 0U;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
    sf_simulink_DW->each_object.who = 0U;
    sf_simulink_DW->each_object.id = 0U;
    sf_simulink_DW->each_object.dist = 0U;
    sf_simulink_B->cruiser.line_angle = 0U;
    sf_simulink_B->cruiser.car_check_flag = 0U;
    sf_simulink_B->cruiser.change_lane_dir = 0U;
    struct_temp.who = 0U;
    struct_temp.id = 0U;
    struct_temp.dist = 0U;
    for (i = 0; i < 360; i++) {
      sf_simulink_B->object[i] = struct_temp;
    }

    /* End of SystemInitialize for Chart: '<S1>/object fetch' */

    /* SystemInitialize for Chart: '<S2>/cruser and submission chart' */
    sf_simulink_DW->is_active_c3_sf_simulink = 0U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
    sf_simulink_DW->time = 0.0;
    sf_simulink_DW->save_time = 0.0;
    sf_simulink_DW->each_obj.who = 0U;
    sf_simulink_DW->each_obj.id = 0U;
    sf_simulink_DW->each_obj.dist = 0U;
    sf_simulink_DW->dt = 0.0;
    sf_simulink_DW->change_lane_dir = 0U;
    sf_simulink_B->signal_violation_flag = 0U;
    sf_simulink_B->steering_angle = 0U;
    sf_simulink_B->speed = 0U;
    sf_simulink_B->overfast_flag = 0U;
    sf_simulink_B->front_car_speed = 0.0;
    sf_simulink_B->change_lane_flag = 0U;

    /* SystemInitialize for Chart: '<S2>/light on-off chart' */
    sf_simulink_DW->is_active_c2_sf_simulink = 0U;
    sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
    sf_simulink_B->blinker_onoff = 0U;
    sf_simulink_B->blinker_dir = 0U;
  }
}

/* Model terminate function */
void sf_simulink_terminate(RT_MODEL_sf_simulink_T * sf_simulink_M)
{
  /* model code */
  rt_FREE(sf_simulink_M->blockIO);
  rt_FREE(sf_simulink_M->inputs);
  rt_FREE(sf_simulink_M->outputs);
  rt_FREE(sf_simulink_M->dwork);
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

  /* block I/O */
  {
    B_sf_simulink_T *b = (B_sf_simulink_T *) malloc(sizeof(B_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,b);
    sf_simulink_M->blockIO = (b);
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
    B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
    DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *)
      sf_simulink_M->dwork);
    ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
      sf_simulink_M->inputs;
    ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
      sf_simulink_M->outputs;

    /* block I/O */
    (void) memset(((void *) sf_simulink_B), 0,
                  sizeof(B_sf_simulink_T));

    /* states (dwork) */
    (void) memset((void *)sf_simulink_DW, 0,
                  sizeof(DW_sf_simulink_T));

    /* external inputs */
    (void)memset(sf_simulink_U, 0, sizeof(ExtU_sf_simulink_T));

    /* external outputs */
    (void) memset((void *)sf_simulink_Y, 0,
                  sizeof(ExtY_sf_simulink_T));
  }

  return sf_simulink_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
