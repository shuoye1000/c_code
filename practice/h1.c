#include <stdio.h>
#include <math.h>
int main(){
int n,a[100][100]={0};
double result=1.0;
printf("�����������");
scanf("%d",&n);
int row,col;
for(row=0;row<n;row++)
for(col=0;col<n;col++)
scanf("%d",&a[row][col]);
int nextrow,stemp,temp,flag;
int switchtime=0;
for(row=0;row<n-1;row++)
{
nextrow=row+1;
if(a[row][row]==0)/* ��ʼ�����һ�У��������ʽ��һ�е�һ����Ϊ�㣬Ҫ������ */
{ while(a[nextrow][row]==0)
{
nextrow++; /* �������ʽ�ڶ��е�һ����Ϊ�㣬�����Ӽ���Ѱ�ҷ�����ֵ���� */
if(nextrow==n)/* �������������ʽ����ʽ��һ��Ԫ�ض�Ϊ�㣬�˳�whileѭ�� */
{ flag=1;
break;
}
}
if(flag==1) /* �˳�whileѭ����ص�for(row=0;row<n-1;row++)�м�1?*/
continue; /* ��array[row][row]==0֪��Ҳ��Ӧ��1����ʼ����ڶ��� */
switchtime++; /* ÿ����һ���У�����ʽ���ű仯1�Σ�ͳ�Ʊ仯���� */
for(col=0;col<n;col++) /* ���������е�����ʽ���� */
{
stemp=a[row][col];
a[row][col]=a[nextrow][col];
a[nextrow][col]=stemp;
}
}
for(nextrow=row+1;nextrow<n;nextrow++)
{ /* ���Ƹ�˹��ȥ��������һ���¸��е�һ����ֵ����*/
temp=a[nextrow][row]/a[row][row];
for(col=0;col<n;col++)
a[nextrow][col]+=-temp*a[row][col];/* ������ʽΪ����������ʽ��ʽ */
}
}for(row=0;row<n;row++)
result*=a[row][row];
printf("%d",result);
}
