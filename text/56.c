#include<stdio.h>
 int main()
{
double a=1,b=2,t;
int i,n;
double sum=0.0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{sum+=b/a;
t=b;
b=a+b;
a=t;
}
printf("%.4f\n", sum);
}
