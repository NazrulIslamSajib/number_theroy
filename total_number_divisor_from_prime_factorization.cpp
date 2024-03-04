#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long tt;
    scanf("%lld",&tt);
    while(tt--)
    {
        long long i,a,b;
        scanf("%lld %lld", &a, &b);
        long long gcd=__gcd(a,b);
        long long ans=1;
        for(i=2;i*i<=gcd;i++)
        {
            if(gcd%i==0)
            {
               long long cnt=0;
               while(gcd%i==0)
               {
                   cnt++;
                   gcd=gcd/i;
               }
              ans=ans*(cnt+1);
            }
        }
        if(gcd>1)
        {
            ans=ans*2;
        }

        printf("%lld\n",ans);
    }
    //// 2^3*3^8*5^4
    //divisor=(3+1)*(8+1)*(4+1)
    return 0;
}

