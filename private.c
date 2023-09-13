// #include <stdio.h>
// #include <omp.h>

// void vectorScalarAdd(int* vector, int scalar, int size) {
//     #pragma omp parallel for
//     for (int i = 0; i < size; i++) {
//         vector[i] += scalar;
//     }
// }

// int main() {
//     int size = 10;
//     int vector[size];
//     int scalar = 5;

//     // Initialize the vector
//     for (int i = 0; i < size; i++) {
//         vector[i] = i;
//     }

//     printf("Original Vector:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", vector[i]);
//     }
//     printf("\n");

//     // Perform vector scalar addition
//     vectorScalarAdd(vector, scalar, size);

//     printf("Vector after Scalar Addition:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", vector[i]);
//     }
//     printf("\n");

//     return 0;
// }


#include <stdio.h>
#include <omp.h>
#include <time.h>

void vectorScalarAdd(int* vector, int scalar, int size) {
    #pragma omp parallel for private(scalar)
    for (int i = 0; i < size; i++) {
        scalar = i + 1; 
        vector[i] += scalar;
    }
}

int main() {
    clock_t start, end;
    start= clock();
    int size = 100;
    int vector[size];

    for (int i = 0; i < size; i++) {
        vector[i] = i;
    }

    printf("Original Vector:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    vectorScalarAdd(vector, 5, size);

    printf("Vector after Scalar Addition:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    end = clock();
    double duration= ((double)end-start)/ CLOCKS_PER_SEC;
    printf("\n Time Taken: %f", duration);
    return 0;
}
