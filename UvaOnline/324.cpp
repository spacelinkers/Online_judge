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



int main()
{
    //fop;
    int n,i,j,cont,x,num[101000],p[15];
    while(sf("%d",&n)!=EOF)
    {
        set0(0,p);
        if(n==0) break;
        num[0]=1;
        cont=1;
        int temp=0;
        FOR(i,1,n+1)
        {
            FOR(j,0,cont)
            {
                int x=num[j]*i+temp;
                num[j]=x%10;
                temp=x/10;
            }
            while(temp>0)
            {
                num[cont]=temp%10;
                temp/=10;
                cont++;
            }
        }
        for(i=cont-1;i>=0;i--)
            p[num[i]]++;
        pf("%d! --\n",n);
        for(i=0;i<10;i++)
        {
            if(p[i]<10)
            {
                if(i==0 || i==5) pf("   (%d)    %d    ",i,p[i]);
                else if(i==4 || i==9) pf("(%d)    %d\n",i,p[i]);
                else pf("(%d)    %d    ",i,p[i]);
            }
            if(p[i]>=10 && p[i]<100)
            {
                if(i==0 || i==5) pf("   (%d)   %d    ",i,p[i]);
                else if(i==4 || i==9) pf("(%d)   %d\n",i,p[i]);
                else pf("(%d)   %d    ",i,p[i]);
            }
            if(p[i]>=100)
            {
                if(i==0 || i==5) pf("   (%d)  %d    ",i,p[i]);
                else if(i==4 || i==9) pf("(%d)  %d\n",i,p[i]);
                else pf("(%d)  %d    ",i,p[i]);
            }
        }
    }


    return 0;
}









