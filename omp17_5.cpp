#include<omp.h>
#include<iostream>
#include<unistd.h>

using namespace std;

int main() 
{
  #pragma omp parallel
  #pragma omp single
  {
    #pragma omp taskgroup
    {
      #pragma omp task
      {
        #pragma omp critical
        cout<<"Task 1\n";

        #pragma omp task
        {
          sleep(1);
          #pragma omp critical
          cout<<"Task 2\n";
        }
      }
    }
    //#pragma omp taskwait
    #pragma omp task
    {
      #pragma omp critical
      cout<<"Task 3\n";
    }
  }

  return 0;
}
