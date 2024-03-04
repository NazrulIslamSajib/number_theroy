#include<bits/stdc++.h>
using namespace std;
long long fact[1000010];
const int p=1e9+7;//reminder would be prime number
long long power(long long a,long long pow)
{
    long long ok=1;
    while(pow)
    {
        if(pow%2==0)
        {
            a=(a*1LL*a)%p;
            pow=pow/2;
        }
        else
        {
            ok=(ok*a*1LL)%p;
            pow--;
        }
    }
    return ok;
}
long long c(long long n,long long k)
{
    long long res=fact[n];
    if(k>n) return 0;
    res=(res*1LL*power(fact[k],p-2))%p; /// nck=(n!)/(k!*(n-k!)  etai kortechi ar vager bodole gun korchi
                                        ///karon mod vage kora jay na gune kora jay tai farmatt's little theorem
    res=(res*1LL*power(fact[n-k],p-2))%p;

    return res%p;

}
int main()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=1;i<=1000000;i++)
    {
        fact[i]=(fact[i-1]*i*1LL)%p;
    }
    long long tt;
    cin>>tt;
    while(tt--)
    {
       long long n,k;
       cin>>n>>k;
       cout<<c(n,k)<<endl;
    }
    return 0;
}
