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
#define FOr(I,B,A)  for(I=B-1;I>=A;I--)
#define FOR(I,A,B)  for(I=A;I<B;I++)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;

char str1[101],str2[1010];
ll l1,l2,dp[101][101],ans=0;


int main ()
{
    fop;
    ll t,i,j,cases=1;
    sf("%lld",&t);
    while(t--)
    {
        //set0(-1,dp);
        sf("%s",&str1);
        l1=strlen(str1);

        FOR(i,0,l1)
        FOR(j,0,l1)
        {
            if(i==j) dp[i][j]=1;
            else dp[i][j]=0;
        }

        FOR(i,1,l1)
        {
            FOr(j,i,0)
            {
                dp[i][j]=dp[i][j+1]+dp[i-1][j]-dp[i-1][j+1];
                if(str1[i]==str1[j])
                    dp[i][j]+=1+dp[i-1][j+1];
            }
        }

        pf("Case %lld: %lld\n",cases++,dp[l1-1][0]);

    }


    return 0;
}
















