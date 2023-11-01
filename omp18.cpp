#include<iostream>
#include<omp.h>

using namespace std;

struct data_struct
{
    data_struct *next;
    int data;
};
int main()
{
    int size=10;
    data_struct *start,*next;
    start=new data_struct();
    start->data=0;
    next=start;
    for(int a=0;a<size;a++)
    {
        next->data=a+1;
        next->next=new data_struct();
        next=next->next;
    }
    omp_nest_lock_t lock1;//locks are not needed here, we used it only so that cout can work properly.
    omp_init_nest_lock(&lock1);
    #pragma omp parallel
    {
        #pragma omp single
        {
            data_struct *p=start;
            while(p)
            {
                #pragma omp task
                {   
                    omp_set_nest_lock(&lock1);
                    cout<<" "<<p->data;
                    omp_unset_nest_lock(&lock1);
                }
                p=p->next;
            }
        }
    }
    return 0;
}