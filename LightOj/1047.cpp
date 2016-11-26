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

int l1,l2,num[30][10],n;
int dp[120][120];


int main ()
{
    fop;
    int t,n,cases=1;
    double m;
    sf("%d".&t);
    while(t--)
    {
        sf("%lf%d",&m,&n);
        FOR(i,0,n)
        {
            sf("%d%lf",&num[i],&cost[i]);
        }
    }



    return 0;
}











