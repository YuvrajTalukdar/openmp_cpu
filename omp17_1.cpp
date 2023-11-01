#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int A=10,B,C;
    int sum1=0,sum2=0;
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(in: A) depend(out: B) 
            {
                for(int a=0;a<100;a++)
                {   sum1+=a;}
                // Task code that reads from A and writes to B
                B=A;
            }
            #pragma omp task depend(in: B)
            {
                for(int a=0;a<100;a++)
                {   sum2+=a;}
                // Task code that reads from B
                C=B*6;
            }
        }
    }
    cout<<"C: "<<C<<" sum1: "<<sum1<<" sum2: "<<sum2<<"\n";
    return 0;
}