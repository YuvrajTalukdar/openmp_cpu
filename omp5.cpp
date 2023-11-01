
#include<omp.h>
#include<iostream>
#include<random>

using namespace std;

int get_random_number(int min,int max)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist6(min,max); // distribution in range [1, 6]
    return dist6(rng);
}

int main()
{
    int num_list[10];
    for(int a=0;a<10;a++)
    {   num_list[a]=get_random_number(1,50);}
    int max1=num_list[0];
    for(int a=1;a<10;a++)
    {
        if(num_list[a]>max1)
        {   max1=num_list[a];}
    }
    cout<<"\ncorrect max: "<<max1;

    int max2=num_list[0];
    #pragma omp parallel num_threads(9)
    {
        int a=omp_get_thread_num()+1;
        #pragma omp critical
        if(num_list[a]>max2)
        {   
            //#pragma omp atomic read
            //#pragma omp critical
            max2=num_list[a];
        }
    }
    cout<<"\n max: "<<max2;

    return 0;
}