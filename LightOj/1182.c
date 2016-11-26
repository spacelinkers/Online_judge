#include<stdio.h>
int main()
{
    long long a=0,b,count=0,t,n,cases=0;
    scanf("%lld",&t);
    while(t--)
    {
        a=0;
        count=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                count++;
                n=n-1;
                n=n/2;
            }
        }

        if(count%2==0)
            printf("Case %lld: even\n",++cases);
        else
            printf("Case %lld: odd\n",++cases);
    }
    return 0;
}
