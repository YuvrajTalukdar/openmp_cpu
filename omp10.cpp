#include<omp.h>
#include<iostream>

using namespace std;

omp_nest_lock_t lock1;

void test()
{
    int tid=omp_get_thread_num();
    omp_set_nest_lock(&lock1);
    cout<<"\ntid: "<<tid;
    omp_unset_nest_lock(&lock1);
}

int main()
{
    omp_init_nest_lock(&lock1);
    #pragma omp parallel num_threads(6)
    {
        test();
    }
    return 0;
}