#include<stdio.h>
int main()
{
    int a,b,t,n,m,sum=0;
    scanf("%d",&t);
    for(a=1;a<=t;a++)
    {
        scanf("%d",&n);
        for(b=0;b<n;b++)
        {
            scanf("%d",&m);
            if(m<0) continue;
            sum=sum+m;
        }
        printf("Case %d: %d\n",a,sum);
        sum=0;
    }
    return 0;
}
