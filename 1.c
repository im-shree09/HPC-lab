#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
int tmp;
void main() {
tmp = 10;
#pragma omp parallel firstprivate(tmp)
// work();
printf("%d\n", tmp);
}