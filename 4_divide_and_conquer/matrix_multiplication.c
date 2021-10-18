#include <math.h>
#include <stdio.h>

#include "matrix_multiplication.h"

void print_matrix(Matrix A) {
    int n_rows = A.rows;

    for (int i = 0; i < n_rows; ++i) {
        printf("| ");
        for (int j = 0; j < n_rows; ++j) {
            printf("%3.2f ", A.data[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}


Matrix square_matrix_multiply(Matrix A, Matrix B) {
    int n_rows = A.rows;
    float current_c;
    Matrix C;

    C.rows = n_rows;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_rows; ++j) {
            current_c = 0;
            for (int k = 0; k < n_rows; ++k) {
                current_c += A.data[i][k] * B.data[k][j];
            }

            C.data[i][j] = current_c;
        }
    }

    return C;
}

void partition_matrices(
    Matrix A,
    Matrix *A11,
    Matrix *A12,
    Matrix *A21,
    Matrix *A22
) {
    int n_rows = A.rows;
    int pivot = floor(n_rows / 2.);

    // Upper-left
    A11->rows = pivot;
    for (int i = 0; i < pivot; ++i) {
        for (int j = 0; j < pivot; ++j) {
            A11->data[i][j] = A.data[i][j];
        }
    }

    // Upper-right
    A12->rows = pivot;
    for (int i = 0; i < pivot; ++i) {
        for (int j = pivot; j < n_rows; ++j) {
            A12->data[i][j - pivot] = A.data[i][j];
        }
    }

    // Lower-left
    A21->rows = pivot;
    for (int i = pivot; i < n_rows; ++i) {
        for (int j = 0; j < pivot; ++j) {
            A21->data[i - pivot][j] = A.data[i][j];
        }
    }

    // Lower-right
    A22->rows = pivot;
    for (int i = pivot; i < n_rows; ++i) {
        for (int j = pivot; j < n_rows; ++j) {
            A22->data[i - pivot][j - pivot] = A.data[i][j];
        }
    }
}

void gather_matrices(
    Matrix C11,
    Matrix C12,
    Matrix C21,
    Matrix C22,
    Matrix *C
) {
    int pivot = C11.rows;
    int n_rows = pivot + C21.rows;

    C->rows = n_rows;

    for (int i = 0; i < pivot; ++i) {
        for (int j = 0; j < pivot; ++j) {
            C->data[i][j] = C11.data[i][j];
        }
    }

    // Upper-right
    for (int i = 0; i < pivot; ++i) {
        for (int j = pivot; j < n_rows; ++j) {
            C->data[i][j] = C12.data[i][j - pivot];
        }
    }

    // Lower-left
    for (int i = pivot; i < n_rows; ++i) {
        for (int j = 0; j < pivot; ++j) {
            C->data[i][j] = C21.data[i - pivot][j];
        }
    }

    // Lower-right
    for (int i = pivot; i < n_rows; ++i) {
        for (int j = pivot; j < n_rows; ++j) {
            C->data[i][j] = C22.data[i - pivot][j - pivot];
        }
    }

}

Matrix add_matrices(Matrix A, Matrix B) {
    int n_rows = A.rows;
    Matrix C;

    C.rows = n_rows;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_rows; ++j) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }

    return C;
}

Matrix subtract_matrices(Matrix A, Matrix B) {
    int n_rows = A.rows;
    Matrix C;

    C.rows = n_rows;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_rows; ++j) {
            C.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }

    return C;
}


Matrix square_matrix_multiply_strassen(Matrix A, Matrix B) {
    int n_rows = A.rows;
    Matrix C;
    Matrix A11, A12, A21, A22, B11, B12, B21, B22;
    Matrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
    Matrix P1, P2, P3, P4, P5, P6, P7;
    Matrix C11, C12, C21, C22;

    if (n_rows == 1) {
        C.rows = 1;
        C.data[0][0] = A.data[0][0] * B.data[0][0];
    } else {
        partition_matrices(A, &A11, &A12, &A21, &A22);
        partition_matrices(B, &B11, &B12, &B21, &B22);

        S1 = subtract_matrices(B12, B22);
        S2 = add_matrices(A11, A12);
        S3 = add_matrices(A21, A22);
        S4 = subtract_matrices(B21, B11);
        S5 = add_matrices(A11, A22);
        S6 = add_matrices(B11, B22);
        S7 = subtract_matrices(A12, A22);
        S8 = add_matrices(B21, B22);
        S9 = subtract_matrices(A11, A21);
        S10 = add_matrices(B11, B12);

        P1 = square_matrix_multiply_strassen(A11, S1);
        P2 = square_matrix_multiply_strassen(S2, B22);
        P3 = square_matrix_multiply_strassen(S3, B11);
        P4 = square_matrix_multiply_strassen(A22, S4);
        P5 = square_matrix_multiply_strassen(S5, S6);
        P6 = square_matrix_multiply_strassen(S7, S8);
        P7 = square_matrix_multiply_strassen(S9, S10);


        C11 = add_matrices(subtract_matrices(add_matrices(P5, P4), P2), P6);
        C12 = add_matrices(P1, P2);
        C21 = add_matrices(P3, P4);
        C22 = subtract_matrices(subtract_matrices(add_matrices(P5, P1), P3), P7);

        gather_matrices(C11, C12, C21, C22, &C);
    }

    return C;
}
