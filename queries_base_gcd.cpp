#include<bits/stdc++.h>
using namespace std;
long long arr[1000010],pre[1000010],suf[1000010];
long long gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    gcd(b,a%b);
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
    long long n,q;
    cin>>n>>q;
    long long i;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    pre[0]=0;
    suf[n+1]=0;
    for(i=1;i<=n;i++)
    {
        pre[i]=gcd(arr[i],pre[i-1]);
    }
    for(i=n;i>=1;i--)
    {
        suf[i]=gcd(arr[i],suf[i+1]);
    }
    while(q--)
    {
        long long l,r;
        cin>>l>>r;
        cout<<gcd(pre[l-1],suf[r+1])<<endl;
    }
    }
    return 0;
}
