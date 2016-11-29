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
#define FOr(I,B,A)  for(I=B-1;I>=A;I--)
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;

int l1,l2,cost[130];
double num[130],m;
double dp[12000];


int main ()
{
    fop;
    int t,n,cases=1,i,j,ans;
    sf("%d",&t);
    while(t--)
    {
        set0(0,dp);
        sf("%lf%d",&m,&n);
        int sum=0;
        FOR(i,0,n)
        {
            sf("%d%lf",&cost[i],&num[i]);
            sum+=cost[i];
        }
        dp[0]=1.0;
        FOR(i,0,n)
        {
            FOr(j,sum+1,cost[i])
            {
                dp[j]=max(dp[j],dp[j-cost[i]]*(1-num[i]));
            }
        }
        int brk=0;
        FOr(i,sum+1,0)
            if(dp[i]>1-m){
                pf("Case %d: %d\n",cases++,i);
                brk=1;
                break;
            }
        if(brk==0)
            pf("Case %d: 0\n",cases++);
    }



    return 0;
}












