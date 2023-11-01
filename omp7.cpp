#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    int shared1=0;
    int n=0,a=5,b=1;
    //firstprivate initialized the variable with the last value it had before the pragma statement
    //lastprivate transfers values from the parallel region to the outside context. 
    #pragma omp parallel num_threads(4) private(n) firstprivate(a) /*lastprivate(b)*///comment out private and see the problem it creates
    {
        #pragma omp critical//critical had to be declared for the shared1, so that incrementation works properly
        {
            shared1++;
            cout<<"\nshared1: "<<shared1;
        }
        int tid=omp_get_thread_num();//private
        cout<<"\nhello world from thread "<<tid;
        n=omp_get_thread_num();
        #pragma omp barrier//comment this out and check the results and effects of barrier line
        cout<<"\nn: "<<n;
        if(tid==0)
        {
            int numt=omp_get_num_threads();
            cout<<"\nno of threads launched: "<<numt;
        }
        a++;
        cout<<"\na "<<a;
        b=5;
    }
    cout<<"\nb: "<<b;
    cout<<"\na: "<<a;
    cout<<"\nn: "<<n;
    return 0;
}