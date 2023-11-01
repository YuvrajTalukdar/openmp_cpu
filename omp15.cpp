#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        #pragma omp single
        cout<<"\none tid: "<<omp_get_thread_num();
        #pragma omp master
        cout<<"\ntwo uid: "<<omp_get_thread_num();
        #pragma omp single// nowait
        cout<<"\nthree tid: "<<omp_get_thread_num();
        cout<<"\nfour tid: "<<omp_get_thread_num();
    }
    cout<<"\n\n";
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (int i = 0; i < 2; i++) {
            cout<<"\nfor loop 1 tid: "<<omp_get_thread_num();
        }
        cout<<"\nnowait Hello World";
        #pragma omp for
        for (int i = 0; i < 2; i++) {
            cout<<"\nfor loop 2 tid: "<<omp_get_thread_num();
        }
        cout<<"\nHello World";
    }
    
    return 0;
}