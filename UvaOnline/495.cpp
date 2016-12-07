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
   // fop;
    int n,i,j,q=0,a[2000],b[2000],c[2000],num;
    while(sf("%d",&n)!=EOF)
    {
        set0(0,a);
        set0(0,b);
        set0(0,c);
        a[0]=0;
        b[0]=1;
        q=1;
        FOR(i,1,n)
        {
            int tmp=0;
            for(j=0;j<q;j++)
            {
                int num=a[j]+b[j]+tmp;
                if(num>9)
                {
                    tmp=num/10;
                    c[j]=num%10;
                }
                else{
                    c[j]=num;
                    tmp=0;
                }
            }
            int z=q;
            if(tmp!=0)
            {
                c[j]=tmp;
                q++;
            }
            for(j=0;j<z;j++)
            {
                a[j]=b[j];
            }
            for(j=0;j<q;j++)
            {
                b[j]=c[j];
            }
        }
        if(n==1) c[0]=1;
        pf("The Fibonacci number for %d is ",n);
        for(j=q-1;j>=0;j--)
            pf("%d",c[j]);
        pf("\n");
    }


    return 0;
}










