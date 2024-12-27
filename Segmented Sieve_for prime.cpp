////this is segmented seive

/* https://www.spoj.com/problems/PRIME1/ */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    cin>>tt;
    while(tt--)
    {
        long long l,r;
        cin>>l>>r;
        if(l<2 and r>=2){  /// edge case hande korchi l er man atleast 2 hoite hbe
        l=2;
        }
        long long r1=sqrt(r)+10;   /// ekon je r deoya thakbe amar to tar sqrt root pojjonot prime niliei
        ///hoy karon segulidiye to vag korbo .
        bool prime[r1+10];
        memset(prime,false,sizeof(prime));  /// l-r  jonno small prime ber kortechi 1 theke sqrt(r) pojjonoto
        prime[0]=true;
        prime[1]=true;
        for(long long i=2;i*i<=r1;i++)
        {
            if(prime[i]==false)
            {
               for(long long j=i*i;j<=r1;j+=i)
               {
                   prime[j]=true;
               }
            }
        }
        vector<long long>v; /// small prime like 100 200 range . to small prime 2,3,5,7,11,12,13 eigula
        /// multiple gula amar ranger modde true kore dibo. mane oi gula prime na.
        for(long long i=2;i<=r1;i++)
        {
            if(prime[i]==false)
            {
                v.push_back(i);
            }
        }
        bool mprime[r-l+1]; /// dorkar r-l+1 er ranger
        memset(mprime,false,sizeof(mprime));
        for(auto x:v)
        {
            long long lower=max(x*x,(l+x-1)/x*x);  /// primer er minimum multiple gula nicchi , x*x keno
            /// dilam kono ekta case dhoro 3/3 dara vag dicchi . tokhon ceil valuo 3 asbe to amar to 3 dorkar nai
            /// 3 er multiple dorkar tai max(9,3) jeta maximum seta nicchi.
            for(int i=lower;i<=r;i+=x)
            {
                mprime[i-l]=true;
            }
        }
        ///eigula zero index theke shuru hocche tai i-l subtruct kortechi.
        for(int i=l;i<=r;i++)
        {
            if(mprime[i-l]==false)
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}

