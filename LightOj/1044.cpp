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
#define FOr(I,B,A)  for(int I=B-1;I>=A;I--)
#define set0(X,Y)    memset(Y,X,sizeof(Y))
#define FOR(I,A,B)  for(int I=A;I<B;I++)
#define ll          long long
#define pb          push_back
#define MX          1000000
#define pf          printf
#define sf          scanf

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;

int n,l1;
char str[1010];
int dp[1010][1010],ans[1010][1010];

int pal(int i,int j)
{
    int d;
    d=j-i+1;
    d/=2;
    FOR(a,0,d+1){
        if(str[a+i]!=str[j-a])
            return 0;
        if(dp[i+1][j+1]!=0) return dp[i+1][j+1];
    }
    return 1;

}


int main ()
{
    fop;
    int t,cases=1;
    sf("%d",&t);
    while(t--)
    {
        //getchar();
        set0(0,dp);
        set0(0,ans);
        sf("%s",&str);
        l1=strlen(str);

        FOR(i,0,l1)
        {
            FOR(j,i,l1)
            {
                int q=pal(i,j);
                if(q==1) dp[i+1][j+1]=1;

            }
        }

        FOR(i,1,l1+1) ans[0][i]=1;
        int d;
        FOR(i,1,l1+1)
        {
            d=ans[i-1][i-1];
            FOR(j,i,l1+1)
            {
                if(i==1)
                {
                    if(dp[i][j]==1)
                        ans[i][j]=d+dp[i][j];
                    else
                    {
                        ans[i][j]=ans[i][j-1]+1;
                    }
                }
                else
                {
                    if(dp[i][j]==1)
                        ans[i][j]=min(ans[i-1][j],d+dp[i][j]);
                    else{
                        ans[i][j]=min(ans[i-1][j],ans[i][j-1]+1);
                    }
                }
            }
        }
        pf("Case %d: %d\n",cases++,ans[l1][l1]);

    }


    return 0;
}













