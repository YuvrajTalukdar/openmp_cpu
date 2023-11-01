//atomic read
#include<omp.h>
#include<iostream>

using namespace std;

int main()
{
    int max=0;
    int arr[10];
    for(int a=0;a<10;a++)
    {
        arr[a]=rand();
        if(arr[a]>max)
        {   max=arr[a];}
    }
    cout<<"\nCorrect max: "<<max;

    int max2=0;
    #pragma omp parallel for
    for(int a=0;a<10;a++)
    {
        if(arr[a]>max2)
        {   max2=arr[a];}
    }
    cout<<"\nIncorrect Max: "<<max2<<endl;

    int max3=0;
    #pragma omp parallel for
    for(int a=0;a<10;a++)
    {
        if(arr[a]>max3)
        {
            #pragma omp atomic read   
            max3=arr[a];
        }
    }
    cout<<"\nMax: "<<max3<<endl;
    return 0;
}