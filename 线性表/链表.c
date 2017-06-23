#include <stdio.h>
#include <stdlib.h>
//没写完下次继续 
// 函数结果状态代码 
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

typedef Link Position;//用来定义结点的位置的指针 

typedef struct {
	
	Link head,tail;
	int  length;
}*LinkList;

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
Status InitList(LinkList *L)
{
//	构造一个新的线性链表L
	(*L)->head=(*L)->tail=(Link)malloc(sizeof(Node));
	if(!(*L)->head)	exit(OVERFLOW);//存储分配失败
	(*L)->head->next=NULL;
	(*L)->length=0; 
	return OK;
}
Status DestroyList(LinkList *L)
{
//	销毁线性链表L，L不在存在 
	free((*L)->head);
	free(*L);
	return OK;
}
Status ClearList(LinkList *L)
{
//	将线性链表L重置为空表，并释放原链表的结点空间 
	(*L)->tail=(*L)->head;
	free((*L)->head->next);
	(*L)->head->next=NULL;
	(*L)->length=0;
	return OK;
}
Status InsFirst(Link h,Link s)
{
//	已知h指向线性链表的头结点，将s所指向的结点插入在第一个结点之前
//  简单来说就是将S插到h指向的结点的后面 先不管h指向的结点后面是否为空 ，都一样 

	if(h) return ERROR; //如果h都为空的话，那还插个毛线啊    
	
// 这里会出现一个问题，如果下面ListInsert()想调用的话，且h是链表中最后一个元素
//那么就会产生新的尾部，而tail并没有指向新的尾部 ，所以这个问题得让ListInsert()自己处理。 
	s->next=h->next;	
	h->next=s;
	return OK;	
	
}
Status DelFirst(Link h,Link *q)
{
//	已知h指向线性链表的头结点，删除链表中的第一个结点以并q返回 
//  同上 ，就是将h指向的结点后一个删了 因为q要返回，就不free(q)了 
	if(h) return ERROR; //如果h都为空的话，就不用删了 
	(*q)=h->next; 
	h->next=h->next->next;	
	return OK;	
}
Status Append(LinkList *L,Link s)
{
//	将指针s所指的一串结点链接在L的最后一个结点上，之后并改变链表L的尾指针指向。
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
//	在带头结点的单链线性表L的第i个元素之前插入元素e
	Link h,s;
	if(!LocatePos(L,i-1,&h)) return ERROR; //i取值不合法
	if(!MakeNode(&s,e)) return ERROR;//结点内存分配失败 
	InsFirst(h,s); //将s插到h指向的后面
	return OK; 
}
Status Remove(LinkList *L,Link *q)
{ 
	if((*L)->head->next) return ERROR;//无结点，返回ERROR 
//删除线性链表L中的尾结点并以Q返回，改变链表L的尾指针指向行的尾结点
	Link newLink;
	newLink=(*L)->head;
	while(newLink->next->next)
		newLink=newLink->next;
//	 将newLink移向倒数第二个的位置
	(*L)->tail=newLink;
	*q=newLink->next; 
	free(newLink->next);
 	return OK; 
}
Status InsBefore(LinkList *L,Link *p,Link s)
{
//	已知p指向线性链表L中的一个结点，用s插在p所指向的结点之后 并修改p指向新的结点 
	Link temp;
	temp=(*L)->head->next;
	while(temp) 
	{
		if(temp->data!=(*p)->data)
		{
			if(!temp->next)//如果p是最后一个则要改变tail
			{
				 (*L)->tail=s;
				 temp->next=s;
				 *p=s; 
			}
			else//如果p是在中间，不用改变tail 
			{
				s->next=temp->next;
				temp->next=s;
				*p=s; 
			}	
			return OK;
		}
		
			
		temp=temp->next;
	}
	if(temp) return ERROR;//未找到p 返回ERROR 
}
Status InsAfter(LinkList *L,Link *p,Link s)
{
	//	已知p指向线性链表L中的一个结点，用s插在p所指向的结点之前 并修改p指向新的结点 
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
	if(temp) return ERROR;//未找到p 返回ERROR 
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
