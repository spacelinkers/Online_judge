#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
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

int a1[70];



int main()
{
    fop;
    struct st{
    int a1,a2,a3;
    };
    struct st N[70];
    int a[3],n,i,p;
    while(sf("%d",&n)!=EOF)
    {
        p=0;
        FOR(i,0,n)
        {
            sf("%d%d%d",&a[0],&a[1],&a[2]);
            sort(a,a+3);
            N[p].a1=a[0];N[p].a2=a[1];N[p].a3=a[2];
            p++;
            N[p].a1=a[1];N[p].a2=a[2];N[p].a3=a[0];
            p++;
        }
        sort(N.a1,N.a1+p-1);
    }


    return 0;
}










