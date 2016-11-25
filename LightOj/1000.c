#include<stdio.h>
int main()
{
    int a,b,t,m,n;
    scanf("%d",&t);
    for(n=1;n<=t;n++)
    {
        scanf("%d%d",&a,&b);
        m=a+b;
        printf("Case %d: %d\n",n,m);
    }
    return 0;
}
