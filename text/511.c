#include<stdio.h>
int main()
{
	unsigned long sum1, sum2;

	int i,b=2;

	for(i=0;i<30;i++)
	{
		sum1+=b;
		b*=2;
	}

	sum1/=100;

	sum2=100000*30;

	printf("���̹��յ�%ld��\n���̹�����%ld��\n",sum2,sum1);

	return 0;
}
