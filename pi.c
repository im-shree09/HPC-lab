#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 1000000000

double calculatePi(int n) {
    double sum = 0.0;
    double step = 1.0 / n;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    return step * sum;
}

int main() {
    clock_t start, end;
    start= clock();
    double pi;
    int num_threads[] = {1, 2, 4, 8};

    for (int i = 0; i < 4; i++) {
        omp_set_num_threads(num_threads[i]);

        double start_time = omp_get_wtime();
        pi = calculatePi(N);
        double end_time = omp_get_wtime();

        printf("Threads: %d | Pi: %.15f | Time taken: %f seconds\n",
               num_threads[i], pi, end_time - start_time);
    }

    end = clock();
    double duration= ((double)end-start)/ CLOCKS_PER_SEC;
    printf("\n Time Taken: %f", duration);
    return 0;
}