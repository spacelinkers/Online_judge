#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define fop         freopen("in.txt","r",stdin)
#define set0(X,Y)   memset(Y,X,sizeof(Y))
#define mapp        map<string,int> mp;
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define FOr(I,B,A)  for(I=B;I>A;I--)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

int num[100010],N[300100],x,y;

void par(int node,int b,int e)
{
    if(b==e)
    {
        N[node]=num[b];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;
    par(l,b,mid);
    par(r,mid+1,e);
    N[node]=min(N[l],N[r]);
}
int ans(int node,int b,int e)
{
    if(x>e || y<b) return 100000000;
    if(b>=x && e<=y) return N[node];
    int l=node*2;
    int r=node*2+1;
    int mid=(e+b)/2;
    int p1=ans(l,b,mid);
    int p2=ans(r,mid+1,e);
    return min(p1,p2);
}

int main()
{
    //fop;
    int t,n,q,i,cases=1;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&q);
        FOR(i,1,n+1)
            sf("%d",&num[i]);
        par(1,1,n);
        pf("Case %d:\n",cases++);
        while(q--)
        {
            sf("%d%d",&x,&y);
            pf("%d\n",ans(1,1,n));
        }
    }



    return 0;
}










