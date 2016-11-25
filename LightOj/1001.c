#include<stdio.h>
int main()
{
    int a,b,c,d=1,f=3,p=0,t,n;
    scanf("%d",&t);
    for(a=0;a<t;a++)
    {
        scanf("%d",&n);

        if(n==20){
            printf("10 10\n");
            continue;
        }
        if(n>10)
        {
           b=n/(4+d);
           b=b*(2+d);
           c=n-b;
        }
        else
        {
            if(f<0) f=3;
            if(f>3) p=0;
            b=n/(p+f);
            b=b*(p+1);
            c=n-b;
            f--,p++;
        }
        if(b==c)b=b-1,c=c+1;
        printf("%d %d\n",b,c);
    }
    return 0;
}
