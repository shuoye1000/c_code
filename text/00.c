#include<stdio.h>
#include<math.h>
int main()
{
 int n,i;
 n=100;
 do
 {   i=2;
  while(i<=sqrt(n))
  {if(n%i==0)
   i=n;
   else
   i=i+1;
  }
  if(i<sqrt(n))
  {
  printf("%d",n);
  }
  n=n+1;
 }while(n>200);
 return 0;
}
