#include<cstdio>
#include<string.h>
#include<math.h>

#define pi 3.141592654

int main()
{
    int t,n,cases=0;
    double r,a1,a2,a3,n1,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&r);
        scanf("%d",&n);
        n1=n;
        a1=(sin(pi/n1));
        a2=r*a1;
        a3=1+a1;
        ans=a2/a3;
        printf("Case %d: %lf\n",++cases,ans);
    }
    return 0;
}
