#include<bits/stdc++.h>
using namespace std;
const int max1=100;
long long arr[max1][max1],I[max1][max1],i,j,k;
void mul(long long II[][max1],long long aarr[][max1],long long ddim)
{
    long long res[max1][max1];
    for(i=0;i<ddim;i++)
    {
        for(j=0;j<ddim;j++)
        {
            res[i][j]=0;
            for(k=0;k<ddim;k++)
            {
               res[i][j] += II[i][k] * aarr[k][j]; ///I=I*A;
            }
        }
    }
    for(i=0;i<ddim;i++)
    {
        for(j=0;j<ddim;j++)
        {
            II[i][j]=res[i][j];
        }
    }
}
void power(long long arr[][max1],long long dim,long long yes)
{
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(i==j)
            {
                I[i][j]=1;
            }
            else
            {
                I[i][j]=0;
            }
        }
    }
    //for(int ii=0;ii<yes;ii++)
    //{

   // }
   while(yes!=0)
   {
       if(yes%2==1)
       {
           mul(I,arr,dim);
           yes--;
       }
       else
       {
           mul(arr,arr,dim);
           yes=yes/2;
       }
   }
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            arr[i][j]=I[i][j];
        }
    }
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
         long long dim,n;
         cin>>dim>>n;
         for(i=0;i<dim;i++)
         {
             for(j=0;j<dim;j++)
             {
                 cin>>arr[i][j];
             }
         }
        power(arr,dim,n);
        for(i=0;i<dim;i++)
        {
        for(j=0;j<dim;j++)
        {
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        }



    }
    return 0;
}
