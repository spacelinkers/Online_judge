#include<stdio.h>
int main()
{
    int x1,y1,z1,x2,y2,z2,mx1=0,my1=0,mz1=0,x,y,z;
    int a,b,c,t,n,cases=0,mx2=1001,my2=1001,mz2=1001;
    int vol;
    scanf("%d",&t);
    while(t--)
    {
        mx1=0,my1=0,mz1=0;
        mx2=1001,my2=1001,mz2=1001;
        scanf("%d",&n);
        while(n--)
        {
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        if(mx1<x1) mx1=x1;
        if(my1<y1) my1=y1;
        if(mz1<z1) mz1=z1;
        if(mx2>x2) mx2=x2;
        if(my2>y2) my2=y2;
        if(mz2>z2) mz2=z2;

        }
        if(mx1>mx2||my1>my2||mz1>mz2)
            printf("Case %d: 0\n",++cases);
        else
        {
        x=mx1-mx2;
        if(x<0) x=x*(-1);
        y=my1-my2;
        if(y<0) y=y*(-1);
        z=mz1-mz2;
        if(z<0) z=z*(-1);
        vol=x*y*z;
        printf("Case %d: %d\n",++cases,vol);
        }
    }
    return 0;
}

