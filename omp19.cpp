#include <omp.h>
#include <stdio.h>

int main()
{
    #pragma omp parallel for collapse(2) num_threads(16)
    for (int i=0;i<4;i++)
    { 
        for (int j=0;j<4;j++)
        {
            printf("Called from thread %d \n",omp_get_thread_num());
        }
    }
}