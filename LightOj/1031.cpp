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

int dp[110][110],vis[110][110];
int n,num[110],ans[110];

int fun(int beg,int endd)
{
    if(vis[beg][endd]) return dp[beg][endd];
    int ans1=0;
    int mid;
    vis[beg][endd]=1;
    FOR(mid,beg+1,endd+1)
        ans1=min(ans1,fun(mid,endd));
    FOR(mid,beg,endd)
        ans1=min(ans1,fun(beg,mid));

    return dp[beg][endd]=ans[endd]-ans[beg-1]-ans1;
}

int main ()
{
    fop;
    int t,cases=1,i,j;

    sf("%d",&t);
    while(t--)
    {
        set0(0,dp);
        set0(0,vis);
        sf("%d",&n);
        ans[0]=0;
        FOR(i,1,n+1){
            sf("%d",&num[i]);
            ans[i]=ans[i-1]+num[i];
        }

        int ans1=fun(1,n);
        pf("Case %d: %d\n",cases++,ans1*2-ans[n]);



        pf("%d ",ans1);
        FOR(i,0,n+1)
        {
            FOR(j,0,n+1)
                pf("%d ",dp[i][j]);
            pf("\n");
        }
        pf("\n\n");
        FOR(i,0,n+1)
            pf("%d ",ans[i]);
        pf("\n\n");
    }



    return 0;
}











;

