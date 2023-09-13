#include <stdio.h>
#include <omp.h>

#define N 4  // Size of matrices

void matrixMultiplication(int A[][N], int B[][N], int result[][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matrixA[N][N] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };
    
    int matrixB[N][N] = {
        {5, 0, 0, 0},
        {4, 6, 0, 0},
        {3, 2, 1, 0},
        {8, 7, 6, 5}
    };
    // int matrixA[N][N] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    
    // int matrixB[N][N] = {
    //     {9, 8, 7},
    //     {6, 5, 4},
    //     {3, 2, 1}
    // };
    
    int result[N][N];

    omp_set_num_threads(100);
    double start_time = omp_get_wtime();

    matrixMultiplication(matrixA, matrixB, result);

    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("\nResult Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken: %f seconds\n", elapsed_time);

    return 0;
}
