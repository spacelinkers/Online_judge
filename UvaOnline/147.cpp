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

long long dp[15][35000];
long long coin[12]={10000,5000,2000,1000,500,200,100,50,20,10,5};


long long fun(long long c,long long w)
{
    long long a1=0,a2=0;
    if(c>=11)
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
    fop;
    double n;
    long long a,r,i;
    set0(-1,dp);
    while(sf("%lld.%lld",&r,&i))
    {
        r=r*100+i;
        n=r;
        a=n;
        if(r==0&&i==0) break;
        long long ans=fun(0,a);
        pf("%6.2lf%17lld\n",n/100,ans);
        r=0,i=0;
    }


    return 0;
}










