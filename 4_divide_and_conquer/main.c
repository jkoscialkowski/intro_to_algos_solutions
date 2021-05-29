#include <stdio.h>

#include "maximum_subarray.h"

int main() {
    const int array[17] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int left_idx, right_idx, max_sum;

    maximum_subarray_brute_force(
        array, 17, &left_idx, &right_idx, &max_sum
    );
    printf("Brute force: (%d, %d, %d)", left_idx, right_idx, max_sum);
    printf("\n");

    maximum_subarray_divide_and_conquer(
        array, 0, 16, &left_idx, &right_idx, &max_sum
    );
    printf(
        "Divide and conquer: (%d, %d, %d)",
        left_idx, right_idx, max_sum
    );
    printf("\n");

    maximum_subarray_linear(array, 17, &left_idx, &right_idx, &max_sum);
    printf("Linear: (%d, %d, %d)", left_idx, right_idx, max_sum);
    printf("\n");

    return 0;
}