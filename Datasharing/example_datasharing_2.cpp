// ** 檔名 example_datasharing_2.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main()
{

    int var = 10;

    printf("\nvar : firstprivate variable\n");
#pragma omp parallel firstprivate(var)
    {
        const int thread_id = omp_get_thread_num();
        var += 1;
        printf("var : %d | computed by thread : %d\n", var, thread_id);
    }

    return 0;
}
