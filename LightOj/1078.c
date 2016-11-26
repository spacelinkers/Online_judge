#include<stdio.h>
int main()
{
    long long n,m,t,a,b,cases=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        a=m;
        for(b=1;;b++)
        {
            if(a%n!=0)
            {
                a=(a*10)+m;
            }
            else break;
        }
        printf("Case %lld: %lld\n",cases++,b);
    }
    return 0;
}
