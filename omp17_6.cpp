#include<omp.h>
#include<unistd.h>
#include<iostream>

using namespace std;

int main() 
{
    #pragma omp parallel //num_threads(1)
    {
        #pragma omp single
        {
            cout<<"\ntask 1 created";
            #pragma omp task
            {
                sleep(1);
                cout<<"\n\nTask 1 execution complete tid: "<<omp_get_thread_num();
            }
            cout<<"\ntask 2 created";
            #pragma omp task
            {
                sleep(1);
                cout<<"\nTask 2 execution complete tid: "<<omp_get_thread_num();
            }

            #pragma omp taskwait
            //#pragma omp barrier
            cout<<"\nTaskwait completed\n";
        }
    }
    return 0;
}
