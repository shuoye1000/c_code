#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
    int num;//顾客序号
    long time;//进入队列时间 (顾客取号时间)
}DATA;
#include"CycQueue.h"//顺序循环队列
int num;//顾客序号

void add(CycQueue *q)//新增顾客
{
    DATA data;
    if(!CycQueueIsFull(q)){//队列未满时
        data.num=++num;
        data.time=time(NULL);
        CycQueueIn(q,data);
    }
    else printf("\n排队的人太多，请稍后排队！\n");
}

void next(CycQueue *q)//通知下一位办理业务
{
    DATA *data;
    if(!CycQueueIsEmpty(q)){
        data=CycQueueOut(q);//出队
        printf("\n请%d号顾客办理业务!\n",data->num);
    }
    if(!CycQueueIsEmpty(q)){
        data=CycQueuePeek(q);
        printf("请%d号顾客准备\n",data->num);
    }
}

int main()
{
    CycQueue *q;
    int i,n;
    num=0;
    q=CycQueueInit();
    if(q==NULL){
        printf("创建队列出错！\n");
        getch();
        return 0;
    }
    printf("\nSelect the operation:\n");
    printf("1.New customer arrived\n");//新到顾客
    printf("2.the next customer\n");//下一个
    printf("0.exit\n");
    char select;
    fflush(stdin);
    do{

        select=getch();
        switch(select){
            case '1':
                add(q);
                printf("There are %d customer waiting.\n",CycQueueLen(q));
                break;
            case '2':
                next(q);
                printf("There are %d customer waiting.\n",CycQueueLen(q));
                break;
            case '0':
                break;
        }
    }while(select!='0');
    CycQueueFree(q);
    getch();
    return 0;
}

