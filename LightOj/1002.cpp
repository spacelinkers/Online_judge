#include<cstdio>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
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

vector<int>E[MX],C[MX];
int ans,maxx=0;

int rec(int k,int l,int ln,int src)
{
    int v=E[k][l];
    if(v==src) return maxx;
    M=rec(k,l+1,ln,src);
    if(maxx<M) maxx=M;
    return maxx;
}

int main()
{
    fop;
    int t,n,m,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        sf("%d%d",&n,&m);
        int i;
        FOR(i,0,m)
        {
            sf("%d%d%d",&x,&y,&z);
            E[x].pb(y);
            E[y].pb(x);
            C[x].pb(z);
        }
        int src;
        sf("%d",&src);
        int i,j;
        FOR(i,0,n)
        {
            int u=E[i];
            int ln=E[i].size();
            if(src==u) ans=0;
            else{
                FOR(j,0,ln)
                {
                    rec(i,j,ln,src);
                }
            }
        }
    }



    return 0;
}









