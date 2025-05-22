#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +10;
long long spf[N+10];
///number of tailing zero ncr * p^q
///https://lightoj.com/problem/trailing-zeroes-ii
void seive()
{

        for (int i=1;i<=N;i++)
        {
            spf[i] = i;
        }
        for (int i =2;i*i<=N;i++)
        {
            if (spf[i] == i)
            {
                for(int j=i*i;j<=N;j+=i)
                {
                    if (spf[j] == j) spf[j] = i; // mark spf only once
                }
            }
        }
}
vector<long long> getPrimeFactors(long long x) {
    vector<long long> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    seive();
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        long long n,r,p,q;
        cin>>n>>r>>p>>q;
        vector<long long>get=getPrimeFactors(p);
        long long two=0,five=0;
        for(auto x:get)
        {
            if(x==2)
            {
                two++;
            }
            else if(x==5)
            {
                five++;
            }
        }
        two=two*q;
        five=five*q;
        long long upzero1=0,downzero1=0,downzero2=0;
        for(int i=5;i<=n;i*=5)
        {
            five+=(n/i);
        }
        for(int i=5;i<=(n-r);i*=5)
        {
            five-=((n-r)/i);
        }
        for(int i=5;i<=(r);i*=5)
        {
            five-=(r/i);
        }
         for(int i=2;i<=n;i*=2)
        {
            two+=(n/i);
        }
        for(int i=2;i<=(n-r);i*=2)
        {
            two-=((n-r)/i);
        }
        for(int i=2;i<=(r);i*=2)
        {
            two-=(r/i);
        }
        cout<<"Case "<<t<<": "<<max(0LL,min(five,two))<<endl;

    }
    return 0;
}


