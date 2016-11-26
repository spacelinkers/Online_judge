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

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;
int dp[(1<<17)+2],num[25][25];
int a=-1,b=-1;

int fun(int N,int p,int n)
{
    if(N==(1<<n)-1) return 0;
    if(dp[N]!=-1) return dp[N];
    int ans=0,z=0,i,j,ret;
    FOR(i,0,n)
    {
        if(check(N,i)==0)
        {

            z=num[p][i];

            ret=z+fun(Set(N,i),p+1,n);
            ans=max(ret,ans);

        }

    }
    return dp[N]=ans;
}

int main ()
{
    //fop;
    int t,cases=1,n,i,j;
    sf("%d",&t);
    while(t--)
    {
        set0(-1,dp);
        sf("%d",&n);
        FOR(i,0,n)
        FOR(j,0,n)
            sf("%d",&num[i][j]);
        int ans=fun(0,0,n);
        pf("Case %d: %d\n",cases++,ans);
    }

    return 0;
}









