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

int dp[7][600][100];
int num[8],minn=100000,p=0,lw;
int coin[8]={5,10,20,50,100,200};

int fun(int c,int w,int x,int lw)
{
    int a1=0,a2=0;
    if(w==lw)
        if(minn>x) minn=x;
    if(c>=p)
    {
        if(w==lw) return 1;
        else return 0;
    }
    if(dp[c][w][x]!=-1) return dp[c][w][x];
    for(int j=1;j<=num[c];j++)
    {
        if(w-coin[c]>=lw){
            a1+=fun(c+1,w-coin[c]*j,x+j,lw);
            }
    }
    a2=fun(c+1,w,x,lw);
    return dp[c][w][x]=a1+a2;
}

int main()
{
    fop;
    double n;
    int i,r,e,out=0;
    while(1)
    {
        FOR(i,0,6)
        {
            sf("%d",&num[i]);
            if(num[i]==0) out++;
        }
        if(out==6) break;
        sf("%d.%d",&r,&e);
        r=r*100+e;
        n=r;
        FOR(i,0,6)
        {
            if(r>=coin[i]) p++;
        }
        set0(-1,dp);
        lw=0;
        int ans1=fun(0,r,0,lw);
        FOR(i,p,6)
        {
            lw=r;
            int ans2=fun(0,coin[i],1,lw);
        }

        pf("%d %d\n",ans1,minn);
        p=0;out=0;minn=100000;
    }

    return 0;
}










