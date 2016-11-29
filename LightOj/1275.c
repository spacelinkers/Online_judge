#include<stdio.h>
int main()
{
    long a,t,tem;
    double b,n,c,ans;
    scanf("%ld",&t);
    for(a=1;a<=t;a++)
    {
        scanf("%lf%lf",&n,&c);
        if(n==0){
            printf("Case %d: 0\n",a);
            continue;
        }
        ans=c/(2*n);
        tem=ans;
        b=ans-tem;
        if(b>0.5)
            printf("Case %d: %d\n",a,tem+1);
        else printf("Case %d: %d\n",a,tem);
    }
    return 0;
}
