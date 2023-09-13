// #include <stdio.h>
// #include <omp.h>

// int fib(int n)

// {
//     int f[n + 2];
//     int i;
// #pragma omp task
//     {
//         f[0] = 0;
//         f[1] = 1;
//     }
// #pragma omp task
//     {
//         for (i = 2; i <= n; i++)
//         {
//             f[i] = f[i - 1] + f[i - 2];
//         }
//     }
// #pragma omp taskwait
//     {
//         return f[n];
//     }
// }

// int main()

// {
//     int n = 10;
// #pragma omp parallel
//     {
//         printf("%d", fib(n));
//     }
//     getchar();
//     return 0;
// }

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int i, j;
    if (n < 2)
        return n;
    else
    {
#pragma omp task shared(i)
        i = fibonacci(n - 1);
#pragma omp task shared(j)
        j = fibonacci(n - 2);

#pragma omp taskwait
        return i + j;
    }
}

int main(int argc, char **argv)
{
    // char *a = argv[1];
    char *a = argv[1];
    int n = atoi(a), result;
#pragma omp parallel
    {
#pragma omp single

        result = fibonacci(n);
    }
    printf("Result is %d\n", result);
}