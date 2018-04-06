#include<stdio.h>
int main(void)
{int a=0,b=0,c=0,d=0,e=0,m=0;
char ch;
ch=getchar();
 while((ch=getchar())!='\n')
    {
                          if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z'){a++;}
                           else if(ch==' '){b++;}
                           else if(ch>='0'&&ch<='9'){c++;}
                           else {d++;}
}
;
printf("%d\n",a);
printf("%d\n",b);
printf("%d\n",c);
printf("%d\n",d);}
