#include<stdio.h>
int main()
{
int i,a[10],m;
for(i=0;i<10;i++)scanf("%d",&a[i]);
for(i=0;i<5;i++){m=a[i];a[i]=a[9-i];a[9-i]=m;}
for(i=0;i<10;i++)i+printf("%d",a[i]);
}
