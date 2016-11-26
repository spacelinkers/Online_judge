#include<stdio.h>
int main()
{
    long a,b,c,d,t,m,cases=0;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&a,&b);
        if(a==1&&b==1)
            printf("Case %ld: 0\n",++cases);
        else if(a-b==0){
            a=a-1;
            if(a%3==0)
                printf("Case %ld: 0\n",++cases);
            else
                printf("Case %ld: 1\n",++cases);
        }
        else {
            a=a-1;
            b=b-1;
            if(a==0)
                d=b-a;
            else d=b-a+1;
            m=d;
            c=d/3;
            d=d-c;

            if(m<3){
            if(a%3==0 || b%3==0)
                printf("Case %ld: %ld\n",++cases,m-1);
            else
                printf("Case %ld: %ld\n",++cases,m);
            }
            else
                printf("Case %ld: %ld\n",++cases,d);
            }
    }
    return 0;
}
