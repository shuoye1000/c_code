#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct doublenode {
    int data;
    struct doublenode *next ,*prior ;
};                      //����һ��˫������
typedef struct doublenode dnode; //��ʽ������

//��ͷ�巨����������
dnode *CreatTab(int n)
{
    int i;
    dnode *pnew,*phead,*ptail;
    phead=(dnode *)malloc(sizeof(dnode));  //Ϊ�������һ��ͷ���
    phead->data=n;
    phead->next =NULL;
    phead->prior =NULL;
    ptail=phead;
    for(i=0;i<n;i++){
        printf("����� %d ���� :",i+1);
        pnew=(dnode *)malloc(sizeof(dnode));  //����ͷ��㣬β�巨
        scanf("%d",& pnew->data);
        ptail->next =pnew ;
        pnew->prior =ptail;
        ptail=pnew;
        ptail->next =NULL;
    }
    return phead;
}
//������ӡ����
void FindTab(dnode *s)
{
    s=s->next ;//��ȥͷ�����ɵ�Ӱ��
    while (s!=NULL)
    {

        printf("      %d\n",s->data);
            s=s->next ;
    }
}
//���㳤��
void length(dnode* k) //����������
{
    k=k->next ;
    int count=0;
    while(k!=NULL)
    {
        k=k->next ;
        count++;
    }
    printf("�������� %d !\n",count);
}
//ɾ��ֵΪn�Ľڵ�
dnode  *deleted(dnode *p ,int n)
{
    int flag=0;
    dnode *p1;
    p1=p->next ;
    while(p1)
    {

        if(p1->data == n){
            if(p1->next !=NULL){
                p1->next ->prior =p1->prior ;
                p1->prior ->next =p1->next ;
                p1=p1->next ;
                flag++;
            }
            else//������һ��Ԫ��Ϊɾ�����
            {
                p1->prior ->next =NULL;
                flag++;
                p1=p1->next ;
            }

        }
        else p1=p1->next;
    }
    if(flag!=0)
        printf("ɾ�����ܹ�%d���ڵ�\n",flag);
    else
        printf("û���ҵ���Ҫɾ����Ԫ��\n");
    return p;
}


//����ѡ��
dnode * charu(dnode *p)
{
    int kk;
    dnode *s,*ss,*mm;
    mm=(dnode *)malloc (sizeof(dnode));//����һ���ռ����ڴ洢����ӵĽ��
    s=p;
    ss=s->next;
    printf("������Ҫ�����Ԫ��:          ");
    scanf("%d",&kk);
    mm->data =kk;
    while(ss){
        if(ss->data >= kk)
        {
            mm->next=ss;
            s->next=mm;
            mm->prior=s;
            ss->prior=mm;
            break;
        }
        else
        {s=s->next ;ss=ss->next ;}
    }
    if(s->next==NULL){
        s->next=mm;
        mm->prior=s;
        mm->next=NULL;
    }
    printf("�Ѿ��ɹ�����������\n");
    return p;
}
//�ԳƵ��ж�
void duichen(dnode *p)
{
    dnode *p1,*p2,*p3;
    int flag=0;
    p1=p->next;
    p2=p; //ʹp2ָ�����һ��Ԫ��
    p3=p->next;
    while(p3)
    {
        p2=p2->next;
        p3=p3->next;
    }
    while(p1!=p2)
    {
        if(p1->data==p2->data)
        {p1=p1->next;p2=p2->prior;}
        else
        {flag=1;break;}
    }
    if(flag==1)
        printf("���ǶԳ�����\n");
    else
        printf("�ǶԳ�����\n");
}
//������ż������
dnode * paixu(dnode * p)
{
    dnode *p1,*p2;
    int temp;
    p1=p->next;
    p2=p;
    while(p2->next !=NULL)
        p2=p2->next ;
    while(1){
        while(p1->data%2!=0) p1=p1->next ;
        while(p2->data%2==0) p2=p2->prior ;
        if(p1->next==p2||p1->prior==p2)
            break;
        else{
        temp=p1->data ;
        p1->data=p2->data ;
        p2->data =temp;
        }
    }
    return p;
}
//�˵�ѡ��
void menu()
{
    printf("\n1.β�巨����һ��˫������ \n");
    printf("2.����˫������ \n");
    printf("3.ɾ��һ��ָ��Ԫ��\n");
    printf("4.����Ԫ��ʹ֮��Ȼ����\n");
    printf("5.�ж��ǲ��ǶԳ� \n");
    printf("6.����������ż��ǰ�� \n");
}
void main()
{
    int m,n,t,choice;
    dnode *p;
    while(1){
        system("cls");
        menu();
        printf("\n�������ѡ��:      ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("����Ҫ��������ĸ�����");
            scanf("%d",&m);
            printf("\n");
            p=CreatTab(m);
            printf("                �����ɹ�!\n");
            system("pause>null");
            break;
        case 2:
            FindTab(p); //bian li the list
            length(p);
            system("pause>null");
            break;
        case 3:
            printf("������Ҫɾ������:      ");
            scanf("%d",&n);
            p=deleted(p,n);
            system("pause>null");
            break;
        case 4:
            charu(p);
            system("pause>null");
            break;
        case 5:
            duichen(p);
            system("pause>null");
            break;
        case 6:
            paixu(p);
            printf("                        ����ɹ�\n");
            system("pause>null");
            break;

        default :
            printf("������󣬳����Զ��˳�!\n");
            system("pause>null");
            exit(1);
        }

    }
}
