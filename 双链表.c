#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct doublenode {
    int data;
    struct doublenode *next ,*prior ;
};                      //定义一个双向链表
typedef struct doublenode dnode; //格式化定义

//“头插法”建立链表
dnode *CreatTab(int n)
{
    int i;
    dnode *pnew,*phead,*ptail;
    phead=(dnode *)malloc(sizeof(dnode));  //为链表设计一个头结点
    phead->data=n;
    phead->next =NULL;
    phead->prior =NULL;
    ptail=phead;
    for(i=0;i<n;i++){
        printf("输入第 %d 个数 :",i+1);
        pnew=(dnode *)malloc(sizeof(dnode));  //生成头结点，尾插法
        scanf("%d",& pnew->data);
        ptail->next =pnew ;
        pnew->prior =ptail;
        ptail=pnew;
        ptail->next =NULL;
    }
    return phead;
}
//遍历打印链表
void FindTab(dnode *s)
{
    s=s->next ;//消去头结点造成的影响
    while (s!=NULL)
    {

        printf("      %d\n",s->data);
            s=s->next ;
    }
}
//计算长度
void length(dnode* k) //计算链表长度
{
    k=k->next ;
    int count=0;
    while(k!=NULL)
    {
        k=k->next ;
        count++;
    }
    printf("链表长度是 %d !\n",count);
}
//删除值为n的节点
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
            else//针对最后一个元素为删除结点
            {
                p1->prior ->next =NULL;
                flag++;
                p1=p1->next ;
            }

        }
        else p1=p1->next;
    }
    if(flag!=0)
        printf("删除了总共%d个节点\n",flag);
    else
        printf("没有找到你要删除的元素\n");
    return p;
}


//插入选项
dnode * charu(dnode *p)
{
    int kk;
    dnode *s,*ss,*mm;
    mm=(dnode *)malloc (sizeof(dnode));//申请一个空间用于存储新添加的结点
    s=p;
    ss=s->next;
    printf("输入你要插入的元素:          ");
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
    printf("已经成功插入数组中\n");
    return p;
}
//对称的判断
void duichen(dnode *p)
{
    dnode *p1,*p2,*p3;
    int flag=0;
    p1=p->next;
    p2=p; //使p2指向最后一个元素
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
        printf("不是对称链表！\n");
    else
        printf("是对称链表！\n");
}
//奇数和偶数排序
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
//菜单选项
void menu()
{
    printf("\n1.尾插法建立一个双向链表 \n");
    printf("2.遍历双向链表 \n");
    printf("3.删除一个指定元素\n");
    printf("4.插入元素使之依然有序\n");
    printf("5.判断是不是对称 \n");
    printf("6.把奇数排在偶数前面 \n");
}
void main()
{
    int m,n,t,choice;
    dnode *p;
    while(1){
        system("cls");
        menu();
        printf("\n输入你的选项:      ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("输入要输入的数的个数：");
            scanf("%d",&m);
            printf("\n");
            p=CreatTab(m);
            printf("                建立成功!\n");
            system("pause>null");
            break;
        case 2:
            FindTab(p); //bian li the list
            length(p);
            system("pause>null");
            break;
        case 3:
            printf("输入你要删除的数:      ");
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
            printf("                        排序成功\n");
            system("pause>null");
            break;

        default :
            printf("输入错误，程序自动退出!\n");
            system("pause>null");
            exit(1);
        }

    }
}
