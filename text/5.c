#include<stdio.h>
int main()
{
    int i=2,m,s,n=0;
    while(i<200)
    {
s=2;
for(;s<i;)
{if(i%s==0)n=n+1;s++;}
if(n==0)printf("%d%d\n",i,n);
    i+=1;}
}
