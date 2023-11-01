#include<iostream>
#include<omp.h>
#include<chrono>
#include<math.h>

using namespace std::chrono;
using namespace std;

const int ARRAY_SIZE = 1000000;
const int NUM_THREADS = 6;

int main() {
    int sharedArray[ARRAY_SIZE];
    int totalSum = 0;

    // Initialize the shared array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sharedArray[i] = i + 1;
    }

    auto start = high_resolution_clock::now();
    #pragma omp parallel num_threads(NUM_THREADS) reduction(+:totalSum)
    {
        int threadId = omp_get_thread_num();
        int localSum = 0;

        // Each thread calculates the sum of elements it's responsible for
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            localSum += sharedArray[i];
        }

        // Accumulate the local sum to the total sum using the reduction clause
        totalSum += localSum;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n\nTime Taken= "+to_string(duration.count()/pow(10,6))+"\n\n";

    std::cout << "Total sum: " << totalSum << std::endl;

    return 0;
}
