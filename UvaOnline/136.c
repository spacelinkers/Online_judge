#include <stdio.h>
int main ()
{
    long long j=1,k,l;
    for(l=1;j<=1500;l++)
    {
     k=l;
    while(k%2==0)
    {
        k=k/2;
    }
    while(k%3==0)
    {
        k=k/3;
    }
    while(k%5==0)
    {
        k=k/5;
    }
    if(k<7){
     if(j==1500)
       printf("The 1500'th ugly number is %lld.",l);
       j++;
       }
    }
}


