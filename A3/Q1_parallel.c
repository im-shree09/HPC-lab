// // #include <omp.h>
// // #include <stdio.h>
// // #include <stdlib.h>
// // void swap(int *num1, int *num2)
// // {
// //     int temp = *num1;
// //     *num1 = *num2;
// //     *num2 = temp;
// // }
// // int sort(int arr[], int n)
// // {
// //     int i, j;
// //     for (i = 0; i < n - 1; i++)
// //     {
// // #pragma omp parallel for default(none), shared(arr, n, i)
// //         for (j = 0; j < n - i - 1; j++)
// //         {
// //             if (arr[j] > arr[j + 1])
// //             {
// //                 int temp = arr[j];
// //                 arr[j] = arr[j + 1];
// //                 arr[j + 1] = temp;
// //             }
// //         }
// //     }
// // }
// // int dec_sort(int arr[], int n)
// // {
// //     int i, j;
// //     for (i = 0; i < n; i++)
// //     {
// // #pragma omp parallel for default(none), shared(arr, n, i)
// //         for (j = i + 1; j < n; ++j)
// //         {
// //             printf("Thread:%d\n", omp_get_thread_num());
// //             if (arr[i] < arr[j])
// //             {
// //                 int a = arr[i];
// //                 arr[i] = arr[j];
// //                 arr[j] = a;
// //             }
// //         }
// //     }
// // }
// // int main(int argc, char *argv[])
// // {
// //     int SIZE = 5;
// //     int arr1[5] = {2, 1, 4, 6, 3};
// //     int arr2[5] = {2, 1, 5, 4, 3};
// //     int n = SIZE;
// //     int i = 0, j = 0;
// //     int first;
// //     double start, end;
// //     start = omp_get_wtime();
// //     sort(arr1, n);
// //     dec_sort(arr2, n);
// //     int sum = 0;
// //     for (i = 0; i < n; i++)
// //     {
// //         sum = sum + (arr1[i] * arr2[i]);
// //     }
// //     printf("\nMinimum scalar product is: ");
// //     printf("%d", sum);
// //     end = omp_get_wtime();
// //     printf("\nTime Parallel= %f", (end - start));
// // }

// #include <omp.h>
// #include <pthread.h>
// #include <stdio.h>

// int main()
// {
//     int N = 1000;
//     int A[1000];
//     for (int i = 0; i < N; i++)
//         A[i] = 10;

//     int B[1000];
//     for (int i = 0; i < N; i++)
//         B[i] = 20;

//     int C[1000] = {0};
//     double stime = omp_get_wtime();
//     for (int i = 0; i < N; i++)
//     {
//         C[i] = A[i] + B[i];
//         printf("Index: %d Thread: %d\n", i,
//         omp_get_thread_num());
//     }

//     for (int i = 0; i < N; i++)
//     {
//         printf("%d ", C[i]);
//     }

//     double etime = omp_get_wtime();
//     double time = etime - stime;
//     printf("Time taken is %f\n", time);
//     return 0;
// }

// C Program to find the minimum scalar product of two
// vectors(dot product) 2020btecs00029
#include <omp.h>
#include <stdio.h>
#include <time.h>
#define n 100000
void sort(int nums[])
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    int turn = i % 2;
#pragma omp parallel for


    for (j = turn; j < n - 1; j += 2)
      if (nums[j] > nums[j + 1])
      {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
  }
}
void sort_des(int nums[])
{
  int i, j;
  for (i = 0; i < n; ++i)
  {
    int turn = i % 2;
#pragma omp parallel for


    for (j = turn; j < n - 1; j += 2)
    {
      if (nums[j] < nums[j + 1])
      {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}




int main()
{
  int nums1[n], nums2[n];
  for (int i = 0; i < n; i++)
  {
    nums1[i] = 10;
  }
  for (int i = 0; i < n; i++)
  {
    nums2[i] = 20;
  }
  clock_t t;
  t = clock();
  sort(nums1);
  sort_des(nums2);
  t = clock() - t;


  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("Time taken (seq): %f\n", time_taken);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + (nums1[i] * nums2[i]);
  }
  printf("%d\n", sum);
  return 0;
}
