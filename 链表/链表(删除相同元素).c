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

//此链表采用头节点为空的结构 
typedef struct LNode{
	
	ElemType data;
	struct LNode *next;
}Node,*Link;
Status MakeNode(Link *L,ElemType e)
{
	//分配由p指向的值为e的结点，并返回OK，若分配失败则返回ERROR
//	就是向L中填充数据域
	*L=(Link)malloc(sizeof(Node));
	if(!*L)	exit(OVERFLOW);//存储分配失败
	(*L)->data=e; 
	return OK;
}
void FreeNode(Link *p)
{
	//释放p所指向是结点
	free(*p); 
}
Status InitList(Link *L)
{
//	构造一个新的线性链表L
	*L=(Link)malloc(sizeof(Node));
	if(!(*L)->next)	exit(OVERFLOW);//存储分配失败
	(*L)->next=NULL; 
	return OK;
}
Status DestroyList(Link *L)
{
//	销毁线性链表L，L不在存在 
	free(*L);
	return OK;
}
Status ClearList(Link *L)
{
//	将线性链表L重置为空表，并释放原链表的结点空间 
	free((*L)->next);
	(*L)->next=NULL;
	return OK;
}

Status DelNode(Link L,Link h)
{
//	L为链表头	
//	已知h指向线性链表的结点，删除链表中结点
//  就是将h指向 的结点删了
	Link q=L->next;
	if(!h) return ERROR; //如果h都为空的话，就不用删了 
	while(q->next!=h) q=q->next;//让q指向h的前一个 
	q->next=h->next; 
	free(h); 
	return OK;	
}
int GetLength(Link L)
{
	//获取长度 
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
//	在带头结点的单链线性表L的第i个元素之前插入元素e
	Link h,s;
	int j;
	h=*L;
	if(!MakeNode(&s,e))
	{
		printf("结点内存分配失败 \n");
		return ERROR;//结点内存分配失败 
	}
	
	while(h->next)h=h->next;//将指针移到待插入的位置 
//	printf("%d\n",h->data);
	s->next=h->next;
	h->next=s; //将s插到h指向的后面
	return OK; 
}
void mutex(Link *L)
{
	//删除链表中相同的元素
	Link q,p;//p为当前待比较元素的位置，q为查找元素 
	q=(*L)->next;
	
	while(q) 
	{
		p=q->next;
		while(p)
		{
			if(q->data==p->data)
			{
				DelNode(*L,p);//删除重复结点 
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
//	遍历打印 
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
	printf("输入一串数，以零结尾%d\n",GetLength(L));
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
