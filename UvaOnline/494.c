#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c=0,d=0;
    char str[999999];
    while(gets(str)!=EOF)
    {
    a=strlen(str);
    for(b=0;b<a;b++)
    {
        if((str[b]>=65&&str[b]<=90)||(str[b]>=97&&str[b]<=122))
        {
            c++;
            if(c!=b){
                d++;
                c=b;
        }
        }
    }
    printf("%d\n",d);
    d=0;
    }
    return 0;
}
