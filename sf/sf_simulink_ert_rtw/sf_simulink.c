/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.c
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.592
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Sep 30 20:01:57 2022
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
#define sf_simulink_DIFF_ANGLE         (3.0)

/* Forward declaration for local functions */
static void sf_simulink_merge_m(int32_T idx[10], real_T x[10], int32_T offset,
  int32_T np, int32_T nq, int32_T iwork[10], real_T xwork[10]);
static void sf_simulink_sort_k(real_T x[10]);
static void sf_simulink_qsort(const real_T x[10], real_T y[10]);
static void sf_simulink_signal_processing(const CORE
  *BusConversion_InsertedFor_cru_l, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW);
static void sf_simulink_time_reprocessing(DW_sf_simulink_T *sf_simulink_DW);
static real_T sf_simulink_nonzero_front(const OBJECT x[360]);
static void sf_simulink_merge(int32_T idx_data[], real_T x_data[], int32_T np,
  int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
static void sf_simulink_sort(real_T x_data[], int32_T x_size[2]);
static real_T sf_simulink_front_ele(const OBJECT x[360]);
static void sf_simulink_accelerator(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_brake(B_sf_simulink_T *sf_simulink_B);
static void sf_simul_check_signal_violation(const SIGNAL
  *BusConversion_InsertedFor_cruse, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW);
static void sf_simulink_up_count(real_T *cnt, real_T limit);
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B);
static real_T sf_simulink_search(const real_T x[10], const real_T y[10], real_T
  val);

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_merge_m(int32_T idx[10], real_T x[10], int32_T offset,
  int32_T np, int32_T nq, int32_T iwork[10], real_T xwork[10])
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
      iwork[p] = idx[q];
      xwork[p] = x[q];
    }

    p = 0;
    q = np;
    iout = offset - 1;
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
static void sf_simulink_sort_k(real_T x[10])
{
  int32_T idx[10];
  int32_T nNaNs;
  real_T xwork[10];
  int32_T iwork[10];
  real_T x4[4];
  int8_T idx4[4];
  int32_T ib;
  int32_T m;
  int8_T perm[4];
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  real_T tmp;
  real_T tmp_0;
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  memset(&xwork[0], 0, 10U * sizeof(real_T));
  for (m = 0; m < 10; m++) {
    idx[m] = 0;
  }

  nNaNs = 0;
  ib = 0;
  for (m = 0; m < 10; m++) {
    if (rtIsNaN(x[m])) {
      idx[9 - nNaNs] = m + 1;
      xwork[9 - nNaNs] = x[m];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int8_T)(m + 1);
      x4[ib - 1] = x[m];
      if (ib == 4) {
        ib = m - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
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
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (tmp <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[i2 - 1] <= tmp_0) {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        i1 = perm[0] - 1;
        idx[ib - 3] = idx4[i1];
        i2 = perm[1] - 1;
        idx[ib - 2] = idx4[i2];
        i3 = perm[2] - 1;
        idx[ib - 1] = idx4[i3];
        i4 = perm[3] - 1;
        idx[ib] = idx4[i4];
        x[ib - 3] = x4[i1];
        x[ib - 2] = x4[i2];
        x[ib - 1] = x4[i3];
        x[ib] = x4[i4];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
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

    for (m = 0; m < ib; m++) {
      i1 = perm[m] - 1;
      i2 = ((m - nNaNs) - ib) + 10;
      idx[i2] = idx4[i1];
      x[i2] = x4[i1];
    }
  }

  m = (nNaNs >> 1) + 10;
  for (ib = 10; ib - 10 <= m - 11; ib++) {
    i1 = ib - nNaNs;
    i2 = idx[i1];
    idx[i1] = idx[19 - ib];
    idx[19 - ib] = i2;
    x[i1] = xwork[19 - ib];
    x[19 - ib] = xwork[i1];
  }

  if ((nNaNs & 1U) != 0U) {
    m -= nNaNs;
    x[m] = xwork[m];
  }

  if (10 - nNaNs > 1) {
    for (m = 0; m < 10; m++) {
      iwork[m] = 0;
    }

    ib = (10 - nNaNs) >> 2;
    m = 4;
    while (ib > 1) {
      if ((ib & 1U) != 0U) {
        ib--;
        i1 = m * ib;
        i2 = 10 - (nNaNs + i1);
        if (i2 > m) {
          sf_simulink_merge_m(idx, x, i1, m, i2 - m, iwork, xwork);
        }
      }

      i1 = m << 1;
      ib >>= 1;
      for (i2 = 0; i2 < ib; i2++) {
        sf_simulink_merge_m(idx, x, i2 * i1, m, m, iwork, xwork);
      }

      m = i1;
    }

    if (10 - nNaNs > m) {
      sf_simulink_merge_m(idx, x, 0, m, 10 - (nNaNs + m), iwork, xwork);
    }
  }
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_qsort(const real_T x[10], real_T y[10])
{
  memcpy(&y[0], &x[0], 10U * sizeof(real_T));
  sf_simulink_sort_k(y);
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
static void sf_simulink_time_reprocessing(DW_sf_simulink_T *sf_simulink_DW)
{
  /*  time is mircoseconds.
     range is 0 ~ 999999 */
  if (sf_simulink_DW->time < sf_simulink_DW->save_time) {
    sf_simulink_DW->dt = (sf_simulink_TIME_UNIT - sf_simulink_DW->save_time) +
      sf_simulink_DW->time;
  } else {
    sf_simulink_DW->dt = sf_simulink_DW->save_time - sf_simulink_DW->time;
  }

  sf_simulink_DW->dt /= sf_simulink_TIME_UNIT;
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static real_T sf_simulink_nonzero_front(const OBJECT x[360])
{
  int32_T n;
  int32_T b_n;
  int32_T c_n;
  b_n = 0;
  c_n = 0;
  for (n = 0; n < 10; n++) {
    if (x[n].id != 0U) {
      b_n++;
    }

    if (x[n + 350].id != 0U) {
      c_n++;
    }
  }

  return (real_T)b_n + (real_T)c_n;
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_merge(int32_T idx_data[], real_T x_data[], int32_T np,
  int32_T nq, int32_T iwork_data[], real_T xwork_data[])
{
  int32_T p;
  int32_T q;
  int32_T iout;
  int32_T offset1;
  int32_T exitg1;
  if ((np != 0) && (nq != 0)) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      iwork_data[p] = idx_data[p];
      xwork_data[p] = x_data[p];
    }

    p = 0;
    q = np;
    iout = -1;
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
static void sf_simulink_sort(real_T x_data[], int32_T x_size[2])
{
  int32_T idx_data[10];
  real_T b_x_data[10];
  int32_T iwork_data[10];
  real_T xwork_data[10];
  int32_T n;
  real_T x4[4];
  int8_T idx4[4];
  int32_T ib;
  int8_T perm[4];
  int32_T bLen;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T b_x_size[2];
  real_T tmp;
  real_T tmp_0;
  if (x_size[1] != 0) {
    b_x_size[1] = x_size[1];
    n = x_size[0] * x_size[1] - 1;
    if (0 <= n) {
      memcpy(&b_x_data[0], &x_data[0], (n + 1) * sizeof(real_T));
    }

    n = x_size[1] - 1;
    if (0 <= n) {
      memset(&idx_data[0], 0, (n + 1) * sizeof(int32_T));
    }

    n = x_size[1] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = 0;
    for (bLen = 0; bLen <= n; bLen++) {
      ib++;
      idx4[ib - 1] = (int8_T)(bLen + 1);
      x4[ib - 1] = b_x_data[bLen];
      if (ib == 4) {
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          ib = 3;
          i4 = 4;
        } else {
          ib = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[ib - 1];
        if (tmp <= tmp_0) {
          tmp = x4[i2 - 1];
          if (tmp <= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else if (tmp <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[i2 - 1] <= tmp_0) {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        i1 = perm[0] - 1;
        idx_data[bLen - 3] = idx4[i1];
        i2 = perm[1] - 1;
        idx_data[bLen - 2] = idx4[i2];
        ib = perm[2] - 1;
        idx_data[bLen - 1] = idx4[ib];
        i4 = perm[3] - 1;
        idx_data[bLen] = idx4[i4];
        b_x_data[bLen - 3] = x4[i1];
        b_x_data[bLen - 2] = x4[i2];
        b_x_data[bLen - 1] = x4[ib];
        b_x_data[bLen] = x4[i4];
        ib = 0;
      }
    }

    if (ib > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
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

      for (bLen = 0; bLen < ib; bLen++) {
        i1 = perm[bLen] - 1;
        i2 = ((n - ib) + bLen) + 1;
        idx_data[i2] = idx4[i1];
        b_x_data[i2] = x4[i1];
      }
    }

    if (x_size[1] > 1) {
      n = (int8_T)x_size[1];
      if (0 <= n - 1) {
        memset(&xwork_data[0], 0, n * sizeof(real_T));
      }

      n = (int8_T)x_size[1];
      if (0 <= n - 1) {
        memset(&iwork_data[0], 0, n * sizeof(int32_T));
      }

      n = x_size[1] >> 2;
      bLen = 4;
      while (n > 1) {
        sf_simulink_merge(idx_data, b_x_data, bLen, bLen, iwork_data, xwork_data);
        bLen <<= 1;
        n = 1;
      }

      if (x_size[1] > bLen) {
        sf_simulink_merge(idx_data, b_x_data, bLen, x_size[1] - bLen, iwork_data,
                          xwork_data);
      }
    }

    x_size[0] = 1;
    x_size[1] = b_x_size[1];
    n = b_x_size[1];
    if (0 <= n - 1) {
      memcpy(&x_data[0], &b_x_data[0], n * sizeof(real_T));
    }
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static real_T sf_simulink_front_ele(const OBJECT x[360])
{
  real_T y;
  uint32_T id[360];
  real_T f1_data[10];
  real_T f2_data[10];
  real_T mn;
  real_T mx;
  int8_T ii_data[10];
  boolean_T b_y;
  boolean_T b_x[2];
  int32_T b_ii;
  int32_T b_idx;
  int32_T i;
  int32_T f1_size[2];
  int32_T f2_size[2];
  boolean_T exitg1;
  for (b_idx = 0; b_idx < 360; b_idx++) {
    id[b_idx] = x[b_idx].id;
  }

  b_idx = 0;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 10)) {
    if (id[b_ii] != 0U) {
      b_idx++;
      ii_data[b_idx - 1] = (int8_T)(b_ii + 1);
      if (b_idx >= 10) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (1 > b_idx) {
    b_idx = 0;
  }

  f1_size[0] = 1;
  f1_size[1] = b_idx;
  b_ii = b_idx - 1;
  for (i = 0; i <= b_ii; i++) {
    f1_data[i] = ii_data[i];
  }

  b_idx = 0;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 10)) {
    if (id[b_ii + 350] != 0U) {
      b_idx++;
      ii_data[b_idx - 1] = (int8_T)(b_ii + 1);
      if (b_idx >= 10) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (1 > b_idx) {
    b_idx = 0;
  }

  f2_size[0] = 1;
  f2_size[1] = b_idx;
  b_ii = b_idx - 1;
  for (i = 0; i <= b_ii; i++) {
    f2_data[i] = ii_data[i];
  }

  mn = 0.0;
  mx = 0.0;
  b_x[0] = true;
  b_x[1] = (f1_size[1] > 0);
  b_y = true;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 2)) {
    if (!b_x[b_ii]) {
      b_y = false;
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  if (b_y) {
    sf_simulink_sort(f1_data, f1_size);
    if (f1_size[1] <= 2) {
      if (f1_size[1] == 1) {
        mn = f1_data[0];
      } else if (f1_data[0] > f1_data[1]) {
        mn = f1_data[1];
      } else {
        mn = f1_data[0];
      }
    } else {
      mn = f1_data[0];
      for (b_ii = 1; b_ii < f1_size[1]; b_ii++) {
        if (mn > f1_data[b_ii]) {
          mn = f1_data[b_ii];
        }
      }
    }
  }

  b_x[0] = true;
  b_x[1] = (b_idx > 0);
  b_y = true;
  b_idx = 0;
  exitg1 = false;
  while ((!exitg1) && (b_idx < 2)) {
    if (!b_x[b_idx]) {
      b_y = false;
      exitg1 = true;
    } else {
      b_idx++;
    }
  }

  if (b_y) {
    sf_simulink_sort(f2_data, f2_size);
    if (f2_size[1] <= 2) {
      if (f2_size[1] == 1) {
        mx = f2_data[0];
      } else if (f2_data[0] < f2_data[1]) {
        mx = f2_data[1];
      } else {
        mx = f2_data[0];
      }
    } else {
      mx = f2_data[0];
      for (b_idx = 1; b_idx < f2_size[1]; b_idx++) {
        if (mx < f2_data[b_idx]) {
          mx = f2_data[b_idx];
        }
      }
    }
  }

  if ((mn == 0.0) || (mx == 0.0)) {
    if (mn != 0.0) {
      y = mn - 1.0;
    } else {
      y = mx - 1.0;
    }
  } else {
    y = mn - 1.0;
  }

  return y;
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
static void sf_simul_check_signal_violation(const SIGNAL
  *BusConversion_InsertedFor_cruse, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW)
{
  sf_simulink_B->signal_violation_flag = (uint8_T)
    ((BusConversion_InsertedFor_cruse->sig_flag == 1) &&
     (sf_simulink_DW->each_obj.dist >
      BusConversion_InsertedFor_cruse->stop_line_dist * 100.0));
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_up_count(real_T *cnt, real_T limit)
{
  if (*cnt < limit) {
    (*cnt)++;
  }
}

/* Function for Chart: '<S2>/cruser and submission chart' */
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B)
{
  /*  overfast checking  */
  sf_simulink_B->overfast_flag = (uint8_T)(sf_simulink_B->front_car_speed > 60.0);
}

/* Function for Chart: '<S1>/object fetch' */
static real_T sf_simulink_search(const real_T x[10], const real_T y[10], real_T
  val)
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

/* Model step function */
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);
  ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
    sf_simulink_M->inputs;
  ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
    sf_simulink_M->outputs;
  real_T local_angle_cam[10];
  real_T local_angle_lidar[10];
  int8_T c;
  int8_T l;
  int16_T i;
  uint32_T save_dist;
  real_T relative_velovity;
  SIGNAL BusConversion_InsertedFor_cruse;
  real_T local_angle_cam_tmp[10];
  real_T local_angle_lidar_tmp[10];
  int32_T i_0;
  real_T tmp[10];
  boolean_T guard1 = false;
  boolean_T guard2 = false;

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
    for (i_0 = 0; i_0 < 10; i_0++) {
      local_angle_cam_tmp[i_0] = sf_simulink_U->Input.object_angle[i_0];
      local_angle_lidar_tmp[i_0] = sf_simulink_U->Input1.angle[i_0];
    }

    sf_simulink_qsort(local_angle_cam_tmp, local_angle_cam);
    sf_simulink_qsort(local_angle_lidar_tmp, local_angle_lidar);
    i = 0;
    c = 0;
    l = 0;
    while (i < 360) {
      /* NEW_PATTERN */
      guard1 = false;
      if ((c >= 10) && (l >= 10)) {
        guard1 = true;
      } else {
        /*  each data is bigger than zero,
           the absolute value of diff between local angles is smaller than three.
           !!! used data is set minus one !!!
           data is existed, what...  */
        if ((local_angle_cam[c] >= 0.0) && (local_angle_lidar[l] >= 0.0) &&
            (fabs(local_angle_cam[c] - (real_T)i) < sf_simulink_DIFF_ANGLE) &&
            (fabs(local_angle_lidar[l] - (real_T)i) < sf_simulink_DIFF_ANGLE) &&
            ((local_angle_cam[c] + local_angle_lidar[l]) / 2.0 == i)) {
          sf_simulink_DW->each_object.who = 3U;
          for (i_0 = 0; i_0 < 10; i_0++) {
            tmp[i_0] = sf_simulink_U->Input.object_id[i_0];
          }

          relative_velovity = sf_simulink_search(local_angle_cam_tmp, tmp,
            local_angle_cam[c]);
          if (relative_velovity < 4.294967296E+9) {
            if (relative_velovity >= 0.0) {
              sf_simulink_DW->each_object.id = (uint32_T)relative_velovity;
            } else {
              sf_simulink_DW->each_object.id = 0U;
            }
          } else {
            sf_simulink_DW->each_object.id = MAX_uint32_T;
          }

          for (i_0 = 0; i_0 < 10; i_0++) {
            tmp[i_0] = sf_simulink_U->Input1.dist[i_0];
          }

          relative_velovity = sf_simulink_search(local_angle_lidar_tmp, tmp,
            local_angle_lidar[l]);
          if (relative_velovity < 4.294967296E+9) {
            if (relative_velovity >= 0.0) {
              sf_simulink_DW->each_object.dist = (uint32_T)relative_velovity;
            } else {
              sf_simulink_DW->each_object.dist = 0U;
            }
          } else {
            sf_simulink_DW->each_object.dist = MAX_uint32_T;
          }

          sf_simulink_B->object[i] = sf_simulink_DW->each_object;
          relative_velovity = c;
          sf_simulink_up_count(&relative_velovity, 10.0);
          if (relative_velovity < 128.0) {
            if (relative_velovity >= -128.0) {
              c = (int8_T)relative_velovity;
            } else {
              c = MIN_int8_T;
            }
          } else {
            c = MAX_int8_T;
          }

          relative_velovity = l;
          sf_simulink_up_count(&relative_velovity, 10.0);
          if (relative_velovity < 128.0) {
            if (relative_velovity >= -128.0) {
              l = (int8_T)relative_velovity;
            } else {
              l = MIN_int8_T;
            }
          } else {
            l = MAX_int8_T;
          }
        } else {
          if ((local_angle_cam[c] < (real_T)i - sf_simulink_DIFF_ANGLE) &&
              (local_angle_cam[c] >= 0.0)) {
            relative_velovity = c;
            sf_simulink_up_count(&relative_velovity, 10.0);
            if (relative_velovity < 128.0) {
              if (relative_velovity >= -128.0) {
                c = (int8_T)relative_velovity;
              } else {
                c = MIN_int8_T;
              }
            } else {
              c = MAX_int8_T;
            }
          }

          if ((local_angle_lidar[l] < (real_T)i - sf_simulink_DIFF_ANGLE) &&
              (local_angle_lidar[l] >= 0.0)) {
            relative_velovity = l;
            sf_simulink_up_count(&relative_velovity, 10.0);
            if (relative_velovity < 128.0) {
              if (relative_velovity >= -128.0) {
                l = (int8_T)relative_velovity;
              } else {
                l = MIN_int8_T;
              }
            } else {
              l = MAX_int8_T;
            }
          }

          guard1 = true;
        }
      }

      if (guard1) {
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
      sf_simulink_time_reprocessing(sf_simulink_DW);
      if (sf_simulink_DW->dt <= 2.0) {
        if (sf_simulink_DW->change_lane_dir == 1) {
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
            (sf_simulink_nonzero_front(sf_simulink_B->object) != 0.0)) {
          save_dist = sf_simulink_DW->each_obj.dist;
          relative_velovity = sf_simulink_front_ele(sf_simulink_B->object);
          if (relative_velovity < 2.147483648E+9) {
            if (relative_velovity >= -2.147483648E+9) {
              i_0 = (int32_T)relative_velovity;
            } else {
              i_0 = MIN_int32_T;
            }
          } else {
            i_0 = MAX_int32_T;
          }

          sf_simulink_DW->each_obj = sf_simulink_B->object[i_0];
          sf_simul_check_signal_violation(&BusConversion_InsertedFor_cruse,
            sf_simulink_B, sf_simulink_DW);
          sf_simulink_time_reprocessing(sf_simulink_DW);
          relative_velovity = ((real_T)sf_simulink_DW->each_obj.dist - (real_T)
                               save_dist) / sf_simulink_DW->dt;

          /*  speed unit and relative_velovity unit is centimeters per seconds  */
          sf_simulink_B->front_car_speed = (real_T)sf_simulink_B->speed +
            relative_velovity;
          sf_simulink_check_speeding(sf_simulink_B);

          /*  the front car is getting closer
             If the front car is already close, can't change lane  */
          if ((relative_velovity < 0.0) && (sf_simulink_DW->each_obj.dist > 100U))
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
              guard2 = true;
            } else {
              sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
            }
          }
        } else {
          /*  undiscover the car in front  */
          /*  signal light color isn't yellow or red  */
          if (sf_simulink_U->Input.sig_flag == 0) {
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
          (sf_simulink_nonzero_front(sf_simulink_B->object) != 0.0)) {
        save_dist = sf_simulink_DW->each_obj.dist;
        relative_velovity = sf_simulink_front_ele(sf_simulink_B->object);
        if (relative_velovity < 2.147483648E+9) {
          if (relative_velovity >= -2.147483648E+9) {
            i_0 = (int32_T)relative_velovity;
          } else {
            i_0 = MIN_int32_T;
          }
        } else {
          i_0 = MAX_int32_T;
        }

        sf_simulink_DW->each_obj = sf_simulink_B->object[i_0];
        sf_simul_check_signal_violation(&BusConversion_InsertedFor_cruse,
          sf_simulink_B, sf_simulink_DW);
        sf_simulink_time_reprocessing(sf_simulink_DW);
        relative_velovity = ((real_T)sf_simulink_DW->each_obj.dist - (real_T)
                             save_dist) / sf_simulink_DW->dt;

        /*  speed unit and relative_velovity unit is centimeters per seconds  */
        sf_simulink_B->front_car_speed = (real_T)sf_simulink_B->speed +
          relative_velovity;
        sf_simulink_check_speeding(sf_simulink_B);

        /*  the front car is getting closer
           If the front car is already close, can't change lane  */
        if ((relative_velovity < 0.0) && (sf_simulink_DW->each_obj.dist > 100U))
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
        if (sf_simulink_U->Input.sig_flag == 0) {
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

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

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
