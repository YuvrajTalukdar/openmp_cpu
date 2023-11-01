#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
    int m1_r,m1_c,m2_r,m2_c;
    cin>>m1_r>>m1_c>>m2_r>>m2_c;
    int m1[m1_r][m1_c];
    for(int a=0;a<m1_r;a++)
    {
        for(int b=0;b<m1_c;b++)
        {   cin>>m1[a][b];}
    }
    int m2[m2_r][m2_c];
    for(int a=0;a<m2_r;a++)
    {
        for(int b=0;b<m2_c;b++)
        {   cin>>m2[a][b];}
    }
    int m3[m1_r][m2_c];
    #pragma omp parallel for collapse(2) num_threads(m1_r*m2_c)
    for(int a=0;a<m1_r;a++)
    {
        for(int b=0;b<m2_c;b++)
        {
            m3[a][b]=0;
            cout<<"\ntid: "<<omp_get_thread_num();
            for(int c=0;c<m2_r;c++)
            {
                m3[a][b]+=m1[a][c]*m2[c][b];
            }
        }
    }
    cout<<"\n";
    for(int a=0;a<m1_r;a++)
    {
        for(int b=0;b<m2_c;b++)
        {   cout<<m3[a][b]<<" ";}
        cout<<endl;
    }
    return 0;
}