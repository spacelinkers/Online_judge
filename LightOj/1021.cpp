#include<bits/stdtr1c++.h>
#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include <set>
#include<map>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

#define fop         freopen("in.txt","r",stdin)
#define set0(X,Y)    memset(Y,X,sizeof(Y))
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define FOr(I,B,A)  for(I=B;I>A;I--)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

ll Set(ll N,ll pos){return N=N | (1<<pos);}
ll reset(ll N,ll pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}

map<int,int> Map;
ll dp[1<<17][22];
ll b,k,num[20];

ll conv(char z)
{
    if(z=='A') return 10;
    else if(z=='B') return 11;
    else if(z=='C') return 12;
    else if(z=='D') return 13;
    else if(z=='E') return 14;
    else if(z=='F') return 15;
    else return z-'0';
}

ll fun(ll N,ll rem,ll n)
{
    if(N==(1<<n)-1)
        if(rem==0) return 1;
            else 0;
    if(dp[N][rem]!=-1) return dp[N][rem];

    ll ans=0,i;
    for(i=n-1;i>=0;i--)
    {
        if(check(N,i)==0)
        {
            ans+=fun(Set(N,i),(rem*b+num[i])%k,n);
        }
    }
    return dp[N][rem]=ans;
}


int main ()
{
    //fop;
    ll t,i,cases=1;
    char nx[20];
    sf("%lld",&t);
    while(t--)
    {
        set0(-1,dp);
        sf("%lld%lld",&b,&k);
        getchar();
        sf("%s",&nx);
        ll len=strlen(nx);
        FOR(i,0,len)
        {
            ll a=conv(nx[i]);
            num[i]=a;
        }
        ll ans=fun(0,0,len);

        pf("Case %lld: %lld\n",cases++,ans);
    }


    return 0;
}










