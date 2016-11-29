#include<stdio.h>
int main()
{
    long a,b,t,n,q,ak,bk,r=0;
    long low,high,mid;
    int nr[100005],qr[500005],ans[100];
    scanf("%ld",&t);
    for(a=0;a<t;a++)
    {
        scanf("%ld%ld",&n,&q);
        for(b=0;b<n;b++)
        {
            scanf("%ld",&nr[b]);
        }
        for(b=0;b<q;b++)
        {
            scanf("%ld%ld",&qr[r],&qr[r+1]);
            while(r!=1){
            low=nr[0];
            high=nr[n];
            while(low<=high)
            {
                mid=(low+high)/2;
                if(nr[mid]>qr[r])
                    high=mid-1;
                if(nr[mid]<qr[r])
                    low=mid+1;
                if(nr[mid]==qr[r]) ans[0]=mid;
            }
            r--;
            }
        }

    }
}
