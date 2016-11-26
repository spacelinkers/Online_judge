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

int dp[100][100],num[500010],n,q;

vector<int>v1,v2,v,q1;
queue<int>P;

struct info{
    int prop,sum;
}tree[500010*3];

void init(int indx,int st,int en)
{
    if(st==en)
    {
        tree[indx].sum=0;
        tree[indx].prop=0;
        return;
    }
    int left=indx*2;
    int right=(indx*2)+1;
    int mid=(st+en)/2;

    init(left,st,mid);

    init(right,mid+1,en);

    tree[indx].sum=tree[left].sum+tree[right].sum;
    tree[indx].prop=tree[left].prop+tree[right].prop;
}

void update(int indx,int st,int en,int i,int j,int val)
{
    if(i>en || j<st)
        return;
    if(st>=i && en<=j)
    {
        tree[indx].sum+=((en-st+1)*val);
        tree[indx].prop+=val;
        return;
    }
    int left=indx*2;
    int right=(indx*2)+1;
    int mid=(st+en)/2;

    update(left,st,mid,i,j,val);

    update(right,mid+1,en,i,j,val);

    tree[indx].sum=tree[left].sum+tree[right].sum+(en-st+1)*tree[indx].prop;
}

int query(int indx,int st,int en,int i,int j,int carry=0)
{
    if(i>en || j<st)
        return 0;
    if(st>=i && en<=j)
        return tree[indx].sum+carry*(en-st+1);
    int left=indx*2;
    int right=(indx*2)+1;
    int mid=(st+en)/2;

    int val1=query(left,st,mid,i,j,carry+tree[indx].prop);
    int val2=query(right,mid+1,en,i,j,carry+tree[indx].prop);

    return val1+val2;
}

int findd(int x,int st,int en)
{
    int mid=(st+en)/2;
    if(v[mid]==x)
        return mid;
    if(v[mid]>x)
        findd(x,st,mid-1);
    else
        findd(x,mid+1,en);
}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);

    int a,b,c;
    while(t--)
    {
        sf("%d%d",&n,&q);
        int p=0;
        v.clear();
        v1.clear();
        v2.clear();
        q1.clear();
        set0(0,tree);
        FOR(i,0,n)
        {
            sf("%d%d",&a,&b);
            v1.pb(a);
            v2.pb(b);
            num[p++]=a;
            num[p++]=b;
        }
        FOR(i,0,q)
        {
            sf("%d",&c);
            q1.pb(c);
            num[p++]=c;
        }
        sort(num,num+p);

        v.pb(num[0]);
        FOR(i,1,p)
        {
            if(num[i]>num[i-1])
                v.pb(num[i]);
        }
        int x=v.size();
        init(1,0,x);
        FOR(i,0,n)
        {
            a=findd(v1[i],0,x);
            b=findd(v2[i],0,x);
            update(1,0,x,a,b,1);
        }
        pf("Case %d:\n",cases++);
        FOR(i,0,q)
        {
            a=findd(q1[i],0,x);
            int ans=query(1,0,x,a,a,0);

            pf("%d\n",ans);
        }


    }

    return 0;
}






















