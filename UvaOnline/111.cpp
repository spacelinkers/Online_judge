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

int num[25],num1[25],num2[25],l[25],n;

int lis()
{
    int i,j,ln=0;
    FOR(i,1,n+1)
        l[i]=1;
    FOR(i,1,n+1)
    FOR(j,i+1,n+1)
    {
        if(num1[j]>num1[i])
        {
            if(l[j]<l[i]+1)
                l[j]=l[i]+1;
        }
    }
    FOR(i,1,n+1)
    {
        if(ln<l[i])
            ln=l[i];
    }
    return ln;
}

int main()
{
    fop;
    int i,j,p;
    sf("%d",&n);
    FOR(i,1,n+1)
        sf("%d",&num[i]);
    while(sf("%d",&p)!=EOF)
    {
        num1[1]=p;
        num2[p]=1;
        FOR(i,2,n+1){
            sf("%d",&num1[i]);
            p=num1[i];
            num2[p]=i;
        }
        FOR(i,1,n+1)
        {
            num1[i]=num[num2[i]];
        }
        pf("%d\n",lis());

    }

    return 0;
}











