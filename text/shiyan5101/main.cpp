#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int n,i,i1,i2,j,k,s;
    scanf("%d",&n);//����Ҫ���������
    for(i=1;i<=n;i++)//����ѭ������
    {k=1;s=0;
    for(j=n-i;j>=0;j--)
            {printf(" ");}//ѭ����������ո�
     while(k<=i){s+=1;
                printf("%d",s);
                k=k+1;
                }
    k=k-2;
    while(k>0){s-=1;
              printf("%d",s);k=k-1;}
     printf("\n");//���ƻ���

    }
    for(i=1;i<n;i++){
s=0;k=1;
   for(j=i;j>=0;j--)
            {printf(" ");}//ѭ����������ո�
     while(k<=n-i){s+=1;
                printf("%d",s);
                k=k+1;
                }
    k=k-2;
    while(k>0){s-=1;
              printf("%d",s);k=k-1;}
     printf("\n");}//���ƻ���
}
