#include<stdio.h>
int main()
{int a,b,k,c,x,y,n;
scanf("%d%d",&a,&b);
x=a;y=b;
if(a>b){k=a;a=b;b=k;}//��֤a����b
while(b!=0){c=a;
            a=b;
            b=c%b;}
            printf("���Լ��Ϊ��%d\n",a);
 n=x*y/a;
 printf("��С������Ϊ��%d",n);}
