#include <stdio.h>
#include <stdlib.h>
//ûд���´μ��� 
// �������״̬���� 
#define TRUE  1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 
typedef int Status;
typedef int ElemType;

//���������ͷ�ڵ�Ϊ�յĽṹ 
typedef struct LNode{
	
	ElemType data;
	struct LNode *next;
}Node,*Link;

typedef Link Position;//�����������λ�õ�ָ�� 

typedef struct {
	
	Link head,tail;
	int  length;
}*LinkList;

Status MakeNode(Link *L,ElemType e)
{
	//������pָ���ֵΪe�Ľ�㣬������OK��������ʧ���򷵻�ERROR
//	������L�����������
	*L=(Link)malloc(sizeof(Node));
	if(!*L)	exit(OVERFLOW);//�洢����ʧ��
	(*L)->data=e; 
	return OK;
}
void FreeNode(Link *p)
{
	//�ͷ�p��ָ���ǽ��
	free(*p); 
}
Status InitList(LinkList *L)
{
//	����һ���µ���������L
	(*L)->head=(*L)->tail=(Link)malloc(sizeof(Node));
	if(!(*L)->head)	exit(OVERFLOW);//�洢����ʧ��
	(*L)->head->next=NULL;
	(*L)->length=0; 
	return OK;
}
Status DestroyList(LinkList *L)
{
//	������������L��L���ڴ��� 
	free((*L)->head);
	free(*L);
	return OK;
}
Status ClearList(LinkList *L)
{
//	����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ� 
	(*L)->tail=(*L)->head;
	free((*L)->head->next);
	(*L)->head->next=NULL;
	(*L)->length=0;
	return OK;
}
Status InsFirst(Link h,Link s)
{
//	��֪hָ�����������ͷ��㣬��s��ָ��Ľ������ڵ�һ�����֮ǰ
//  ����˵���ǽ�S�嵽hָ��Ľ��ĺ��� �Ȳ���hָ��Ľ������Ƿ�Ϊ�� ����һ�� 

	if(h) return ERROR; //���h��Ϊ�յĻ����ǻ����ë�߰�    
	
// ��������һ�����⣬�������ListInsert()����õĻ�����h�����������һ��Ԫ��
//��ô�ͻ�����µ�β������tail��û��ָ���µ�β�� ����������������ListInsert()�Լ����� 
	s->next=h->next;	
	h->next=s;
	return OK;	
	
}
Status DelFirst(Link h,Link *q)
{
//	��֪hָ�����������ͷ��㣬ɾ�������еĵ�һ������Բ�q���� 
//  ͬ�� �����ǽ�hָ��Ľ���һ��ɾ�� ��ΪqҪ���أ��Ͳ�free(q)�� 
	if(h) return ERROR; //���h��Ϊ�յĻ����Ͳ���ɾ�� 
	(*q)=h->next; 
	h->next=h->next->next;	
	return OK;	
}
Status Append(LinkList *L,Link s)
{
//	��ָ��s��ָ��һ�����������L�����һ������ϣ�֮�󲢸ı�����L��βָ��ָ��
	int counter=0; 
	(*L)->tail->next=s;
	while(s)
	{
		s=s->next;
		counter++;
	}
	
	(*L)->tail=s;
	(*L)->length+=counter;
	return 0; 
}
Status ListInsert(LinkList *L,int i,ElemType e)
{
//	�ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	Link h,s;
	if(!LocatePos(L,i-1,&h)) return ERROR; //iȡֵ���Ϸ�
	if(!MakeNode(&s,e)) return ERROR;//����ڴ����ʧ�� 
	InsFirst(h,s); //��s�嵽hָ��ĺ���
	return OK; 
}
Status Remove(LinkList *L,Link *q)
{ 
	if((*L)->head->next) return ERROR;//�޽�㣬����ERROR 
//ɾ����������L�е�β��㲢��Q���أ��ı�����L��βָ��ָ���е�β���
	Link newLink;
	newLink=(*L)->head;
	while(newLink->next->next)
		newLink=newLink->next;
//	 ��newLink�������ڶ�����λ��
	(*L)->tail=newLink;
	*q=newLink->next; 
	free(newLink->next);
 	return OK; 
}
Status InsBefore(LinkList *L,Link *p,Link s)
{
//	��֪pָ����������L�е�һ����㣬��s����p��ָ��Ľ��֮�� ���޸�pָ���µĽ�� 
	Link temp;
	temp=(*L)->head->next;
	while(temp) 
	{
		if(temp->data!=(*p)->data)
		{
			if(!temp->next)//���p�����һ����Ҫ�ı�tail
			{
				 (*L)->tail=s;
				 temp->next=s;
				 *p=s; 
			}
			else//���p�����м䣬���øı�tail 
			{
				s->next=temp->next;
				temp->next=s;
				*p=s; 
			}	
			return OK;
		}
		
			
		temp=temp->next;
	}
	if(temp) return ERROR;//δ�ҵ�p ����ERROR 
}
Status InsAfter(LinkList *L,Link *p,Link s)
{
	//	��֪pָ����������L�е�һ����㣬��s����p��ָ��Ľ��֮ǰ ���޸�pָ���µĽ�� 
	Link temp;
	temp=(*L)->head;
	while(temp->next) 
	{
		if(temp->next->data!=(*p)->data)
		{
				s->next=temp->next;
				temp->next=s;
				*p=s; 
			return OK;
		}
		
			
		temp=temp->next;
	}
	if(temp) return ERROR;//δ�ҵ�p ����ERROR 
}
Status SetCurElem(Link *p,ElemType e)
{
}
ElemType GetCurElem(Link p)
{
}
Status ListEmpty(LinkList L)
{
} 
int ListLength(LinkList L)
{
}
Position GetHead(LinkList L)
{
}
 
Position GetLast(LinkList L)
{
}
Position PriorPos(LinkList L,Link p)
{
}
Position NextPos(LinkList L,Link p)
{
}
Position LocateElem(LinkList L,Link p,Status (*compare)(ElemType,ElemType))
{
}
Status ListTraverse(LinkList L)
{
} 
Status compare(ElemType a,ElemType b)
{
	if(a==b)
		return TRUE;
	else
		return FLASE; 
} 
int main()
{
	return 0;
} 
