#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
           long long a,x;
           cin>>a>>x;
           long long res=1,base=a,power=x;
           while(power!=0)
           {
               if(power%2==1)
               {
                   power--;
                   res=base*res;
               }
               else
               {
                   power=power/2;
                   base=base*base;
               }
           }
           cout<<res<<endl;
    }
    return 0;
}
