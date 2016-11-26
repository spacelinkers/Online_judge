#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100050
vector<long>edges[MAX];


int main()
{
    long t,e,i,cases=0;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&e);
        long x,y,source[100020];
        for(i=1;i<=e;i++)
        {
            scanf("%ld%ld",&x,&y);
            source[i]=x;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        queue<int>Q;
        long taken[100050]={0},distance[MAX]={0},ans;
        for(long loop=1;loop<=e;loop++)
        {
            Q.push(source[loop]);
            taken[loop]=1;
            distance[loop]=0;
            while(!Q.empty())
            {
            long u=Q.front();
            for(i=0;i<edges[u].size();i++)
            {
                long v=edges[u][i];
                if(!taken[v])
                {
                    taken[v]=1;
                    distance[v]=distance[u]+1;
                    ans=distance[v];
                    Q.push(v);
                }
            }
            Q.pop();
        }
        }
        printf("Case %ld: %ld\n",++cases,ans);
        ans=0;
    }
    return 0;
}












