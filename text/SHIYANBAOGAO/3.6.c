#include<stdio.h>//从小到大排序后查找数所在的位置
int main()
{int a[100],i,j,m,n;
printf("请输入数组的长度");
scanf("%d",&n);
printf("请输入数进行排序");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++)
{if(a[j]>a[j+1]){
        m=a[j];
        a[j]=a[j+1];
        a[j+1]=m;}}}
printf("排序后为;");
for(i=0;i<n;i++)printf("%d ",a[i]);
int first,mid,last;
scanf("%d",&b);
if(b==a[n/2])printf("%d",n/2);
mid=n/2;
while(b!=a[mid]){
                if(b>a[n/2])n=n+n/2;
                else n=n-n/2;
}
printf("%d",n);
}
