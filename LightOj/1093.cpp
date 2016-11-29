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

int dp[160][160],num[100005];
int l1,l2,l3,n,d,l_min[100005],r_min[100005],sl_min[100005];
int l_max[100005],r_max[100005],sl_max[100005];

int fun(int a,int b)
{
    int i,j;
    l_min[0]=num[0];
    r_min[b-1]=num[b-1];

    FOR(i,1,b)
    {
        if(i%d==0)
            l_min[i]=num[i];
        else
            l_min[i]=min(l_min[i-1],num[i]);
        j=b-i-1;

        if(j%d==0)
            r_min[j]=num[j];
        else
            r_min[j]=min(r_min[j+1],num[j]);
    }

    for(i=0,j=0;i+d<=b;i++)
    {
        sl_min[j++]= min(r_min[i],l_min[i+d-1]);
    }
//    return sl_min;
}

int fun1(int a,int b)
{
    int i,j;
    l_max[0]=num[0];
    r_max[b-1]=num[b-1];

    FOR(i,1,b)
    {
        if(i%d==0)
            l_max[i]=num[i];
        else
            l_max[i]=max(l_max[i-1],num[i]);

        j=b-i-1;

        if(j%d==0)
            r_max[j]=num[j];
        else
            r_max[j]=max(r_max[j+1],num[j]);
    }

    for(i=0,j=0;i+d<=n;i++)
    {
        sl_max[j++]= max(r_max[i],l_max[i+d-1]);
    }
}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);
    while(t--)
    {
        set0(0,sl_max);
        set0(0,r_max);
        set0(0,l_max);
        set0(11111111,sl_min);
        set0(11111111,r_min);
        set0(11111111,l_min);
        sf("%d%d",&n,&d);
        FOR(i,0,n)
        {
            sf("%d",&num[i]);
        }
        fun(0,n);

        fun1(0,n);
        int maxx=0,b;
        if(d==1) pf("Case %d: 0\n",cases++);
        else
        {
            FOR(i,0,n-d)
            {
                b=sl_min[i]-sl_max[i];
                if(b<0) b*=-1;
                maxx=max(maxx,b);
            }
            pf("Case %d: %d\n",cases++,maxx);
        }
    }


    return 0;
}




















