//atomic update
#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    int count=0;
    #pragma omp parallel num_threads(16)
    {   count++;}
    cout<<"\nIncorrect sum: "<<count<<endl;
    int count2=0;
    #pragma omp parallel num_threads(16)
    {
        /*here update option can 
        also be used for more specific atomicity*/
        #pragma omp atomic
        count2++;
    }
    cout<<"\nCorrect sum: "<<count2<<endl;
    return 0;
}