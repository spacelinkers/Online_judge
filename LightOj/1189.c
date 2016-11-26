#include<stdio.h>
long long fact(long long  d)
{
    if(d<=1) return 1;
    else return (d*fact(d-1));
}
int main()
{
    long long a,b,c,d,n,t,cases=0,count=0;
    int ans[100];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(a=20;a>=0;a--)
        {
            d=a;
            b=fact(d);
            if(n>=b){
            n=n-b;
            ans[count++]=a;
            }
        }
        printf("Case %lld: ",++cases);
        if(n==0){
            for(a=count-1;a>=0;a--)
            {
                if(a==0)
                    printf("%lld!",ans[a]);
                else
                    printf("%lld!+",ans[a]);
            }
        }
        else printf("impossible");
        printf("\n");
        count=0;
    }
}
