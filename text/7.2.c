#include<stdio.h>
int main()
{
int i,j,a[20],m,n=0;
for(i=0;i<20;i++)scanf("%d",&a[i]);
for(i=0;i<20;i++)//每个数字进行比较
    {m=0;
    for(j=0;j<i;j++){if(a[i]!=a[j])m++;}
   if(m==i)n++;}
   printf("%d",n);
   }
