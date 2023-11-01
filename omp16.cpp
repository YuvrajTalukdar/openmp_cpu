#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    omp_nest_lock_t lock1;
    omp_init_nest_lock(&lock1);
    //#pragma omp parallel num_threads(5) schedule(static,1)
    /*
    static schedule means that iterations blocks are mapped statically to the execution 
    threads in a round-robin fashion. The nice thing with static scheduling is that OpenMP 
    run-time guarantees that if you have two separate loops with the same number of 
    iterations and execute them with the same number of threads using static scheduling, 
    then each thread will receive exactly the same iteration range(s) in both parallel regions. 
    */
    cout<<"\nstatic scheduling";
    #pragma omp parallel for schedule(static,1) num_threads(5)
    for (int i=0;i<10;i++)
    { 
        omp_set_nest_lock(&lock1);
        cout<<"\ntid: "<<omp_get_thread_num();
        omp_unset_nest_lock(&lock1);
    }
    /*
    So one of the advantages for using static scheduling is that it improves locality in 
    memory access. The disadvantage is that bad choice of scheduling parameters can ruin 
    the performance.

    dynamic scheduling works on a "first come, first served" basis. Two runs with the same 
    number of threads might (and most likely would) produce completely different "iteration 
    space" -> "threads" mappings as one can easily verify:
    */
    cout<<"\n\ndynamic scheduling";
    #pragma omp parallel for schedule(dynamic,1) num_threads(5)
    for (int i=0;i<10;i++)
    { 
        omp_set_nest_lock(&lock1);
        cout<<"\ntid: "<<omp_get_thread_num();
        omp_unset_nest_lock(&lock1);
    }

    cout<<"\n\nguided scheduling";
    #pragma omp parallel for schedule(guided,1) num_threads(5)
    for (int i=0;i<10;i++)
    { 
        omp_set_nest_lock(&lock1);
        cout<<"\ntid: "<<omp_get_thread_num();
        omp_unset_nest_lock(&lock1);
    }

    return 0;
}