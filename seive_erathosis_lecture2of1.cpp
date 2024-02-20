#include<bits/stdc++.h>
using namespace std;
bool prime[90000001];
long long max1=90000000,i;///1 koti number nichi 5 lac prime number ber korte
vector<long long>v;
void solve()
{
    prime[0]=true;
    prime[1]=true;
    for(i=2;i*i<=max1;i++)
    {

        if(prime[i]==false)
        {
            for(long long j=i*i;j<=max1;j=j+i)
            {
                prime[j]=true;
            }
        }
    }
    for(i=2;i<=max1;i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}
int main()
{
    solve();
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        cout<<v[n-1]<<endl;
    }
    return 0;
}
