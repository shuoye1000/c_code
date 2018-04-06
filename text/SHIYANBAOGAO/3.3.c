#include <stdio.h>
#include <math.h>
int main()
{
float x,x0,f,f1;
x = 2.0;
do{
x0=x;
f=2*x0*x0*x0-4*x0*x0+3*x0-6;
f1=6*x0*x0-8*x0+3;
x=x0-f/f1;
}while(fabs(x-x0)>=1e-5);
printf ("%f\n",x);
}
