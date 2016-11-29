#include<stdio.h>
int main()
{
    int x1,y1,x2,y2,t,a,b,cases=0,m,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",++cases);
        while(m--)
        {
           scanf("%d%d",&p,&q);
           if(p>x1 && p<x2)
                if(q>y1 && q<y2)
                {
                    printf("Yes\n");
                }
                else printf("No\n");
            else printf("No\n");
        }
    }
    return 0;
}
