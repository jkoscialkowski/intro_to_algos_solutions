#include <stdio.h>

#include "maximum_subarray.h"
#include "matrix_multiplication.h"

void maximum_subarray_demo();
void matrix_multiplication_demo1();
void matrix_multiplication_demo2();

int main() {
    maximum_subarray_demo();
    printf("\n\n\n");
    matrix_multiplication_demo1();
    printf("\n\n\n");
    matrix_multiplication_demo2();

    return 0;
}

void maximum_subarray_demo() {
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
}

void matrix_multiplication_demo1() {
    const Matrix matrix1 = {{{1, 3}, {7, 5}}, 2};
    const Matrix matrix2 = {{{6, 8}, {4, 2}}, 2};

    print_matrix(square_matrix_multiply_strassen(matrix1, matrix2));
}

void matrix_multiplication_demo2() {
    const Matrix matrix1 = {{{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}}, 4};
    const Matrix matrix2 = {{{0, 1, 0, 1}, {2, 0, 2, 0}, {1, 2, 3, 4}, {4, 3, 2, 1}}, 4};

    print_matrix(matrix1);
    print_matrix(matrix2);
    printf("\n");
    print_matrix(square_matrix_multiply(matrix1, matrix2));
    printf("\n");
    print_matrix(square_matrix_multiply_strassen(matrix1, matrix2));
}