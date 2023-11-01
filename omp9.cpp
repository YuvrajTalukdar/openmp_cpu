#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    int x = 0,y=0;

    #pragma omp parallel sections
    {
        //cout<<"\nparallelized with "<<omp_get_num_threads()<<" threads";
        #pragma omp section 
        {
            ++x;
            cout<<"\nthread_id for first section: "<<omp_get_thread_num();
        }
        #pragma omp section 
        {
            --y;
            cout<<"\nthread_id for second section: "<<omp_get_thread_num();
        }
    }
    cout<<"\nx: "<<x<<" y: "<<y;
    return x;
}
/*
The idea of parallel sections is to give the compiler a hint that the various (inner) sections can be performed in parallel, for example:

This is a hint to the compiler and not guaranteed to happen, though it should. Your output is kind of what is expected; it says that there are #sections being executed in thread id 1, and in thread 2. The output order is non-deterministic as you don't know what thread will run first.
*/