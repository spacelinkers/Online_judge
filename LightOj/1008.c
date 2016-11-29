#include<stdio.h>
#include<math.h>
int main()
{
    int t,a,b,m,n;
    long long s,x,y,corner,dis;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        scanf("%lld",&s);
        x=sqrt(s);
        y=x*x;
        if(y!=s) x=x+1;
        y=x-1;
        corner=2+(2*y);
        corner=(y*corner)/2;
        corner=corner+1;
        n=x;
        if(s>corner)
        {
            if(x%2==0)
            {
                dis=s-corner;
                a=x;
                b=x-dis;
            }
            else{
                dis=s-corner;
                b=x;
                a=x-dis;
            }
        }
        else if(s<corner)
        {
            if(x%2==0)
            {
                dis=corner-s;
                b=x;
                a=x-dis;
            }
            else{
                dis=corner-s;
                a=x;
                b=x-dis;
            }
        }
        else if(s==corner){
            printf("Case %d: %d %d\n",m,n,n);
            continue;
        }

        printf("Case %d: %d %d\n",m,a,b);
    }
    return 0;
}
