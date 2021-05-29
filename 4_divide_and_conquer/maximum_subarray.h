#ifndef INC_4_DIVIDE_AND_CONQUER_MAXIMUM_SUBARRAY_H
#define INC_4_DIVIDE_AND_CONQUER_MAXIMUM_SUBARRAY_H

void maximum_subarray_brute_force(
    int array[],
    int size,
    int *left_idx,
    int *right_idx,
    int *max_sum
);

void maximum_subarray_divide_and_conquer(
    int array[],
    int low,
    int high,
    int *left_idx,
    int *right_idx,
    int *max_sum
);

void maximum_subarray_linear(
    int array[],
    int size,
    int *left_idx,
    int *right_idx,
    int *max_sum
);

#endif //INC_4_DIVIDE_AND_CONQUER_MAXIMUM_SUBARRAY_H
