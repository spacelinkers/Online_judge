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


int dp[60][60][60],n,x;
int len1,len2,len3;
char a[60],b[60],c[60];


int fun(int i,int j,int k)
{
    if(a[i]=='\0' || b[j]=='\0' || c[k]=='\0')
        return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int ans=0;
    if(a[i]==b[j] && c[k]==a[i] && b[j]==c[k])
        ans=1+fun(i+1,j+1,k+1);
    else{
        int val1=fun(i+1,j,k);
        int val2=fun(i+1,j+1,k);
        int val3=fun(i+1,j,k+1);
        int val4=fun(i,j+1,k+1);
        int val5=fun(i,j+1,k);
        int val6=fun(i,j,k+1);

        ans=max(max(max(max(max(val6,val5),val4),val3),val2),val1);
    }
    return dp[i][j][k]=ans;

}
int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);
    while(t--)
    {
        set0(-1,dp);
        sf("%s%s%s",&a,&b,&c);
        len1=strlen(a);
        len2=strlen(b);
        len3=strlen(c);

        int ans=fun(0,0,0);

        pf("Case %d: %d\n",cases++,ans);
    }


    return 0;
}




















