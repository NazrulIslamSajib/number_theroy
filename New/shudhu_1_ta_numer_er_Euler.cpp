///Euler
///emon koto gula x ache jeno x and n coprime hoy
///1<=x<=n  kotu gula x ache jeta n er sathe coprime
///pie(p)=p-1. prime p
///prime na hole
///pie(p^k)=p^k-(p^k/p)==p^k-p^(k-1)
///in general pie(n)= er prime factorization korle
///p1^k,p2^k hole pottker pie(n)=pie(p1^k)*p(p2^k)
///second formula pie(n)=n*(1-1/p1)*(1-1/p2)....
#include<bits/stdc++.h>
using namespace std;
vector<long long>primefactorization(long long n)
{
        vector<long long>factors;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
               factors.push_back(i); ///jodi sob power lagto tahole while loop e ditam
               long long cnt=0;
               while(n%i==0)
               {

                   cnt++;
                   n=n/i;
               }

            }
        }
        if(n>1)
        {
            factors.push_back(n);
        }
        return factors;
}
long long phi(long long n)
{
    vector<long long>prime=primefactorization(n);
    for(auto p:prime)
    {
        n=(n-n/p);
    }
    return n;
}
int main()
{

    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        cout<<phi(n)<<endl;
    }

}





















