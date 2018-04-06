#include<stdio.h>
#include <math.h>
void main()
{
int n,i,j,flag;
for(i=2;i<=200;i++)
{
flag=1,j=2;
n=(int)sqrt((double)i);
while(flag && j<=n)
{
if(i%j==0)
flag=0;
j++;
}
if(flag)
printf("%d\t",i);

}
}
