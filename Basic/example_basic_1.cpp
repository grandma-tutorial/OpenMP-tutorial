// ** 檔名 example_basic_1.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{

    printf("Hello, world (Master)\n");

#pragma omp parallel
    {
        printf("Hi! (Multithreading)\n");
    }

    return 0;
}
