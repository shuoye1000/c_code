#include<stdio.h>//��С�����������������ڵ�λ��
int main()
{int a[100],i,j,m,n;
printf("����������ĳ���");
scanf("%d",&n);
printf("����������������");
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
printf("�����Ϊ;");
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
