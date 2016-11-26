#include<stdio.h>
int main()
{
    int t,m,n,a,cases=0,b=0;
    scanf("%d",&t);
    while(t--)
    {
        b=0;
        scanf("%d%d",&m,&n);
        if(m==1 || n==1)
        {
            if(m==1)
                printf("Case %d: %d\n",++cases,n);
            else
                printf("Case %d: %d\n",++cases,m);
        }
        else if(m==2 || n==2)
        {
            if(m!=2) n=m;

            if((n-5)%4==0)
            {
                n=n/2;
                n=(n+1)*2;
                printf("Case %d: %d\n",++cases,n);
                continue;
            }
            n=n/2;
            if(n%2==0)
                printf("Case %d: %d\n",++cases,n*2);
            else{
                n=(n+1)*2;
                printf("Case %d: %d\n",++cases,n);
            }
        }
        else{
            a=n*m;
            a=(a+1)/2;
            printf("Case %d: %d\n",++cases,a);
        }
    }
    return 0;
}
