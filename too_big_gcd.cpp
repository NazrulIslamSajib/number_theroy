#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long power(long long base,long long power,long long mod1)
{
    long long res=1;
    while(power!=0)
    {
        if(power%2==1)
        {
            res=((res%mod1)*(base%mod1))%mod1;
            power--;
        }
        else
        {
            base=((base%mod1)*(base%mod1))%mod1;
            power=power/2;
        }
    }
    return res%mod1;
}
long long gcd(long long a,long long b,long long n)
{
    if(a==b)
    {
        return (power(a,n,mod)+power(b,n,mod))%mod;
    }
    long long num=abs(a-b);
    long long max1=1;
    for(long long  i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
             long long tmp=(power(a,n,i)+power(b,n,i))%i;
             if(tmp==0)
             {
                 max1=max(max1,i);

             }
             tmp=(power(a,n,num/i)+power(b,n,num/i))%(num/i);
             if(tmp==0)
             {
                 max1=max(max1,num/i);

             }
        }
    }
    return max1%mod;
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long a,b,n;
        cin>>a>>b>>n;
        cout<<gcd(a,b,n)<<endl;
    }
    return 0;
}
