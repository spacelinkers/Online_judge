#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;

#define inf 1<<30
#define MAXX 100000
queue<int>Q;
vector<int>edges[MAXX];
int dis[MAXX];

int main()
{
    //freopen("in.txt","r",stdin);
    int NC,x,y,total,srt,en,cases=1;
    int ar[100000],a[100];
    while(1)
    {
        scanf("%d",&NC);
        if(!NC)
            break;
        memset(ar,0,sizeof(ar));
        total=0;
        while(NC--)
        {
            scanf("%d%d",&x,&y);
            if(!ar[x]){
                edges[x].clear();
                dis[x]=inf;
                ar[x]=1;
                a[total++]=x;
            }
            if(!ar[y]){
                edges[y].clear();
                dis[y]=inf;
                ar[y]=1;
                a[total++]=y;
            }
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        while(1)
        {
            scanf("%d%d",&srt,&en);
            if(!srt&&!en)
                break;
            Q.push(srt);
            dis[srt]=0;
            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                int j=edges[u].size();
                for(int i=0;i<j;i++)
                {
                    int v=edges[u][i];
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        Q.push(v);
                    }
                }
            }
            int ans=0;
            for(int i=0;i<total;i++)
            {
                if(dis[a[i]]<=en)
                    ans+=1;
                dis[a[i]]=inf;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases++,total-ans,srt,en);
        }
    }
    return 0;
}
