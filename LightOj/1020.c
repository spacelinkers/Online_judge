#include<stdio.h>
int main()
{
    long long t,n,cases=1,a=0,b;
    char str[10][10];
    scanf("%lld",&t);
    while(t--)
    {
        a=0;
        scanf("%lld%s",&n,&str[a++]);

        if(n==0){
            cases++;
            continue;
        }
        if(str[0][0]=='A' && n==1)
            printf("Case %lld: Bob\n",cases++);
        else if(str[0][0]=='A' && n==2)
            printf("Case %lld: Alice\n",cases++);
        else if(n==3)
            printf("Case %lld: Alice\n",cases++);
        else if(str[0][0]=='B' && n<=2)
            printf("Case %lld: Bob\n",cases++);
        else if(str[0][0]=='A')
        {
            b=n-3;
            if(b%2==0)
                printf("Case %lld: Alice\n",cases++);
            else
                printf("Case %lld: Bob\n",cases++);
        }
        else if(str[0][0]=='B')
        {
            b=n-4;
            if(b%2==0)
                printf("Case %lld: Alice\n",cases++);
            else
                printf("Case %lld: Bob\n",cases++);
        }
    }
    return 0;
}
