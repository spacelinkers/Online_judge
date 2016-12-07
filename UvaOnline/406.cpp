#include<cstdio>
#include<string.h>
#include<math.h>

int main()
{
    int n,c,count=1,p=0;
    int prime[1000];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&c);
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==2||i==3)
            {
                prime[count++]=i;
                continue;
            }
            int m=sqrt(i);
            for(int j=2;j<=m;j++)
            {
                if(prime[j]>m)
                    break;
                else if(i%prime[j]==0)
                {
                    p++;
                    break;
                }
            }
            if(p==0)
                prime[count++]=i;
            p=0;

        }
        printf("%d %d:",n,c);
        int mid;
        count=count-1;
        if(count%2==0)
        {
            c=c*2;
            mid=count-c;
            mid=mid/2;
        }
        else
        {
            c=(c*2)-1;
            mid=count-c;
            mid=mid/2;
        }
        if(mid<=0)
            for(int i=1;i<=count;i++)
                printf(" %d",prime[i]);
        else
            for(int i=mid+1;i<=mid+c;i++)
                printf(" %d",prime[i]);
        count=1,p=0;
        printf("\n\n");
    }
    return 0;
}
