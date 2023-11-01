#include<omp.h>
#include<iostream>

using namespace std;

void test(bool val)
{
    #pragma omp parallel if (val)
    if(omp_in_parallel())
    {
        #pragma omp single
        cout<<"\nval: "<<val<<" parallelized with "<<omp_get_num_threads()<<" threads";
    }
    else
    {
        cout<<"\nval: "<<val<<" serialized";
    }
    #pragma omp parallel for if(val)
    for(int a=0;a<2;a++) 
    {
        cout<<"\na: "<<a;
    }
}

int main()
{
    omp_set_num_threads(5);
    test(false);
    test(true);
    return 0;
}