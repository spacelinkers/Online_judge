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


int dp[100][100],num[20],n,m;
char str[100];

int fun(int pos,int prev)
{
    if(pos==n)
        return 1;
    if(dp[pos][prev]!=-1) return dp[pos][prev];

    int ans=0;
    FOR(i,0,m)
    {
        if(prev==0 || abs(num[i]-prev)<=2)
            ans+=fun(pos+1,num[i]);
    }
    return dp[pos][prev]=ans;

}


int main ()
{
    fop;
    int t,cases=1;

    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&m,&n);
        set0(-1,dp);
        FOR(i,0,m)
            sf("%d",&num[i]);
        int ans=fun(0,0);
        pf("Case %d: %d\n",cases++,ans);
    }




    return 0;
}


