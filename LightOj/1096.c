#include<stdio.h>
f(long long n, int a,int b,int c)
{
    long long x;
    if(n<=2) return 0;
    x=(a*f(n-1,a,b,c))+(b*f(n-3,a,b,c))+c;
    return x;
}
int main()
{
    long long n,cases,t,ans;
    int a,b,c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%d%d%d",&n,&a,&b,&c);
        ans=f(n,a,b,c);
        printf("%lld\n",ans);
    }
}
