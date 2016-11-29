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

int num[100010],N[300100];

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
    N[node]=N[l]+N[r];
}

void update(int node,int b,int e,int i,int neww)
{
    if(i>e || i<b) return;
    if(b>=i && e<=i)
    {
        N[node]=neww;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(e+b)/2;
    update(l,b,mid,i,neww);
    update(r,mid+1,e,i,neww);
    N[node]=N[l]+N[r];

}

int ans(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return N[node];
    int l=node*2;
    int r=node*2+1;
    int mid=(e+b)/2;
    int p1=ans(l,b,mid,i,j);
    int p2=ans(r,mid+1,e,i,j);
    return p1+p2;
}

int main()
{
    //fop;
    int t,n,q,k,cases=1,no,x,y,v;
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&q);
        FOR(k,1,n+1)
            sf("%d",&num[k]);
        par(1,1,n);
        pf("Case %d:\n",cases++);
        while(q--)
        {
            sf("%d",&no);
            if(no==1)
            {
                sf("%d",&x);
                pf("%d\n",num[x+1]);
                num[x+1]=0;
                update(1,1,n,x+1,0);
            }
            else if(no==2)
            {
                sf("%d%d",&x,&v);
                num[x+1]+=v;
                update(1,1,n,x+1,num[x+1]);
            }
            else if(no==3)
            {
                sf("%d%d",&x,&y);
                pf("%d\n",ans(1,1,n,x+1,y+1));
            }
        }
    }


    return 0;
}










