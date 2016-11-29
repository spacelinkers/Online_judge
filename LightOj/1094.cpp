#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 10000
vector<int>edges[MAX];
vector<int>cost[MAX];

int main()
{
    int t,n,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x,y,w,source;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            if(i==1) source=x;
            edges[x].push_back(y);
            edges[y].push_back(x);
            cost[x].push_back(w);
            cost[y].push_back(w);
        }
        queue<int>Q;
        Q.push(source);
        int taken[10000]={0};
        int distance[10000];
        taken[source]=1;
        distance[source]=0;
        while(!Q.empty())
        {
            int u=Q.front();
            for(int i=0;i<edges[u].size();i++)
            {
                int v=edges[u][i];
                if(!taken[v])
                {
                    distance[v]=distance[u]+cost[u][i];
                    taken[v]=1;
                    Q.push(v);
                }
            }
            Q.pop();
        }
        int max=distance[source];
        for(int i=1;i<n;i++)
        {
            if(max<distance[i])
                max=distance[i];
        }
        printf("Case %d: %d\n",++cases,max);
        for(int z=0;z<n;z++)
        {
            edges[z].clear();
            cost[z].clear();
        }
    }
    return 0;
}

