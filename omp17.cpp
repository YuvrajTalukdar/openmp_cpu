#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                cout<<"\nfrom task 1 tid: "<<omp_get_thread_num();
            }
            #pragma omp task
            {
                cout<<"\nfrom task 2 tid: "<<omp_get_thread_num();
            }
        }
    }

    return 0;
}