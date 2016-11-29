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

int dp[100][100],num,n,q;

vector<int>v1,v2,v,q1;
queue<int>P;

struct info{
    int sum,prop;
}tree[100010*3];

void init(int indx,int st,int en)
{
    if(st==en)
    {
        tree[indx].sum=0;
        tree[indx].prop=0;
        return ;
    }
    int left=indx<<1;
    int right=(indx<<1)+1;
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
        if(st==en){
        tree[indx].sum=((en-st+1)*val);
       // tree[indx].prop+=val;
        return ;}
    }
    int left=indx<<1;
    int right=(indx<<1)+1;
    int mid=(st+en)>>1;

    update(left,st,mid,i,j,val);
    update(right,mid+1,en,i,j,val);

    tree[indx].sum=tree[left].sum+tree[right].sum+(en-st+1)*tree[indx].prop;
}

int query(int indx,int st,int en,int i,int j,int carry)
{
    if(i>en || j<st)
        return 0;
    if(st>=i && en<=j)
        return tree[indx].sum+carry*(en-st+1);
    int left=indx<<1;
    int right=(indx<<1)+1;
    int mid=(st+en)>>1;

    int val1=query(left,st,mid,i,j,carry+tree[indx].prop);
    int val2=query(right,mid+1,en,i,j,carry+tree[indx].prop);

    return val1+val2;
}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);

    int a,b,c,p;
    while(t--)
    {
        set0(0,tree);
        sf("%d%d",&n,&q);
        init(1,0,n-1);
        pf("Case %d:\n",cases++);
        int cont=0,prx=0;
        FOR(i,0,q)
        {
            sf("%d",&a);
            if(a==1)
            {
                sf("%d%d%d",&b,&c,&p);
//                if(cont!=0)
//                    update(1,0,n-1,b,c,-prx);
                update(1,0,n-1,b,c,p);
                prx=p;
                cont=1;
            }
            else if(a==2)
            {
                sf("%d%d",&b,&c);
                int ans=query(1,0,n-1,b,c,0);
                int x=c-b+1;
                int z=__gcd(ans,x);
                ans/=z;
                x/=z;
                if(x!=1)
                    pf("%d/%d\n",ans,x);
                else
                    pf("%d\n",ans);
            }
        }
    }


    return 0;
}






















