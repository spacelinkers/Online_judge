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


int main ()
{
    //fop;
    int t,n,a,cases=1;

    sf("%d",&t);
    while(t--)
    {
        int mins=0,sum=0;
        sf("%d",&n);
        FOR(i,0,n)
        {
            sf("%d",&a);
            if(a<0) mins++;
            if(a<0) a*=-1;
            sum+=a;
        }
        pf("Case %d: ",cases++);
        if(mins==n) pf("inf\n");
        else
        {
            n=n-mins;
            int b=__gcd(n,sum);
            if(b!=0)
                n/=b,sum/=b;
            pf("%d/%d\n",sum,n);
        }
    }


    return 0;
}













