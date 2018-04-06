#include<stdio.h>
int main()
{
int a,b,k,x,y;
scanf("%d%d",&a,&b);
x=a;
y=b;
while(1){
    if(a%k==0&&b%k==0) break;
    k--;
  }
printf("%d\n",k);
k=x*y/k;
printf("%d",k);
}
