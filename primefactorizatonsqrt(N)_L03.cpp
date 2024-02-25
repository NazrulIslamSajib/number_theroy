#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long n,i;
        cin>>n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
               long long cnt=0;
               while(n%i==0)
               {
                   cnt++;
                   n=n/i;
               }
               cout<<i<<" ^ "<<cnt<<endl;
            }
        }
        if(n>1)
        {
            cout<<n<<" ^ "<<1<<endl;
        }

    }
    return 0;
}
