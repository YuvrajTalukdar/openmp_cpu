#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int a[5], i;
    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<5;i++)
        {   a[i]=i*i;}
        #pragma omp master//underlying section of code is executed by the master thread only. i.e. thread with id 0.
        for(i=0;i<5;i++)
        {   cout<<"\na["<<i<<"]= "<<a[i];}
        #pragma omp barrier
        //#pragma omp for
        //for(i=0;i<5;i++)
        //{   a[i]+=i;}
    }
    
    return 0;
}