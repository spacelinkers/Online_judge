#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,t,q,two=0,five=0,low,high,r=0,mid,tem=1000000000;
    scanf("%d",&t);
    for(b=0;b<t;b++)
    {
        five=0,two=0,tem=1000000000;
        scanf("%d",&q);
        low=0;
        high=q*5;
        while(low<=high)
        {
            five=0,two=0;
            mid=(low+high)/2;
            if(mid<=25){
            for(a=5;a<=mid;a=a+5)
            {
                d=a;
                while(d%5==0)
                {
                    d=d/5;
                    five++;
                }
            }
            }
            else{
                d=mid/25;
                d=d*25;
                a=d;
                for(c=1;;c++)
                {
                    r=pow(5,c);
                    if(r>d){
                        c--;
                        break;
                    }
                }
                r=1-pow((1/5),c);
                r=r/(1-(1/5));
                five=d*r;

                a=mid-d;
                a=a/5;
                five=five+a;
            }
            if(five>0)
            {
                if(tem==mid) break;
                if(five==q){
                if(tem>mid)
                    tem=mid;
                high=mid-1;
                }
                else low=mid+1;
            }
            else low=mid+1;
        }
        if(tem==1000000000) printf("Case %d: impossible\n",b+1);
        else printf("Case %d: %d\n",b+1,tem);
    }
    return 0;
}
