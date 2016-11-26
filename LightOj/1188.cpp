#include<bits/stdc++.h>
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

int dp[100][100],num[500010],n,q,ans=0;
int block,cont[500010],ans1[500010];

vector<int>v1,v2,v,q1;
queue<int>P;

struct info{
    int left,right,pos;
}N[500010];

bool cmp(info x,info y)
{
    if(x.left/block!=y.left/block)
        return x.left/block<y.left/block;
    return x.right<y.right;
}

void fun_add(int z)
{
    cont[num[z]]++;
    if(cont[num[z]]==1)
        ans++;
}

void fun_remove(int z)
{
    cont[num[z]]--;
    if(cont[num[z]]==0)
        ans--;
}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);

    int a,b,p;
    while(t--)
    {
        set0(0,N);
        set0(0,cont);
        sf("%d%d",&n,&q);

        block=sqrt(n)+1;

        FOR(i,0,n)
        {
            sf("%d",&num[i]);
        }

        pf("Case %d:\n",cases++);
        FOR(i,0,q)
        {
            sf("%d%d",&N[i].left,&N[i].right);
            N[i].left--,N[i].right--;
            N[i].pos=i;
        }
        sort(N,N+q,cmp);

        int currentl=0;
        int currentr=0;
        FOR(i,0,q)
        {
            int l=N[i].left;
            int r=N[i].right;

            while(currentl<l)
            {
                fun_remove(currentl);
                currentl++;
            }
            while(currentl>l)
            {
                fun_add(currentl-1);
                currentl--;
            }
            while(currentr<=r)
            {
                fun_add(currentr);
                currentr++;
            }
            while(currentr>r+1)
            {
                fun_remove(currentr-1);
                currentr--;
            }
            ans1[N[i].pos]=ans;
        }

        FOR(i,0,q)
            pf("%d\n",ans1[i]);
        ans=0;
    }

    return 0;
}






















