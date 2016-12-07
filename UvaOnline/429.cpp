#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;

#define MAXX 10000
vector<int>E[MAXX];
queue<int>Q;
char dic[1000][1000];
int vis[1000],dis[1000];

int main()
{
    freopen("in.txt","r",stdin);
    int t,x,y,flag=0,l,u,v,ans=0;
    char a[100],b[100],c[100];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        for(l=1;;l++)
        {
            scanf("%s",&dic[l]);
            if(dic[l][0]=='*')
                break;
        }
        int z=l-1;
        for(int i=1;i<z;i++)
        {
            x=i;
            int u=strlen(dic[i]);
            int v=strlen(dic[i+1]);
            if(u==v)
            {
                for(int j=i+1;j<=z;j++){
                for(int n=0;n<u;n++)
                    if(dic[i][n]!=dic[j][n])
                        flag++;
                if(flag==1){
                    y=j;
                    E[x].push_back(y);
                    E[y].push_back(x);

                }flag=0;
                }
            }
        }
        getchar();
        int str,en,flag=0;
        while(gets(c))
        {
            if(strlen(c)<=0) break;
            sscanf(c,"%s %s",&a,&b);
            for(int i=1;i<=z;i++)
            {
                if(!strcmp(dic[i],a)) str=i;
                if(!strcmp(dic[i],b)) en=i;
            }
            memset(vis,0,sizeof(vis));
            memset(dis,0,sizeof(dis));
            Q.push(str);
            vis[str]=-1;
            dis[str]=1;
            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                int ln=E[u].size();
                for(int i=0;i<ln;i++)
                {
                    int v=E[u][i];
                    if(!vis[v])
                    {
                        dis[v]=dis[u]+1;
                        vis[v]=-1;
                        ans=dis[v];
                        Q.push(v);
                    }
                    if(v==en)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            printf("%s %s %d\n",a,b,ans-1);
            while(!Q.empty())
                Q.pop();
            ans=0,flag=0;
        }
        for(int i=1;i<=z;i++)
            E[i].clear();
        if(t!=0) printf("\n");
    }
    return 0;
}
