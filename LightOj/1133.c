#include<stdio.h>
int main()
{
    int a,b,d,n,m,cases=0,t,tem;
    int n1[150],temp[150];
    char m1[150];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(d=0;d<n;d++)
        {
            scanf("%d",&n1[d]);
        }
        for(d=0;d<m;d++)
        {
            getchar();
            scanf("%c",&m1[0]);
            if(m1[0]=='P')
            {
                scanf("%d%d",&a,&b);
                tem=n1[a];
                n1[a]=n1[b];
                n1[b]=tem;
            }
            else if(m1[0]=='S')
            {
                scanf("%d",&a);
                for(b=0;b<n;b++)
                    n1[b]=n1[b]+a;
            }
            else if(m1[0]=='M')
            {
                scanf("%d",&a);
                for(b=0;b<n;b++)
                    n1[b]=n1[b]*a;
            }
            else if(m1[0]=='D')
            {
                scanf("%d",&a);
                for(b=0;b<n;b++)
                    n1[b]=n1[b]/a;
            }
            else if(m1[0]=='R')
            {
                for(a=0,b=n-1;a<n;a++,b--)
                    temp[a]=n1[b];
                for(a=0;a<n;a++)
                    n1[a]=temp[a];
            }
        }
        printf("Case %d:\n",++cases);
        for(a=0;a<n;a++)
        {
            if(a==n-1) printf("%d\n",n1[a]);
            else printf("%d ",n1[a]);
        }
    }
    return 0;

}
