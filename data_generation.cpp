#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int Q=100000,i;
    int A[Q];
    srand(time(0));
    for(i=0;i<Q;i++) 
    {
        A[i]=rand()%2;
        //cout<<A[i]<<" ";
    }

    char T[Q+1];
    for(i=0;i<Q;i++)
    {
        if(A[i]==1) T[i]='1';
        else T[i]='0';
    }
    //cout<<"\n";

    fstream input;                       
    input.open("input.txt", ios::out);  
    input<<T;
    input.close();
    return 0;

}