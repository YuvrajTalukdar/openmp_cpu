#include <iostream>
#include <omp.h>

using namespace std;

int main() 
{
    int N = 5;
    #pragma omp parallel num_threads(2)
    {
        #pragma omp for ordered
        for (int i = 0; i < N; ++i) 
        {
            #pragma omp ordered
            {   
                cout << "Ordered section for i = ";
                cout<< i << " (Thread " << omp_get_thread_num() << ")\n";
            }
        }
        cout<<"\ncheck";
    }
    return 0;
}
