#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int sum1=0,sum2=0;
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskgroup
            {   //both task will run in parallel
                #pragma omp task
                {
                    cout<<"\nrunning task 1 with thread id: "<<omp_get_thread_num();
                    for(int a=0;a<100;a++)
                    {   sum1+=a;}
                }
                #pragma omp task
                {
                    cout<<"\nrunning task 2 with thread id: "<<omp_get_thread_num();
                    for(int a=0;a<100;a++)
                    {   sum2+=a;}
                }
                cout<<"\nReached end of taskgroup tid: "<<omp_get_thread_num();
            } // End of taskgroup
            // Code after tasks are completed
            cout<<"\n\nsum1: "<<sum1<<" sum2: "<<sum2<<"\n";

            #pragma omp taskgroup
            {   //both task will run in parallel
                #pragma omp task
                {
                    cout<<"\nrunning task 1 with thread id: "<<omp_get_thread_num();
                    for(int a=0;a<100;a++)
                    {   sum1+=a;}
                }
                #pragma omp task
                {
                    cout<<"\nrunning task 2 with thread id: "<<omp_get_thread_num();
                    for(int a=0;a<100;a++)
                    {   sum2+=a;}
                }
                cout<<"\nReached end of taskgroup tid: "<<omp_get_thread_num();
            } // End of taskgroup
            // Code after tasks are completed
            cout<<"\n\nsum1: "<<sum1<<" sum2: "<<sum2<<"\n";
        }
    }
    return 0;
}