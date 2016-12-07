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

vector<int>E[MX];
queue<int>Q;
int vis[MX],ans=0;

int main()
{
    fop;
    int t,i,j,x,y,q=0;
    char a,str[10],ch[30];
    sf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        sf("%c",&a);
        int k=0;
        for(i='A';i<=a;i++)
            ch[k++]=i;
        getchar();
        while(1)
        {
            gets(str);

            if(strlen(str)==0)
                break;
            FOR(j,0,k)
            {
                if(str[0]==ch[j])
                    x=j;
                if(str[1]==ch[j])
                    y=j;
            }
            E[x].pb(y);
            E[y].pb(x);
        }

        set0(-1,vis);
        FOR(i,0,k-1)
        {
            int src=i;
            Q.push(src);
            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                int len=E[u].size();
                FOR(j,0,len)
                {
                    int v=E[u][j];
                    if(vis[v]==-1)
                    {
                        vis[v]=0;
                        Q.push(v);
                        q++;
                    }
                }
            }
            if(q!=0) ans++;
            while(!Q.empty())
                Q.pop();
            q=0;
        }
        pf("%d\n",ans);
        if(t!=0) pf("\n");
        FOR(i,0,k)
            E[i].clear();
        ans=0,q=0;
    }


    return 0;
}









