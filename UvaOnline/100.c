#include<stdio.h>
int main()
{
    long long i,a,j,x,y,d,max=0;
    while(scanf("%lld%lld",&x,&y)!=EOF){
    if(x>y){
        d=x;
        x=y;
        y=d;
    }
    for(a=x;a<=y;a++)
    {
        j=0;
        i=a;
    while(i!=1)
    {
    if(i%2==0)
       {
        i=i/2;
        j++;
       }
    else{
        i=(3*i)+1;
        j++;
        }
    }
    if(max<j+1) max=j+1;
    }
    printf("%lld %lld %lld\n",x,y,max);
    max=0;
    }
    return 0;

}
