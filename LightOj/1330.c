#include<stdio.h>
int main()
{
    int t,m,n,cases=0;
    int a,b,rmax,cmax,rsum=0,csum=0,c,r;
    int row[60],colm[60],mat[100][100],tem[100][100];
    scanf("%d",&t);
    while(t--)
    {
        rsum=0,csum=0;
        scanf("%d%d",&m,&n);
        rmax=n;
        cmax=m;
        for(a=0;a<m;a++)
        {
            scanf("%d",&row[a]);
            if(rmax<row[a]) rmax=row[a];
            rsum=rsum+row[a];
        }
        for(a=0;a<n;a++)
        {
            scanf("%d",&colm[a]);
            if(cmax<colm[a]) cmax=colm[a];
            csum=csum+colm[a];
        }
        if(cmax!=m || rmax!=n || rsum!=csum){
            printf("Case %d: impossible\n",++cases);
            continue;
        }
        for(r=0;r<m;r++)
        for(c=0;c<n;c++)
        {
            if(row[r]-1>=0 && colm[c]-1>=0)
            {
                mat[r][c]=1;
                row[r]=row[r]-1;
                colm[c]=colm[c]-1;
            }
            else mat[r][c]=0;
        }

        for(r=0;r<m-1;r++){
        for(c=0;c<n;c++)
        {
            if(mat[r][c]>mat[r+1][c])
            {
                a=r;
                for(c=0;c<n;c++){
                tem[a][c]=mat[a][c];
                mat[a][c]=mat[a+1][c];
                mat[a+1][c]=tem[a][c];
                }
            }
        }
        }
        for(r=0;r<m;r++)
        {
            for(c=0;c<n;c++)
                printf("%d ",mat[r][c]);
            printf("\n");
        }
    }
}










