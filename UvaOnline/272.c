#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100000];
    int a,b,c=0;

    while(gets(str1)!=EOF)
    {
    b=strlen(str1);
    for(a=0;a<b;a++)
    {
        if(str1[a]=='"' && c==0)
        {
            printf("``");
            c++;
        }
        else if(str1[a]=='"' && c==1)
        {
            printf("''");
            c--;
        }
        else printf("%c",str1[a]);
    }
    printf("\n");
    }
    return 0;
}
