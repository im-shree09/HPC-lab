#include<stdio.h>
#include<omp.h>

void printMes(){
    int tn;
    tn = omp_get_thread_num();
    printf("\nHello there from %d \n", tn);
}

int main()
{
    #pragma omp parallel num_threads(10)
    printMes();
    return 0;
}