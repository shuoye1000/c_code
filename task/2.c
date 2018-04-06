#include<stdio.h>
int main()
{
int a[10];
int i,j,t;
for(i=0;i<10;i++)scanf("%d",&a[i]);
for(i=0;i<=9;i++){t=a[i];
                  j=i-1;
                 while(j>=0&&a[j]>t){a[j+1]=a[j];j--;}
                 a[j+1]=t;}
                 for(i=0;i<=9;i++)printf("%d  ",a[i]);}
