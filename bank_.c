#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
    int num;//�˿����
    long time;//�������ʱ�� (�˿�ȡ��ʱ��)
}DATA;
#include"CycQueue.h"//˳��ѭ������
int num;//�˿����

void add(CycQueue *q)//�����˿�
{
    DATA data;
    if(!CycQueueIsFull(q)){//����δ��ʱ
        data.num=++num;
        data.time=time(NULL);
        CycQueueIn(q,data);
    }
    else printf("\n�Ŷӵ���̫�࣬���Ժ��Ŷӣ�\n");
}

void next(CycQueue *q)//֪ͨ��һλ����ҵ��
{
    DATA *data;
    if(!CycQueueIsEmpty(q)){
        data=CycQueueOut(q);//����
        printf("\n��%d�Ź˿Ͱ���ҵ��!\n",data->num);
    }
    if(!CycQueueIsEmpty(q)){
        data=CycQueuePeek(q);
        printf("��%d�Ź˿�׼��\n",data->num);
    }
}

int main()
{
    CycQueue *q;
    int i,n;
    num=0;
    q=CycQueueInit();
    if(q==NULL){
        printf("�������г���\n");
        getch();
        return 0;
    }
    printf("\nSelect the operation:\n");
    printf("1.New customer arrived\n");//�µ��˿�
    printf("2.the next customer\n");//��һ��
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

