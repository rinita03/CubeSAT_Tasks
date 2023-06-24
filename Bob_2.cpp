#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int E=3;
    const int T=7;
    const int Y=25000*T;
    const int J=25000*E;

    int U[E][T],i,j,a,x;
    
    //parity-bit matrix
    for(i=0;i<T;i++)
    {
        a=i+1;
        for(j=E-1;j>=0;j--)
        {            
            U[j][i]=a%2;
            a/=2;               
        }
    }
    //for(i=0;i<E;i++) {for(j=0;j<T;j++) cout<<U[i][j]<<" ";cout<<"\n";}
    
    //reading encoded file
    char F[Y+1];
    ifstream encoded;
    encoded.open("encoded.txt", ios::out);  
    encoded>>F;
    //cout<<F;
    encoded.close();
    F[Y]='\0';

    
    
    //cout<<"\n";
    int G[Y];
    for(i=0;i<Y;i++)
    {
        if(F[i]=='1') G[i]=1;
        else G[i]=0;
        //cout<<G[i]<<" ";
    }
    //cout<<"\n";
    //G[30]=1;

    int P[J],err,num=0;

    for(x=0;x<25000;x++){
       for(i=x*E,a=4,err=0;i<(x+1)*E;i++,a/=2)
       {
         P[i]=0;
         for(j=0;j<T;j++)
               P[i]=P[i]^((U[i-x*E][j])&(G[j+x*T]));
          err+=a*P[i];
        //cout<<Y[i]<<" ";
       }
      if(err!=0) 
         {
            G[(err-1)+(x*T)]=(G[(err-1)+(x*T)]+1)%2;
            num++;
         }
    }
    //cout<<"\n";
    

    

    //retrieving the data
    int v=25000*(T-E);
    int S[v];
    for(x=0;x<25000;x++)
    {
      for(i=x*T,a=1,j=(x+1)*(T-E)-1;i<(x+1)*T;i++)
      {
         if(i==(a-1)+x*T)
         {
            a=2*a;
            
         }  
         else 
         {
            S[j]=G[i];
            j--;
         } 
      }
    }
    cout<<num<<"\n";

    //saving into reconciled_message
    char M[v+1];
    for(i=0;i<v;i++)
    {
        if(S[i]==1) M[i]='1';
        else M[i]='0';
    }
    M[v]='\0';
    
    float h=num/100000.0;
    cout<<"Bit Error Rate="<<h<<"\n";
    fstream reconciled_message;
    reconciled_message.open("reconciled_message.txt", ios::out);  
    reconciled_message<<M;
    reconciled_message.close();

    //for(j=0;j<T-E;j++) cout<<S[j]<<" ";
    //cout<<"\n";
}