#include<iostream>
#include<omp.h>
#include<unistd.h>//for sleep

using namespace std;

int main()
{
    #pragma omp parallel
    {
        #pragma omp single//if we dont use single than multiple both the tasks will be executed using n threads. n being the default no od threads set in omp environment. If you want such behaviour than just comment it out.
        {
            #pragma omp task
            {
                cout<<"\nfrom task 1 tid: "<<omp_get_thread_num();
                sleep(1);
            }
            #pragma omp task
            {
                cout<<"\nfrom task 2 tid: "<<omp_get_thread_num();
                sleep(1);
            }
            cout<<"\nthread "<<omp_get_thread_num()<<" exited";
        }
    }
    cout<<"\n\nsection testing";
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            cout<<"\nfrom section 1 tid: "<<omp_get_thread_num();
            sleep(1);
        }
        #pragma omp section
        {
            cout<<"\nfrom section 2 tid: "<<omp_get_thread_num();
            sleep(1);
        }
        cout<<"\nthread "<<omp_get_thread_num()<<" exited\n\n";
    }

    return 0;
}