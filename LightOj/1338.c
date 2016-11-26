#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,x,t,sum1=0,sum2=0,cases=0;
    char str1[120],str2[120];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(str1);
        gets(str2);
        a=strlen(str1);
        b=strlen(str2);
        for(x=0;x<a;x++)
        {
            str1[x]=tolower(str1[x]);
            if(str1[x]>='a' && str1[x]<='z')
                sum1=sum1+str1[x];
        }
        for(x=0;x<b;x++)
        {
            str2[x]=tolower(str2[x]);
            if(str2[x]>='a' && str2[x]<='z')
                sum2=sum2+str2[x];
        }
        if(sum1==sum2)
            printf("Case %d: Yes\n",++cases);
        else
            printf("Case %d: No\n",++cases);
        sum1=0,sum2=0;
    }
    return 0;
}
