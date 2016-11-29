#include<stdio.h>
int main()
{
    long long a,b,c,ans;
    int cases=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>=b && a>=c){
            if((a*a)==(b*b)+(c*c))
                printf("Case %d: yes\n",++cases);
            else printf("Case %d: no\n",++cases);
        }
        else if(b>=c && b>=a){
            if((b*b)==(c*c)+(a*a))
                printf("Case %d: yes\n",++cases);
            else printf("Case %d: no\n",++cases);
        }
        else if(c>=b && c>=a){
            if((c*c)==(b*b)+(a*a))
                printf("Case %d: yes\n",++cases);
            else printf("Case %d: no\n",++cases);
        }
    }
    return 0;
}
