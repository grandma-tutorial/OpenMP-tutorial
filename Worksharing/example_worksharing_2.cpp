// ** 檔名 example_worksharing_2.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main()
{
    const int N = 8;
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8};
#pragma omp parallel
    {
        const int thread_id = omp_get_thread_num();

// parallel computing for A[i] = A[i] + 1
#pragma omp sections
        {
// section 1
#pragma omp section
            {
                for (int i = 0; i < N / 2; i++)
                {
                    A[i] = A[i] + 1;
                    printf("A[%d] is computed by thread number : %d\n", i, thread_id);
                }
            }

// section 2
#pragma omp section
            {
                for (int i = N / 2; i < N; i++)
                {
                    A[i] = A[i] + 1;
                    printf("A[%d] is computed by thread number : %d\n", i, thread_id);
                }
            }
        }
    }

    // print the array after parallel computing
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
    return 0;
}