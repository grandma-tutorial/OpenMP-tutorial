// ** 檔名 example_synchronization_3.cpp **
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

#pragma omp for ordered
        for (int i = 0; i < N; i++)
        {
#pragma omp ordered
            {
                A[i] = A[i] + 1;
                printf("A[%d] is computed by thread : %d\n", i, thread_id);
            }
        }
    }
    return 0;
}