#include<iostream>
#include<omp.h>
#include<chrono>
#include<math.h>

using namespace std::chrono;
using namespace std;

const int ARRAY_SIZE = 1000000;
const int NUM_THREADS = 6;

int main() 
{
    int sharedArray[ARRAY_SIZE];
    int results[NUM_THREADS] = {0};

    // Initialize the shared array
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        sharedArray[i] = i + 1;
    }

    auto start = high_resolution_clock::now();
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int threadId = omp_get_thread_num();
        int sum = 0;

        // Each thread calculates the sum of elements it's responsible for
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) 
        {
            sum += sharedArray[i];
        }

        // Store the thread's sum in the results array
        results[threadId] = sum;
    }

    // Calculate the total sum from thread results
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; i++) 
    {
        totalSum += results[i];
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n\nTime Taken= "+to_string(duration.count()/pow(10,6))+"\n\n";

    cout << "Total sum: " << totalSum << std::endl;

    return 0;
}
