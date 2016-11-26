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

ll dp[110];


int main ()
{
    fop;
    ll t,cases=1,i,j,n,cont=0,ans=0;
    dp[1]=0;dp[2]=1;
    FOR(i,3,32)
    {
        dp[i]=dp[i-1]+(2<<i-3);
        dp[i]+=dp[i-1];
    }

    sf("%lld",&t);
    while(t--)
    {
        sf("%lld",&n);
        ll z=n;
        while(n>1)
        {
            cont=0;
            ll d=1;
            while(d<=n){
                d*=2;
                cont++;
            }
            d=d/2;
            ans+=dp[cont-1];
            ll x=(1<<cont)-(1<<cont-1);
            x/=2;
            x+=(1<<(cont-1))-1;
            x=n-x;
            if(x>0)
            ans+=(x);
            n-=d;


        }
        pf("Case %lld: %lld\n",cases++,ans);
        ans=0;
    }



    return 0;
}











;

