#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 100000
vector<int>edges[MAX];

int main()
{
    int t,w,h,cases=0,p=1;
    int x,y,s1,s2,num[25][25];
    char str[25][25];
    scanf("%d",&t);
    while(t--)
    {
        p=1;
        scanf("%d%d",&w,&h);

        for(int i=1;i<=h;i++){
            getchar();
        for(int j=1;j<=w;j++)
        {
            scanf("%c",&str[i][j]);
            if(str[i][j]=='.')
                num[i][j]=p++;
            else if(str[i][j]=='#')
                num[i][j]=0;
            else{
                num[i][j]=p++;
                str[i][j]='.';
                s1=i,s2=j;
            }
        }
        }

        for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(str[i][j]=='.')
            {
                if(str[i][j]==str[i][j+1]){
                    x=num[i][j];y=num[i][j+1];
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
                if(str[i][j]==str[i][j-1]){
                    x=num[i][j];y=num[i][j-1];
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
                if(str[i][j]==str[i+1][j]){
                    x=num[i][j];y=num[i+1][j];
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
                if(str[i][j]==str[i-1][j]){
                    x=num[i][j];y=num[i-1][j];
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
            }
        }
        int source=num[s1][s2];
        queue<int>Q;
        int ans=1;
        int taken[1000]={0};
        taken[source]=1;
        Q.push(source);
        while(!Q.empty())
        {
        int u=Q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i];
            if(!taken[v])
            {
                ans++;
                taken[v]=1;
                Q.push(v);
            }
        }
            Q.pop();
        }
        printf("Case %d: %d\n",++cases,ans);
        ans=1;
    }
    return 0;
}


