#include<iostream>
#include<omp.h>
#include<math.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

int main()
{
    int no_of_threads=12;
    int i,sum=0;
    int thread_sum[no_of_threads];
    omp_set_num_threads(no_of_threads);
    auto start = high_resolution_clock::now();
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        thread_sum[tid]=0;
        #pragma omp for
        for(i=1;i<=100000;i++)
        {   thread_sum[tid]+=i;}
    }
    for(int a=0;a<4;a++)
    {   sum+=thread_sum[a];}
    cout<<"sum: "<<sum;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n\nTime Taken= "+to_string(duration.count()/pow(10,6))+"\n\n";
    /*
    this code is effected by false sharing problem
    cause= thread_sum array is stored in a cache line. When indivitual element of the thread_sum
    array is updated the entire cache line is invalidated as a result again and again data needs to 
    be copied from main memory to cache line. 
    */
    return 0;
}