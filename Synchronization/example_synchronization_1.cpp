// ** 檔名 example_synchronization_1.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main()
{
    printf("Case 1, without barrier:\n");
#pragma omp parallel num_threads(2)
    {

        const int thread_id = omp_get_thread_num();
        // Case 1, without barrier
        printf("A1 I am thread %d\n", thread_id);
        printf("A2 I am thread %d\n", thread_id);
        printf("B I am thread %d\n", thread_id);
    }

    printf("\n=======================\n\n");
    printf("Case 2, with barrier:\n");
#pragma omp parallel num_threads(2)
    {
        const int thread_id = omp_get_thread_num();
        // Case 2, with barrier
        printf("A1 I am thread %d\n", thread_id);
        printf("A2 I am thread %d\n", thread_id);
#pragma omp barrier
        printf("B I am thread %d\n", thread_id);
    }

    return 0;
}