// ** 檔名 example_basic_2.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
#pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        printf("Hi, I am thread number %d\n", ID);
    }

    omp_set_num_threads(3);
#pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("Hello, I am thread number %d\n", ID);
    }
    return 0;
}
