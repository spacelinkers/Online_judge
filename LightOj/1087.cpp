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


int tree[4*200005];

vector<int>V;
queue<int>P;

void update(int indx,int st,int en,int pos,int val)
{
    if(pos==st && pos==en)
    {
        tree[indx]+=val;
        return;
    }

    int left=indx<<1;
    int right=(indx<<1)+1;
    int mid=(st+en)/2;

    if(pos<=mid)
        update(left,st,mid,pos,val);
    else
        update(right,mid+1,en,pos,val);

    tree[indx]=tree[left]+tree[right];
}

int query(int indx,int st,int en,int pos)
{
    tree[indx]--;
    if(st==en)
        return st;
    int left=indx<<1;
    int right=(indx<<1)+1;
    int mid=(st+en)/2;

    if(pos<=tree[left])
        return query(left,st,mid,pos);
    else
        return query(right,mid+1,en,pos-tree[left]);

}

int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);

    while(t--)
    {
        sf("%d%d",&n,&q);
        int all=n+q;
        int pos=n;
        int tem=n;
        V.clear();
        set0(0,tree);
        FOR(i,1,n+1)
        {
            sf("%d",&num);
            V.pb(num);
            update(1,1,all,i,1);
        }
        pf("Case %d:\n",cases++);
        while(q--)
        {
            int b;
            char a[4];
            sf("%s",&a);
            sf("%d",&b);
            if(a[0]=='c')
            {
                if(b>pos)
                {
                    pf("none\n");
                    continue;
                }
                pos--;
                int ans=query(1,1,all,b);
                pf("%d\n",V[ans-1]);
            }
            else{
                V.pb(b);
                pos++;
                tem++;
                update(1,1,all,tem,1);
            }
        }
    }




    return 0;
}






















