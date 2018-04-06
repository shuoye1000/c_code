#include<stdio.h>
int main()
{int a,b,k,c,x,y,n;
scanf("%d%d",&a,&b);
x=a;y=b;
if(a>b){k=a;a=b;b=k;}//保证a大于b
while(b!=0){c=a;
            a=b;
            b=c%b;}
            printf("最大公约数为：%d\n",a);
 n=x*y/a;
 printf("最小公倍数为：%d",n);}
