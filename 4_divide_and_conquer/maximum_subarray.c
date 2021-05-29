#include <limits.h>
#include <math.h>

#include "maximum_subarray.h"

void find_max_crossing_subarray(
        int array[],
        int low,
        int mid,
        int high,
        int *max_left_idx,
        int *max_right_idx,
        int *max_sum
);

void maximum_subarray_brute_force(
    int array[],
    int size,
    int *left_idx,
    int *right_idx,
    int *max_sum
) {
    int start_idx, end_idx, current_sum;

    *max_sum = INT_MIN;
    *left_idx = 0;
    *right_idx = 0;

    for (start_idx = 0; start_idx < size; ++start_idx) {
        current_sum = 0;
        for (end_idx = start_idx; end_idx < size; ++end_idx) {\
            current_sum += array[end_idx];

            if (current_sum > *max_sum) {
                *max_sum = current_sum;
                *left_idx = start_idx;
                *right_idx = end_idx;
            }
        }
    }
}

void maximum_subarray_divide_and_conquer(
        int array[],
        int low,
        int high,
        int *left_idx,
        int *right_idx,
        int *max_sum
) {
    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;
    int mid;

    if (low == high) {
        *max_sum = array[low];
        *left_idx = low;
        *right_idx = high;
    }
    else {
        mid = floor((low + high) / 2.);

        maximum_subarray_divide_and_conquer(
            array, low, mid, &left_low, &left_high, &left_sum
        );
        maximum_subarray_divide_and_conquer(
            array, mid + 1, high, &right_low, &right_high, &right_sum
        );
        find_max_crossing_subarray(
            array, low, mid, high, &cross_low, &cross_high, &cross_sum
        );

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            *max_sum = left_sum;
            *left_idx = left_low;
            *right_idx = left_high;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum) {
            *max_sum = right_sum;
            *left_idx = right_low;
            *right_idx = right_high;
        }
        else {
            *max_sum = cross_sum;
            *left_idx = cross_low;
            *right_idx = cross_high;
        }
    }
}

void maximum_subarray_linear(
        int array[],
        int size,
        int *max_sub_left_idx,
        int *max_sub_right_idx,
        int *max_sub_sum
) {
    int border_sub_left_idx = 1;
    int border_sub_sum = INT_MIN;
    int right_idx;

    *max_sub_left_idx = 0;
    *max_sub_right_idx = 0;
    *max_sub_sum = INT_MIN;

    for (right_idx = 0; right_idx < size; ++right_idx) {
        if (border_sub_sum >= 0) {
            border_sub_sum += array[right_idx];
        }
        else {
            border_sub_sum = array[right_idx];
            border_sub_left_idx = right_idx;
        }

        if (border_sub_sum > *max_sub_sum) {
            *max_sub_sum = border_sub_sum;
            *max_sub_left_idx = border_sub_left_idx;
            *max_sub_right_idx = right_idx;
        }
    }
}

void find_max_crossing_subarray(
    int array[],
    int low,
    int mid,
    int high,
    int *max_left_idx,
    int *max_right_idx,
    int *max_sum
) {
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    int i, j;

    for (i = mid; i >= low; --i) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            *max_left_idx = i;
        }
    }

    sum = 0;
    for (j = mid + 1; j <= high; ++j) {
        sum += array[j];
        if (sum > right_sum) {
            right_sum = sum;
            *max_right_idx = j;
        }
    }

    *max_sum = left_sum + right_sum;
}
