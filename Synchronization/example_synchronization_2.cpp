// ** 檔名 example_synchronization_2.cpp **
// 都會阿嬤 OpenMP 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <omp.h>

int main()
{
    // Case 1, without critical
    int number = 0;
#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (int i = 0; i < 10000; i++)
        {
            number++;
        }

#pragma omp single                                               // just print once
        printf("Without critical, the number is :%d\n", number); // wrong because of data race
    }

    // Case 2, with critical
    number = 0;
#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (int i = 0; i < 10000; i++)
        {
#pragma omp critical
            {
                number++;
            }
        }

#pragma omp single                                               // just print once
        printf("With critical,    the number is :%d\n", number); // correct because of data race
    }

    return 0;
}