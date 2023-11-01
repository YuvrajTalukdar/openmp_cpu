#include<iostream>
#include<omp.h>
#include<math.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

int main()
{
    int no_of_threads=8;
    int i,sum=0;
    omp_set_num_threads(no_of_threads);
    auto start = high_resolution_clock::now();
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        #pragma omp for reduction(+:sum)
        for(i=1;i<=100000;i++)
        {   sum+=i;}
    }
    cout<<"sum: "<<sum;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n\nTime Taken= "+to_string(duration.count()/pow(10,6))+"\n\n";
    /*
    avoiding false sharing problem
    */
    return 0;
}