#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define fop         freopen("in.txt","r",stdin)
#define set0(X,Y)   memset(Y,X,sizeof(Y))
#define mapp        map<string,int> mp;
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define FOr(I,B,A)  for(I=B;I>A;I--)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf
#define mod         100000007

long long dp[55][60000];
long long num[200],n,k;
long long coin[200];

long long fun(long long c,long long w)
{
    long long a1=0,a2=0;

    if(c>=n)
    {
        if(w==0) return 1;
        else return 0;
    }

    if(dp[c][w]!=-1) return dp[c][w];
    for(long long j=1;j<=num[c];j++)
    {
        if(w-coin[c]*j>=0)
            a1+=fun(c+1,w-coin[c]*j);
    }
    a2=fun(c+1,w);

    return dp[c][w]=(a1+a2)%mod;
}

int main()
{
    fop;
    long long t,i,cases=1;
    sf("%lld",&t);
    while(t--)
    {
        sf("%lld%lld",&n,&k);
        FOR(i,0,n)
            sf("%lld",&coin[i]);
        FOR(i,0,n)
            sf("%lld",&num[i]);

        set0(-1,dp);
        long long ans1=fun(0,k);
        pf("Case %lld: %lld\n",cases++,ans1);
    }

    return 0;
}











