#include<iostream>
#include<omp.h>
#include<math.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

int main()
{
    int no_of_threads=8;
    int i,sum_all=0;
    omp_set_num_threads(no_of_threads);
    auto start = high_resolution_clock::now();
    #pragma omp parallel
    {
        int sum=0;
        int tid=omp_get_thread_num();
        #pragma omp for
        for(i=1;i<=100000;i++)
        {   sum+=i;}
        #pragma omp critical
        sum_all+=sum;
    }
    cout<<"sum: "<<sum_all;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n\nTime Taken= "+to_string(duration.count()/pow(10,6))+"\n\n";
    /*
    avoiding false sharing problem
    */
    return 0;
}