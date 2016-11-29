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


ll dp[60][60],num[100005];
ll l1,l2,l3;

struct info {
    ll prop, sum;
} tree[100005 * 3];

void init(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node].sum = 0;
        tree[node].prop = 0;
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    ll Left = node * 2;
    ll Right = (node * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;

}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum +carry*(e - b + 1);
    ll Left = node*2;
    ll Right = (node*2)+1;
    ll mid = (b+e)/2;

    ll p1 = query(Left,b,mid,i,j,carry+tree[node].prop);
    ll p2 = query(Right,mid+1,e,i,j,carry+tree[node].prop);

    return p1 + p2;
}

int main ()
{
    fop;
    ll t,cases=1;
    sf("%lld",&t);
    ll n,q,x,y,v,a;
    while(t--)
    {
        set0(0,tree);
        sf("%lld%lld",&n,&q);
        FOR(i,0,n)
            num[i]=0;
        pf("Case %lld:\n",cases++);
        init(1,0,n-1);
        while(q--)
        {
            sf("%lld",&a);
            if(a==0)
            {
                sf("%lld%lld%lld",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else if(a==1)
            {
                sf("%lld%lld",&x,&y);
                ll ans=query(1,0,n-1,x,y,0);
                pf("%lld\n",ans);
            }
        }
    }



    return 0;
}




















