#include<stdio.h>
int main(){
int n;
printf("�������ַ��ĸ�����");
scanf("%d",&n);
int a,b=0,d;
char c;
for(a=0;a<=n;a++){c=getchar();
                  if(c>='0'&&c<='9'){d=c-'0';b=b+d;}}
                  printf("%d",b);
}
