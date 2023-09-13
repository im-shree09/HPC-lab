// #include <stdio.h>
// #include <omp.h>

// #define N 5  // Size of matrices

// void sumLowerTriangularMatrices(int A[][N], int B[][N], int result[][N]) {
//     #pragma omp parallel for
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j <= i; j++) {
//             result[i][j] = A[i][j] + B[i][j];
//         }
//     }
// }

// int main() {
//     int matrixA[N][N] = {
//         {1, 0, 0, 0, 0},
//         {2, 3, 0, 0, 0},
//         {4, 5, 6, 0, 0},
//         {7, 8, 9, 10, 0},
//         {11, 12, 13, 14, 15}
//     };
    
//     int matrixB[N][N] = {
//         {5, 0, 0, 0, 0},
//         {4, 6, 0, 0, 0},
//         {3, 2, 1, 0, 0},
//         {8, 7, 6, 5, 0},
//         {9, 10, 11, 12, 13}
//     };
    
//     int result[N][N];

//     double start_time = omp_get_wtime();

//     sumLowerTriangularMatrices(matrixA, matrixB, result);

//     double end_time = omp_get_wtime();
//     double elapsed_time = end_time - start_time;

//     printf("Matrix A:\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", matrixA[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nMatrix B:\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", matrixB[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nResult Matrix:\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j <= i; j++) {  // Corrected loop limit
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nTime taken: %f seconds\n", elapsed_time);

//     return 0;
// }


#include <stdio.h>
#include <omp.h>

#define N 5  // Size of matrices

void sumLowerTriangularMatrices(int A[][N], int B[][N], int result[][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    // int matrixA[N][N] = {
    //     {1, 0, 0, 0},
    //     {2, 3, 0, 0},
    //     {4, 5, 6, 0},
    //     {7, 8, 9, 10}
    // };
    
    // int matrixB[N][N] = {
    //     {5, 0, 0, 0},
    //     {4, 6, 0, 0},
    //     {3, 2, 1, 0},
    //     {8, 7, 6, 5}
    // };
    int matrixA[N][N] = {
        {1, 0, 0, 0, 0},
        {2, 3, 0, 0, 0},
        {4, 5, 6, 0, 0},
        {7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15}
    };
    
    int matrixB[N][N] = {
        {5, 0, 0, 0, 0},
        {4, 6, 0, 0, 0},
        {3, 2, 1, 0, 0},
        {8, 7, 6, 5, 0},
        {9, 10, 11, 12, 13}
    };
    
    int result[N][N];

    double start_time = omp_get_wtime();

    sumLowerTriangularMatrices(matrixA, matrixB, result);

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
            if (j <= i) {
                printf("%d ", result[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("\nTime taken: %f seconds\n", elapsed_time);

    return 0;
}
