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

int dp[160][160],num[30005],ans[30005],vis[30005];
int l1,l2,l3,n,x[20],y[20];


int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);
    while(t--)
    {
        set0(-1,vis);
        set0(0,ans);
        sf("%d",&n);
        FOR(i,0,n)
            sf("%d",&num[i]);
        FOR(i,0,n)
        {
            if(vis[i]==-1)
            {
                int a=i;
                int cont1=1;
                while(a>0 && num[a-1]>=num[i])
                {
                    cont1++;
                    if(num[a-1]==num[i]) vis[a+1]=1;
                    a--;
                }
                a=i;
                while(a<n-1 && num[a+1]>=num[i])
                {
                    cont1++;
                    if(num[a+1]==num[i]) vis[a+1]=1;
                    a++;
                }
                ans[i]=cont1*num[i];
            }
            else ans[i]=0;
            vis[i]=1;
        }
        int maxx=0;
        FOR(i,0,n)
            maxx=max(maxx,ans[i]);
        pf("Case %d: %d\n",cases++,maxx);

    }


    return 0;
}




















