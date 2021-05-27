// ** 檔名 example_worksharing_3.cpp **

#include <stdio.h>
#include <omp.h>

int main()
{

#pragma omp parallel
    {
        const int thread_id = omp_get_thread_num();

        printf("**Outside** single section, I am thread number %d\n", thread_id);

#pragma omp single
        {
            printf("!!Inside!!  single section, I am thread number %d\n", thread_id);
        }
    }
    return 0;
}