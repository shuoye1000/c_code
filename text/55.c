#include<stdio.h>
int main(){
int n;
printf("�������ַ��ĸ�����");
scanf("%d",&n);
int a,b=0,d;
char c;
for(a=0;a<=n;a++){c=getchar();
                  if((c-'A'>=0)&&(c-'A')<=26)c=c+32;
                   printf("%c",c);}

}
