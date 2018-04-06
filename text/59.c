#include <stdio.h>
main()
{
 int n,i,j;
 scanf("%d",&n);
 for(j=0;j<n+1;j++)
 {
 for(i=n;i>j;i--)
 printf(" ");
 for(i=0;i<2*j+1;i++)
 printf("*");
 printf("\n");
 }

 for(j=0;j<n;j++)
 {
  for(i=0;i<=j;i++)
  printf(" ");
       for(i=2*n;i>1+2*j;i--)
       printf("*");
       printf("\n");
 }
}
