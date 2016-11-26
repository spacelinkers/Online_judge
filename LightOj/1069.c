#include<stdio.h>
int main()
{
    int a,b,cases=0,time,t,trv;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a==0){
            printf("Case %d: 0\n",++cases);
            continue;
        }
        if(a>b){
            trv=a-b;
            trv=trv+a;
        }
        else trv=b;
        time=19+(trv*4);
        printf("Case %d: %d\n",++cases,time);
    }
    return 0;
}
