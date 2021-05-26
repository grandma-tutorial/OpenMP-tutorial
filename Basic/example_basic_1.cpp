// ** 檔名 example_basic_1.cpp **

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
