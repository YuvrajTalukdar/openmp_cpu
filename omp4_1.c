#include <omp.h>
#include <stdio.h>

//barriers are global in nature
//t0 reach barrier in if condition 1
//t1 reach barrier in if condition 2
//t2 directly goes to the end as never reach the barrier 
//Now t0,t1 are waithing for t2 at the barrier, t2 which already reached the end of #pragma skipped the barrier as it did not meet the if conditions.
int main() {
    int thread_id;
    int num_threads = 3;

    #pragma omp parallel num_threads(num_threads)
    {
        
        thread_id = omp_get_thread_num();
        #pragma omp barrier
        printf("%d",thread_id);
        //#pragma omp barrier

        if (thread_id == 0) 
        {
            printf("Thread 0: Doing some work...\n");
            // Simulate some work
            for (int i = 0; i < 10000000; i++);
            printf("Thread 0: Reached the barrier.\n");

            // Incorrectly trying to wait for thread 1
            #pragma omp barrier
            printf("Thread 0: Barrier crossed.\n");
        } else if (thread_id == 1) {
            printf("Thread 1: Doing some work...\n");
            // Simulate some work
            for (int i = 0; i < 10000000; i++);
            printf("Thread 1: Reached the barrier.\n");

            // Incorrectly trying to wait for thread 0
            #pragma omp barrier
            printf("Thread 1: Barrier crossed.\n");
        }
    }

    return 0;
}
