#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int sum1[5][5];
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskloop collapse(2)
            for (int i = 0; i < 5; i++) 
            {
                for(int j=0;j<5;j++)
                {   
                    cout<<"\nrunning from tid: "<<omp_get_thread_num();
                    sum1[i][j]=i*j;
                }
                // Task code for each loop iteration
            }
        }
    }
    return 0;
}