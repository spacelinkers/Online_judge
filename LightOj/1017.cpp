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


int dp[160][160],num[165];
int l1,l2,l3,n,w,k,a;

struct lin{
    int x,y;
}N[120];

bool cmp(lin a,lin b){return a.x<b.x;}

int fun(int cont,int rem)
{
    if(cont >= n || rem == 0)
    {
        return 0;
    }
    if(dp[cont][rem] != -1) return dp[cont][rem];
    int ans1 = 0,i,ans=0;
    int ls=num[cont]+w;
    for(i=cont ; i<n && ls>=num[i] ; i++)
    {
        ans1++;
    }
    ans1+=fun(i,rem-1);
    int ans2=fun(cont+1,rem);
    ans=max(ans1,ans2);
    return dp[cont][rem]=ans;
}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d%d",&n,&w,&k);
        set0(-1,dp);
        pf("Case %d: ",cases++);
        FOR(i,0,n)
        {
            sf("%d%d",&a,&num[i]);
        }
        sort(num,num+n);
        int ans=fun(0,k);
        pf("%d\n",ans);
    }



    return 0;
}




















