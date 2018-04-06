//由键盘输入正数n，要求输出中间数字为n的菱形图案。要求菱形左边紧靠屏幕左边。
#include<stdio.h>
int main()
{
    int n,i,i1,i2,j,s=0,k=0;
    scanf("%d",&n);//定义要输入的行数
    for(i=1;i<=n;i++)//控制循环次数
    {
    for(j=n-1;j>0;j--)
            {printf(" ");k+=1;}//循环控制输出空格
    for(i1=k;i1<=n;i1++){s+=1;
                         printf("%d",s);//控制输出
                          for(i2=0;i2<=n;i1++){s=s-1;
                          s-=1;
                         printf("%d",s);s=0;}}//控制输出1到n

     printf("\n");//控制换行
    }

}
