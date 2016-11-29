#include<stdio.h>
int main()
{
    long long a,b,d,t,r,c,r1,c1,r2,c2,cases=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
        r=r1-r2;
        if(r<0) r=r*(-1);
        c=c1-c2;
        if(c<0) c=c*(-1);
        if(r==c)
            printf("Case %lld: 1\n",++cases);
        else if(r%2==0 && c%2==0)
            printf("Case %lld: 2\n",++cases);
        else if(r%2!=0 && c%2!=0)
            printf("Case %lld: 2\n",++cases);
        else
        printf("Case %lld: impossible\n",++cases);
    }
    return 0;
}
