#include<stdio.h>
int main()
{
    int a,b,t;
    double r,z,y,x,pi;
    pi=2*acos(0.0);
    scanf("%d",&t);
    for(a=1;a<=t;a++)
    {
        scanf("%lf",&r);
        if(r==0){
            printf("Case %d: 0\n",a);
            continue;
        }
        y=2*r;
        z=y*y;
        y=pi*(r*r);
        x=z-y;
        printf("Case %d: %.2lf\n",a,x);
    }
    return 0;
}
