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

ll dp[7][30500];
ll coin[7]={1,5,10,25,50};


ll fun(ll c,ll w)
{
    ll a1=0,a2=0;
    if(c>=5)
    {
        if(w==0) return 1;
        else return 0;
    }
    if(dp[c][w]!=-1) return dp[c][w];
    if(w-coin[c]>=0) a1=fun(c,w-coin[c]);
    a2=fun(c+1,w);
    return dp[c][w]=a1+a2;
}

int main()
{
    ll a,r;
    set0(-1,dp);
    while(sf("%lld",&r)!=EOF)
    {
        ll ans=fun(0,r);
        if(ans==1)
        pf("There is only %lld way to produce %lld cents change.\n",ans,r);
        else
        pf("There are %lld ways to produce %lld cents change.\n",ans,r);
    }

    return 0;
}











