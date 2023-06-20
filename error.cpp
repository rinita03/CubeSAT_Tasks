#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    const int Q=4;
    const int W=7;
    const int L=25000*Q;
    const int Z=25000*W;
    
    //importing encoded file
    char Y[Z+1];
    ifstream encoded;
    encoded.open("encoded.txt", ios::out);  
    encoded>>Y;
    //cout<<Y<<"\n";
    encoded.close();
    
    srand(time(0));
    int i,c,l,count=0;
    for(i=0;i<Z;i+=7)
    {
       c=rand()%25;
       if(c==5) 
       {
         count++;
         l=(rand()%7)+i;
         if(Y[l]=='1') Y[l]='0';
         else Y[l]='1';
       }
    }
    cout<<count<<"\n";
    
    
    fstream error_encoded;
    error_encoded.open("error_encoded.txt", ios::out);
    error_encoded<<Y;
    error_encoded.close();



}