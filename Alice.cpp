#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    const int Q=4;
    const int W=7;
    const int L=25000*Q;
    const int Z=25000*W;
    
    int D[Q][W],i,j,a=1,p=Q-1;
    

    //Reading the input file
    char F[L+1];
    ifstream input;
    input.open("input.txt", ios::out);  
    input>>F;
    //cout<<F;
    input.close();
    

    //cout<<"\n";
    
    //converting the input string into array of numbers
    int A[L];
    for(i=0;i<L;i++)
    {
        if(F[i]=='1') A[i]=1;
        else A[i]=0;
        //cout<<A[i]<<" ";
    }
    //cout<<"\n";
    //cout<<A[2]<<"\n";

    for(i=0;i<W;i++) for(j=0;j<Q;j++) D[j][i]=0;  //D is the generator matrix, W=total no. of bits(data+parity), Q=no. of data bits only
    for(i=0;i<W;i++)
    {
        if(i==(a-1))
        {
            a=2*a;
        }
        else 
        {
            for(j=0;j<Q;j++) 
            {
                if(j==p) D[j][i]=1;
                else D[j][i]=0;
            }
            p--;
        }
    }
    for(i=0,a=1;i<W;i++)
    {
        if(i==(a-1))
        {
            for(j=0;j<Q;j++)
            {
                for(p=i+2;p<W+1;p++)
                {
                    if(((i+1)&p)!=0) D[j][i]=D[j][i]^D[j][p-1];
                }
            }
           a=2*a; 
        }
        else continue;
    }
    //for(j=0;j<Q;j++) {for(i=0;i<W;i++) cout<<D[j][i]<<" ";cout<<"\n";}
    
    //encoding
    int P[Z],h;
    for(a=0;a<25000;a++)
    {
        h=a*W;
        for(i=h;i<h+W;i++)
        {
           P[i]=0;
           for(j=0;j<Q;j++)
           {
             P[i]=(P[i]^(A[j+Q*a]&(D[j][i-h])));
           }
              
        //cout<<P[i]<<" ";
        }
    }
    //cout<<"\n";
    
    //cout<<h;
    
    char C[Z+1];
    for(i=0;i<Z;i++) 
    {
        if(P[i]==1) C[i]='1';
        else C[i]='0';

    }
    //cout<<C<<"\n";
    
    
    /*ofstream MyFile("encoded.txt");
    MyFile<<C;
    MyFile.close();*/
    fstream encoded;                       
    encoded.open("encoded.txt", ios::out);  
    encoded<<C;
    encoded.close();
    return 0;





}
