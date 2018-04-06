#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK    1
typedef int status;
typedef int ElemType;
typedef struct Node
{
 ElemType data;
 struct Node *next;
} LNode,*LinkList;
void Build(LinkList L)//����һ����ͷ���ĵ�����
{
 int n;
 LinkList p,q;
 p=L;
 printf("������n��n������Ԫ��:\n");
 scanf("%d",&n);
 while(n--)
 {
  q=(LinkList)malloc(sizeof(LNode));
  scanf("%d",&q->data);
  q->next=NULL;
  p->next=q;
  p=q;
 }
}
void Print(LinkList L)//���㵥����ĳ��ȣ�Ȼ�����������
{
 int num=0;
 LinkList p;
 p=L->next;
 while(p)
 {
  num++;
  printf("%d ",p->data);
  p=p->next;
 }
 printf("\n����Ϊ%d:\n",num);
}
void Tips()
{
 printf("�����ּ�ѡ����Ӧ����\n");
 printf("<1> ����������䳤��:\n");
 printf("<2> ����ֵΪx��ֱ��ǰ�����:\n");
 printf("<3> ɾ��ֵΪx�Ľ��:\n");
 printf("<4> ������Ԫ������:\n");
 printf("<5> ɾ����������ֵ����mink��С��maxk��Ԫ��:\n");
 printf("<6> ɾ����������ֵ��ͬ�Ķ���Ԫ��:\n");
 printf("<7> �ֽ����������:\n");
 printf("<8> �������������ֵΪX�Ľ�㣬ʹ��Ȼ����:\n");
 printf("<9> ����������:\n");
 printf("<0> �˳�:\n");
}
void Find(LinkList L,int x)//����ֵΪx��ֱ��ǰ�����q
{
 LinkList p;
 p=L;
 while( p->next &&p->next->data!=x)
  p=p->next;
 if(p->next)
  printf("%d��ǰ�����Ϊ:%d\n\n",x,p->data);
 else
  printf("û�ҵ�!!\n\n");
}
void Delete(LinkList L,int x)//ɾ��ֵΪx�Ľ��
{
 LinkList p,q;
 p=L;
 while( p->next &&p->next->data!=x)
  p=p->next;
 if(p->next)
 {
  q=p->next;
  p->next=q->next;
  free(q);
  printf("ɾ���ɹ�!!\n\n");
 }
 else
  printf("������û��%d\n\n",x);
}
void NiZhi(LinkList L)//�ѵ���������Ԫ������,������ͷ�巨��������!
{
 LinkList p,s;
 p=s=L->next;
 L->next=NULL;
 while(p)
 {
  s=s->next;
  p->next=L->next;
  L->next=p;
  p=s;
 }
 printf("���óɹ�!!!\n\n");
}


void Delete1(LinkList L)//ɾ����������ֵ����mink��С��maxk��Ԫ��
{
 int maxk,mink;
 LinkList p,q,s;
 printf("������mink,maxk:\n");
 scanf("%d %d",&mink,&maxk);
 p=L;
 while(p->next && p->next->data<=mink)
  p=p->next;
 s=p->next;
 while(s && s->data<maxk)
 {
  q=s;
  s=s->next;
  free(q);
 }
 p->next=s;
 printf("ɾ���ɹ�\n\n");
}
void Delete2(LinkList L)//ɾ����������ֵ��ͬ�Ķ���Ԫ�أ�ʹ�ò���������Ա�������Ԫ�ص�ֵ������ͬ����
{
 LinkList p,q,s;
 p=L;
 q=L->next;
 while(q->next)
 {
  if(q->data==q->next->data)
  {
   p->next=q->next;
   s=q;
   q=q->next;
   free(s);
  }
  else
  {
   p=p->next;
   q=q->next;
  }
 }
 printf("ɾ���ɹ�!!!!\n");
}
void fenjie(LinkList L)//���ã�1������������ʵ�ֽ���ֽ��������������һ��ȫ��Ϊ��������һ��ȫ��Ϊż��
{
 LinkList s,p,Lb,cur1,cur2;
 Lb=(LinkList )malloc(sizeof(LNode));
 Lb->next=NULL;
 s=L->next;
 L->next=NULL;
 cur1=L;
 cur2=Lb;
 while(s)
 {
  p=s;
  s=s->next;
  p->next=NULL;
  if(p->data&1)
  {
   cur1->next=p;
   cur1=cur1->next;
  }
  else
  {
   cur2->next=p;
   cur2=cur2->next;
  }
 }
 cur1=L->next;
 cur2=Lb->next;
 printf("Ԫ��Ϊ����������:\n");
 while(cur1)
 {
  printf("%d ",cur1->data);
  cur1=cur1->next;
 }
 printf("\nԪ��Ϊż��������:\n");
 while(cur2)
 {
  printf("%d ",cur2->data);
  cur2=cur2->next;
 }
 printf("\n\n");
}
void Insert(LinkList L,LinkList p)//�������������ֵΪX�Ľ�㣬ʹ��Ȼ����
{
 LinkList s;
 s=L;
 while(s->next && s->next->data < p->data)
  s=s->next;
 p->next=s->next;
 s->next=p;
}
status Sort(LinkList L)//����������
{
 LinkList s,r;
 s=L->next;
 L->next=NULL;
 while(s)
 {
  r=s;
  s=s->next;
  r->next=NULL;
  Insert(L,r);
 }
 return OK;
}
int main()
{
 int op,x,flag;
 LinkList L,p;
 L=(LinkList)malloc(sizeof(LNode));
 L->next=NULL;
 L->data=-1;
 Build(L);
 Tips();
 scanf("%d",&op);
 while(op)
 {
  switch(op)
  {
  case 1:
   Print(L);
   break;
  case 2:
   printf("������Ҫ���ҵ�Ԫ��X:\n");
   scanf("%d",&x);
   Find(L,x);
   break;
  case 3:
   printf("������Ҫ���ҵ�ɾ��X:\n");
   scanf("%d",&x);
   Delete(L,x);
   break;
  case 4:
   NiZhi(L);
   break;
  case 5:
   Delete1(L);
   break;
  case 6:
   Delete2(L);
   break;
  case 7:
   fenjie(L);
   break;
  case 8:
   printf("������Ҫ�����Ԫ��X:\n");
   scanf("%d",&x);
   p=(LinkList)malloc(sizeof(LNode));
   p->data=x;
   Insert(L,p);
   printf("����ɹ�!!!\n\n");
   break;
  case 9:
   flag=Sort(L);
   if(flag)
    printf("����ɹ�!!\n");
   break;
  }
  Tips();
  scanf("%d",&op);
 }
 return 0;
}
