#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int i,sum=0;
    omp_set_num_threads(12);
    #pragma omp parallel
    {
        cout<<"\ncheck";
        #pragma omp for reduction(+:sum)
        for(i=1;i<=100;i++)
        {   sum+=i;}
    }
    
    int sum2=0;
    for(i=1;i<=100;i++)
    {   sum2+=i;}
    cout<<"sum: "<<sum<<" sum2: "<<sum2<<"\n";
    /*
    we need to add 100 numbers, these numbers are divided into chunks and each shunks are added in
    different threads. Finally the results of the chunks are added up to get the final threads.
    */
    return 0;
}