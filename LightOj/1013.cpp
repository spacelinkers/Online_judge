
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

map<int,int> Map;

int dp[35][35],d1,d2,x;
ll dp2[35][35][65];
char str1[35],str2[35];

int fun(int a,int b)
{
    int ans=0;
    if(str1[a]=='\0' || str2[b]=='\0') return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    if(str1[a]==str2[b])
        ans=1+fun(a+1,b+1);
    else{
        int v1=fun(a+1,b);
        int v2=fun(a,b+1);
        ans=max(v1,v2);
    }
    return dp[a][b]=ans;

}

ll fun2(ll a,ll b,ll c)
{
    ll ans=0;
    if(str1[a]=='\0'){
        if(c+d2-b==x) return 1;
        else return 0;
    }
    if(str2[b]=='\0'){
        if(c+d1-a==x) return 1;
        else return 0;
    }

    if(dp2[a][b][c]!=-1) return dp2[a][b][c];
    if(str1[a]==str2[b])
        ans=fun2(a+1,b+1,c+1);
    else{
        ans=fun2(a+1,b,c+1)+fun2(a,b+1,c+1);
    }
    return dp2[a][b][c]=ans;
}


int main ()
{
    //fop;
    int t,cases=1;
    sf("%d",&t);
    getchar();
    while(t--)
    {
        sf("%s%s",&str1,&str2);

        set0(-1,dp);
        set0(-1,dp2);
        d1=strlen(str1);
        d2=strlen(str2);

        int d = fun(0,0);
        x = d1+d2-d;
        ll z = fun2(0,0,0);
        pf("Case %d: %d %lld\n",cases++,x,z);
    }


    return 0;
}







