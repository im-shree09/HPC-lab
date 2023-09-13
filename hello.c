#include<omp.h>
#include<stdio.h>
// gcc -fopenmp hello.c 
// ./a.exe

// int *argc, char* argv[]
int main()
{
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        printf("Hello shree!\n");
    }
}