#include<stdio.h>
int main()
{
    long long a[102],b,c,d,i,j,sum=0,z[102];
    for(i=0;;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==0) break;
    }
    for(i=0;;i++)
    {
        b=a[i];
        if(b==0) break;
        for(j=1;;j++)
        {
            c=b;
            if(c%j==0)
            {
                d=c/j;
                if(j<=d) sum=sum+j+d;
                else break;
            }
            if(j>d) break;
        }
        z[i]=sum-b;
        sum=0;
    }
    printf("PERFECTION OUTPUT\n");
    for(i=0;;i++)
    {
        if(a[i]==0){
            printf("END OF OUTPUT\n",z[i]);
            break;
        }
        else if(z[i]<a[i]) printf("%5lld  DEFICIENT\n",a[i]);
        else if(z[i]==a[i]) printf("%5lld  PERFECT\n",a[i]);
        else if(z[i]>a[i])printf("%5lld  ABUNDANT\n",a[i]);
    }
    return 0;
}
