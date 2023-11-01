#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    #pragma omp parallel num_threads(4)
    {
        int tid=omp_get_thread_num();
        cout<<"\nhello world from thread "<<tid;
        #pragma omp barrier//comment this out and check the results and effects of barrier line
        if(tid==0)
        {
            int numt=omp_get_num_threads();
            cout<<"\nno of threads launched: "<<numt;
        }
    }
    return 0;
}