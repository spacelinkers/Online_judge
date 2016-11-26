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
#define mod         100000007

ll n,k;
ll dp[19005],coin[104];

int main()
{
    fop;
    ll t,i,j,l,cases=1,z,p;
    sf("%lld",&t);
    while(t--)
    {
        sf("%lld%lld",&n,&k);
        FOR(i,0,n)
            sf("%lld",&coin[i]);
        set0(0,dp);
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=k;j++)
            {
                if(dp[j]!=0)
                {
                    dp[j+coin[i]]=(dp[j+coin[i]]+dp[j])%100000007;
                }
            }
        }
        pf("Case %lld: %lld\n",cases++,dp[k]);
    }

    return 0;
}











