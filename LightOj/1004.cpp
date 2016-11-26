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

ll n,l,num[220][220];
ll dp[220][220];

ll fun(ll r,ll c,ll w)
{
    ll a1=0,a2=0;
    if(r>l) return 0;
    if(num[r][c]==0) return 0;
    if(dp[r][c]!=0) return dp[r][c];

    if(r<n)
    {
        a1=num[r][c]+fun(r+1,c,w+num[r][c]);
        a2=num[r][c]+fun(r+1,c+1,w+num[r][c]);
    }
    else{
        a1=num[r][c]+fun(r+1,c,w+num[r][c]);
        a2=num[r][c]+fun(r+1,c-1,w+num[r][c]);
    }
    dp[r][c]=max(a1,a2);
    return dp[r][c];
}

int main()
{
    fop;
    ll t,i,j,p=1,cases=1;
    sf("%lld",&t);
    while(t--)
    {
        sf("%lld",&n);
        l=(2*n)-1;
        set0(0,dp);
        set0(0,num);
        for(i=1;i<=l;i++)
        {
            if(i<=n)
            for(j=1;j<=i;j++)
                sf("%lld",&num[i][j]);
            else{
            for(j=1;j<=n-p;j++)
            {
                sf("%lld",&num[i][j]);
            }
            p++;
            }
        }
        ll ans=fun(1,1,0);
        pf("Case %lld: %lld\n",cases++,ans);
        p=1;
    }


    return 0;
}





