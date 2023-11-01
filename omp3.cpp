#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        int numt=omp_get_num_threads();
        int tid=omp_get_thread_num();
        cout<<"\nhello world 1 from thread "<<tid<<" num: "<<numt;
    }
    #pragma omp parallel num_threads(4 )
    {
        int numt=omp_get_num_threads();
        int tid=omp_get_thread_num();
        cout<<"\nhello world 2 from thread "<<tid<<" num: "<<numt;
    }
    return 0;
}