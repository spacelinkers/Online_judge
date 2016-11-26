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

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

map<int,int> Map;

int l1,l2;
char str1[120],str2[120];
int dp[120][120];
string str[120][120];


int print()
{
    int a,b;

    FOR(a,1,l1+1)
    {
        FOR(b,1,l2+1)
        {
            if(str1[a-1]==str2[b-1])
            {
                dp[a][b]=1+dp[a-1][b-1];
                str[a][b]=str[a-1][b-1]+str1[a-1];
            }
            else if(dp[a-1][b]>dp[a][b-1])
            {
                dp[a][b]=dp[a-1][b];
                str[a][b]=str[a-1][b];
            }
            else if(dp[a-1][b]<dp[a][b-1])
            {
                dp[a][b]=dp[a][b-1];
                str[a][b]=str[a][b-1];
            }
            else{
                dp[a][b]=dp[a-1][b];
                str[a][b]=min(str[a-1][b],str[a][b-1]);
            }
        }

    }
    return dp[l1][l2];
}

int main ()
{
    fop;
    int t,i,j,a,b,cases=1;


    sf("%d",&t);
    while(t--)
    {
        set0(0,dp);
        getchar();
        sf("%s%s",&str1,&str2);
        l1=strlen(str1);
        l2=strlen(str2);

        FOR(i,0,101)
        FOR(j,0,101)
            str[i][0]=str[0][i]="";

        int ans=print();
        if(ans==0) pf("Case %d: :(\n",cases++);
        else{
            pf("Case %d: ",cases++);
            cout<<str[l1][l2]<<endl;
        }
    }

    return 0;
}
















