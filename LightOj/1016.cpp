
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
#define set0(X,Y)    memset(Y,X,sizeof(Y))
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define FOr(I,B,A)  for(I=B;I>A;I--)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

map<int,int> Map;


int main ()
{
    //fop;
    int t,cases=1,i,n,w,x,y,num[50005];
    sf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&w);
        FOR(i,0,n)
        {
            sf("%d%d",&x,&y);
            num[i]=y;
        }
        sort(num,num+n);
        int p=1,j=0;
        FOR(i,1,n)
        {
            if(num[i]-num[j]>w)
            {
                p++;
                j=i;
            }
        }
        pf("Case %d: %d\n",cases++,p);
    }


    return 0;
}







