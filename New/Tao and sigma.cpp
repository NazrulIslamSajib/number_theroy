///tao hocche number of divisor
///n er prime factorization korle eder 16*3=2^4 * 3^1
///tahoe n er divisor hbe=(4+1)+2 special 2 jog karon combination korle
///eidike 0 dite pare abar oi dike 0 dite pari.
///sigma hocche=joto gula divisor ache eder sums sigma=(p1^(e1+1)-1)/(p1-1)..p2,pr eivabe sob prime factor
#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
long long tao[mx+10];
long long sigma[mx+10];
void seive()
{
    for(int i=1;i*i<=mx;i++)
    {
        for(int m=i;m<mx;m+=i)
        {
            tao[m]++;
            sigma[m]+=i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    seive();///eta hocche optimize seive na . optimise ta i*i theke suru hoy
    while(tt--)
    {
         long long n;
         cin>>n;
         cout<<"Tao : "<<tao[n]<<endl;
         cout<<"Sigma : "<<sigma[n]<<endl;
    }
    return 0;
}


