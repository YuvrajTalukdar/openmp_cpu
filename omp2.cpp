#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    #pragma omp parallel 
    {
        int numt=omp_get_num_threads();
        int tid=omp_get_thread_num();
        cout<<"\nhello world from thread "<<tid<<" num: "<<numt;
    }
    return 0;
}