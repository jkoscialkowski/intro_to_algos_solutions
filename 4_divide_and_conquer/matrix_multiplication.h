#ifndef INC_4_DIVIDE_AND_CONQUER_MATRIX_MULTIPLICATION_H
#define INC_4_DIVIDE_AND_CONQUER_MATRIX_MULTIPLICATION_H

typedef struct Matrices {
    float data[128][128];
    int rows;
} Matrix;

void print_matrix(Matrix A);
Matrix square_matrix_multiply(Matrix A, Matrix B);
Matrix square_matrix_multiply_strassen(Matrix A, Matrix B);

#endif //INC_4_DIVIDE_AND_CONQUER_MATRIX_MULTIPLICATION_H
