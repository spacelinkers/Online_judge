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
#define FOr(I,B,A)  for(int I=B-1;I>=A;I--)
#define set0(X,Y)    memset(Y,X,sizeof(Y))
#define FOR(I,A,B)  for(int I=A;I<B;I++)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;


ll dp[60][60],col[60],row[60],n,k;
ll len1,len2,len3,ans1=0;

ll fun(ll a,ll x)
{
    if(a==k)
    {
        return 1;
    }
    if(dp[a][x]!=-1) return dp[a][x];
    ll ans=0;
    FOR(i,x,n)
    FOR(j,0,n)
    {
        if(col[i]==1||row[j]==1)
            continue;
        col[i]=row[j]=1;
        ans+=fun(a+1,i);
        col[i]=row[j]=0;
    }
    return dp[a][x]=ans;
}

int main ()
{
    fop;
    ll t,cases=1;
    sf("%lld",&t);
    while(t--)
    {
        set0(-1,dp);
        set0(0,col);
        set0(0,row);
        sf("%lld%lld",&n,&k);
        ll ans=fun(0,0);
        pf("Case %lld: %lld\n",cases++,ans);
        ans1=0;
    }



    return 0;
}




















