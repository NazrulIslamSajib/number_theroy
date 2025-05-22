#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +10;
long long spf[N+10]; 
///nlog(log(n)) ///arek ta prime factorization ache seta O(sqrt(n)) . ei code eta diye multile factorization ber kora jay test casees
void seive()
{

        for(int i=1;i<=N;i++)
        {
            spf[i] = i;
        }
        for(int i=2;i*i<=N;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=N;j+=i)
                {
                    if(spf[j]==j)spf[j]=i;
                }
            }
        }
}
vector<long long>PrimeFactors(long long x)
{
    vector<long long>factors;
    while (x != 1)
    {
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
        vector<long long>get=PrimeFactors(p);
        long long two=0,five=0;
        for(auto x:get)
        {
           cout<<x<<" ";
        }
        cout<<endl;

    }
    return 0;
}


