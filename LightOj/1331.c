#include<stdio.h>
#include<math.h>
double cal(double a,double b,double r)
{
    double ansr;
    ansr=(a*a)+(b*b)-(r*r);
    ansr=ansr/(2*a*b);
    ansr=acos(ansr);
    return ansr;
}
int main()
{
    double r,r1,r2,r3,a,b,c,ans,ans1,ans2,ans3;
    double x,y,z;
    int t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        r1=y+z;
        r2=x+z;
        r3=x+y;
        r=(r1+r2+r3)/2;
        ans=r*(r-r1)*(r-r2)*(r-r3);
        ans=sqrt(ans);

        a=r2,b=r3;
        ans1=cal(a,b,r1);
        ans1=(ans1*x*x)/2;

        a=r1,b=r3;
        ans2=cal(a,b,r2);
        ans2=(ans2*y*y)/2;

        a=r1,b=r2;
        ans3=cal(a,b,r3);
        ans3=(ans3*z*z)/2;

        ans=ans-(ans1+ans2+ans3);
        printf("Case %d: %.10lf\n",++cases,ans);
    }
    return 0;
}
