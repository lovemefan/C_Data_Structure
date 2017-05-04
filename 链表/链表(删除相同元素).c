#include <stdio.h>
#include <stdlib.h>
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
Status InitList(Link *L)
{
//	����һ���µ���������L
	*L=(Link)malloc(sizeof(Node));
	if(!(*L)->next)	exit(OVERFLOW);//�洢����ʧ��
	(*L)->next=NULL; 
	return OK;
}
Status DestroyList(Link *L)
{
//	������������L��L���ڴ��� 
	free(*L);
	return OK;
}
Status ClearList(Link *L)
{
//	����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ� 
	free((*L)->next);
	(*L)->next=NULL;
	return OK;
}

Status DelNode(Link L,Link h)
{
//	LΪ����ͷ	
//	��֪hָ����������Ľ�㣬ɾ�������н��
//  ���ǽ�hָ�� �Ľ��ɾ��
	Link q=L->next;
	if(!h) return ERROR; //���h��Ϊ�յĻ����Ͳ���ɾ�� 
	while(q->next!=h) q=q->next;//��qָ��h��ǰһ�� 
	q->next=h->next; 
	free(h); 
	return OK;	
}
int GetLength(Link L)
{
	//��ȡ���� 
	int i=0;
	while(L->next)
	{
		i++;
		L=L->next;
	}
	return i;
}
Status ListInsert(Link *L,ElemType e)
{
//	�ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	Link h,s;
	int j;
	h=*L;
	if(!MakeNode(&s,e))
	{
		printf("����ڴ����ʧ�� \n");
		return ERROR;//����ڴ����ʧ�� 
	}
	
	while(h->next)h=h->next;//��ָ���Ƶ��������λ�� 
//	printf("%d\n",h->data);
	s->next=h->next;
	h->next=s; //��s�嵽hָ��ĺ���
	return OK; 
}
void mutex(Link *L)
{
	//ɾ����������ͬ��Ԫ��
	Link q,p;//pΪ��ǰ���Ƚ�Ԫ�ص�λ�ã�qΪ����Ԫ�� 
	q=(*L)->next;
	
	while(q) 
	{
		p=q->next;
		while(p)
		{
			if(q->data==p->data)
			{
				DelNode(*L,p);//ɾ���ظ���� 
				p=q->next;
			}
			else
				p=p->next;	
			
		} 
		q=q->next;
	}
} 
void ListTraverse(Link L)
{
//	������ӡ 
	Link p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	int n;
	Link L;
	InitList(&L);
	printf("����һ�����������β%d\n",GetLength(L));
	scanf("%d",&n);
	while(n)
	{
		
		ListInsert(&L,n);
		scanf("%d",&n);
	}
	mutex(&L);
	ListTraverse(L);
	return 0;
} 
