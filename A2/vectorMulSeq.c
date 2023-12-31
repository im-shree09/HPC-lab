#include <omp.h>
#include <pthread.h>
#include <stdio.h>

int main()
{
    int N = 500;
    int A[1000];
    for (int i = 0; i < N; i++)
        A[i] = 20;
    int S = 2;

    double itime;
    itime = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {

        A[i] *= S;
        printf("Index: %d Thread: %d\n", i,omp_get_thread_num());
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    double ftime = omp_get_wtime();
    double exec_time = ftime - itime;
    printf("\nTime taken is %f\n", exec_time);
    printf("\n");
}