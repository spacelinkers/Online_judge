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


ll dp[100],n,len,m;
char str[100];

ll fun(ll num)
{
    if(num<0) return 0;
    ll i,j,poww[100];

    poww[0]=1;
    FOR(i,1,len+3)
        poww[i]=poww[i-1]*10;

    set0(0,dp);
    FOr(i,len,0)
        dp[i]=dp[i+1]+(str[i]-'0')*poww[len-i-1];

    ll z=0,result=1;
    FOR(i,1,len)
    {
        z=z*10+(str[i-1]-'0');
        if(str[i]!='0')
            result+=z*poww[len-i-1];
        else
            result+=(z-1)*poww[len-i-1]+dp[i+1]+1;
    }
    return result;
}


int main ()
{
    fop;
    ll t,i,j,cases=1;

    sf("%lld",&t);
    while(t--)
    {
        pf("Case %lld: ",cases++);
        sf("%lld%lld",&m,&n);

        set0(-1,dp);
        sprintf(str,"%lld",m-1);
        len=strlen(str);
        ll ans1=fun(m-1);

        set0(-1,dp);
        sprintf(str,"%lld",n);
        len=strlen(str);
        ll ans2=fun(n);

        ll ans=ans2-ans1;
        pf("%lld\n",ans);
    }




    return 0;
}











;






