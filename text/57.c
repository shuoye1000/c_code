# include<stdio.h>
void main()
{
int a[10],i,j,k;
for(i=0;i<=9;i++)
scanf("%d",&a[i]);
for(i=0;i<=9;i++)
for(j=i+1;j<=9;j++)
if (a[i]<a[j])
{
k=a[i];
a[i]=a[j];
a[j]=k;
}
printf("%d ",a[9]);
}
