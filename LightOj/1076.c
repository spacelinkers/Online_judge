#include<stdio.h>
int main()
{
    int a,b,c,d,con=0,sum=0,max,mid,tem,t,i;
    int n[1000000];
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        for(c=0;c<a;c++)
        {
            scanf("%d",&n[c]);
            d=d+n[c];
            if(c==0) max=n[0];
            if(n[c]>max)
                max=n[c];
        }

        tem=100000000;
        while(max<=d){
            mid=(max+d)/2;
        for(c=0;c<a;c++)
        {
            sum=sum+n[c];
            if(sum>mid)
            {
                c--;
                con++;
                sum=0;
            }
            else if(sum<=mid)
                if(c==a-1){
                    con++;
                }
        }
        if(con<=b)
        {
            if(tem==mid) break;
            if(mid<tem)
            tem=mid;
            d=mid-1;

        }
        else max=mid+1;
        con=0;
        sum=0;
        }
        printf("Case %d: %d\n",i,tem);
        d=0;
        con=0;
        sum=0;
        }
        return 0;
}

