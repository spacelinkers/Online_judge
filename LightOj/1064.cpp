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


ll dp[250][500],n,x;
ll num[]={1,2,3,4,5,6};


int main ()
{
    fop;
    ll t,cases=1;
    sf("%lld",&t);
    while(t--)
    {
        set0(0,dp);
        sf("%lld%lld",&n,&x);

        FOR(i,1,7)
            dp[1][i]=1;
        FOR(i,1,n)
        {
            FOR(j,1,150)
            {
                if(dp[i][j]!=0)
                FOR(k,1,7)
                {
                    dp[i+1][j+k]+=dp[i][j];
                }
            }
        }
        ll ans=0,z=1;
        FOR(i,x,150)
            ans+=dp[n][i];
        FOR(i,0,n)
            z*=6;
        ll gcd=__gcd(ans,z);
        pf("Case %lld: ",cases++);
        if(ans==0) pf("0\n");
        else if(z/gcd==1) pf("%lld\n",ans/gcd);

        else pf("%lld/%lld\n",ans/gcd,z/gcd);
    }


    return 0;
}




















