#include<stdio.h>//���ӳ�������
int main()
{
int n,s=1,i;
scanf("%d",&n);
for(i=2;i<=n;i++)s=2*(s+1);
    printf("%d",s);
}
