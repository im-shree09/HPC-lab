#include <stdio.h>
#include <omp.h>
#include <time.h>
void vectorScalarAdd(int* vector, int scalar, int size) {
    #pragma omp parallel for firstprivate(scalar)
    for (int i = 0; i < size; i++) {
        scalar = scalar + i;
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
