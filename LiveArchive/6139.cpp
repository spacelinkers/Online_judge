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

int num[100010],tree[100010*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=num[b];
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node]=tree[left]*tree[right];
}

void update(int node,int b,int e,int i,int newval)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i)
    {
        tree[node]=newval;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newval);
    update(right,mid+1,e,i,newval);
    tree[node]=tree[left]*tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 1;
    if(b>=i && e<=j)
        return tree[node];
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)/2;
    int val1=query(left,b,mid,i,j);
    int val2=query(right,mid+1,e,i,j);

    return val1*val2;
}


int main ()
{
    //fop;
    int n,q,p,neww,b,e,newval;
    char chr;
    while(sf("%d%d",&n,&q)!=EOF)
    {
        FOR(i,1,n+1)
        {
            sf("%d",&num[i]);
            if(num[i]>0)
                num[i]=1;
            else if(num[i]<0)
                num[i]=-1;
            else num[i]=0;
        }
        set0(0,tree);
        init(1,1,n);
        while(q--)
        {
            getchar();
            sf("%c",&chr);
            if(chr=='C')
            {
                sf("%d%d",&p,&neww);
                if(neww>0)
                    newval=1;
                else if(neww<0)
                    newval=-1;
                else newval=0;
                update(1,1,n,p,newval);
            }
            if(chr=='P')
            {
                sf("%d%d",&b,&e);
                int ans=query(1,1,n,b,e);
                if(ans<0) pf("-");
                else if(ans>0) pf("+");
                else pf("0");
            }
        }
        pf("\n");

    }
    return 0;
}













