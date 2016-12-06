#include<cstdio>
#include<iostream>
#include<string.h>
char str[1005][1005];
int r[]={0,0,-1,1,-1,-1,1,1},c[]={1,-1,0,0,-1,1,-1,1};
int p=0,i,j,maxn=0;

void rec(int i,int j,int n)
{
    int s,t,l;
    if(str[i][j]=='1')
    {
        str[i][j]='0';
        for(l=0;l<8;l++)
        {
            s=i+r[l];
            t=j+c[l];
            if(s>=0&&t>=0&&s<n&&t<n&&str[s][t]=='1')
            rec(s,t,n);
        }
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    int x,y,z,n,cases=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",&str[i]);
        }

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(str[i][j]=='1')
                {
                    rec(i,j,n);
                    p++;
                }

        }
        printf("Image number %d contains %d war eagles.\n",cases++,p);
        p=0;

    }
    return 0;
}

