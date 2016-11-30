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

ll p[100000];

int main()
{
    //fop;
    int t,n,m;
    sf("%d",&t);
    while(t--)
    {
        int brk=1;
        sf("%d",&n);
        int i=9,c=0;
        while(n>1)
        {
            while(n%i==0)
            {
                n/=i;
                p[i]+=1;
            }
            i--;
            if(i==1)
            {
                if(n>9) brk=0;
                break;
            }
        }
        sort(p,p+c);
        if(brk==0) pf("-1\n");
        else{
            for(i=0;i<c;i++)
                pf("%d",p[i]);
            pf("\n");
        }
    }




    return 0;
}










