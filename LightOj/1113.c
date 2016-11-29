#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000][1000],str1[10][10];
    int a,b=0,cases=0,t,l,n=0;
    scanf("%d",&t);
    while(t--)
    {
        strcpy(str[0],"http://www.lightoj.com/");
        printf("Case %d:\n",++cases);
        for(a=0;;a++)
        {
            scanf("%s",str1[0]);
            l=strlen(str1);
            if(l==5)
            {
                n++;
                scanf("%s",str[n]);
                printf("%s\n",str[n]);
            }
            else if(l==4 && str1[0][0]=='Q')
                break;
            else if(l==4 && str1[0][0]=='B')
            {
                n--;
                if(str[n][0]=='\0'){
                    printf("Ignored\n");
                    n++;
                    }
                else printf("%s\n",str[n]);
            }
            else if(l==7)
            {
                n++;
                if(str[n][0]=='\0'){
                    printf("Ignored\n");
                    n--;
                    }
                else printf("%s\n",str[n]);
            }

        }
    }
    return 0;
}
