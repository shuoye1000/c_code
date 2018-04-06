#include<stdio.h>
int main()
{
int a,b;char c;
scanf("%d",&a);
b=a/10;
switch(b){
case(10):c='A';break;
case(9):c='A';break;
case(8):c='B';break;
case(7):c='C';break;
case(6):c='D';break;
default:c='E';break;
}
printf("%c",c);
}
