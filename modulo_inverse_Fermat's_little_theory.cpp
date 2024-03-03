#include<bits/stdc++.h>
using namespace std;
long long power(long long base, long long power,long long mod)
{
        long long res=1;
        while(power)
        {
            if(power%2==1)
            {
                res=(base%mod)*(res%mod);
                power--;
            }
            else
            {
                base=(base%mod)*(base%mod);
                power=power/2;
            }
        }
        return res%mod;
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long a,m;
        cin>>a>>m;
        ///mane ekhane a inverse ber korbeo jet a^m-2 diye ber kobo kint shorto hocche a and m hoite hbe coprime
        cout<<"a^-1     : "<<power(a,m-2,m)<<endl;
    }
    return 0;
}
