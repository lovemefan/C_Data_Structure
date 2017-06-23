#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
// 函数结果状态代码 
#define TRUE  1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 
typedef int Status;
typedef int ElemType;
typedef struct l{
	
	ElemType *elem;
	int length;
	int listsize;	
	
}List,*ListPointer;
Status compare(ElemType a,ElemType b)
{
	if(a==b)
		return TRUE;
	else
		return FLASE; 
} 
Status InitList(ListPointer *L)
{
//	构造一个空的线性表 
	(*L)->elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(!(*L)->elem)	exit(OVERFLOW);//存储分配失败
	(*L)->length = 0;              //空表长度为0 
	(*L)->listsize = LIST_INIT_SIZE;//初始储存容量，以ElemType为单位
	return OK; 
}
void DestroyList(ListPointer *L)
{
//	删除此线性表 
	free((*L)->elem);
	free(*L);
}
void ClearList(ListPointer *L)
{
//	清空线性表的元素数据 
	(*L)->length=0;
}
Status ListEmpty(ListPointer L)
{
	if(L->length)
		return TRUE;
	else
		return FLASE; 
}
int ListLength(ListPointer L)
{
	return L->length;
}
Status getElem(ListPointer *L,int i ,ElemType *e)
{	//1<=i<=ListLength(L) 用e返回L中第i个元素的值 
	if(i<1||i>(*L)->length+1) return ERROR;
		int *p;
		p=(*L)->elem;
		*e=*(p+i-1);
	return OK;
}
int LocateElem(ListPointer L,ElemType e,Status (*compare)(ElemType,ElemType) )
{	//在线性表中查找e的位置，若找到则返回其在L的位序，否则返回0
	ElemType *p;
	int i;
	i=1;//i的初始值为第一个元素的位序 
	p=L->elem; //p的初始值为第一个元素的储存位置
	while(i<=L->length && !(*compare)(*p++,e)) ++i;//遍历查找
	if(i<=L->length)
		return i;
	else
		return 0; 
	
}
Status PriorElem(ListPointer L,ElemType e,ElemType *pre_e)
{
//	若线性表存在且不是第一个，则用pre_e返回它的前驱 ，否则操作失败，pre_e无定义 
	if(L->length!=0&&L->length!=1&&LocateElem(L,e,compare)!=0)
		*pre_e=*(L->elem+LocateElem(L,e,compare)-2);
	else 
		return  INFEASIBLE;
}
Status NextElem(ListPointer L,ElemType e,ElemType *next_e)
{
	//	若线性表存在且不是最后一个个，则用next_e返回它的前驱 ，否则操作失败，pre_e无定义 
	if(L->length!=0&&L->length!=100&&LocateElem(L,e,compare)!=0)
		*next_e=*(L->elem+LocateElem(L,e,compare));
	else 
		return  INFEASIBLE;
}
Status ListInsert(ListPointer *L,int i,ElemType e)
{
	ElemType *p,*q;
//在线性表中L第i个位置之前插入元素e，长度加一 
	if(i<1||i>(*L)->length+1) return ERROR;
	if((*L)->length>=(*L)->listsize)
	{
//		当前空间已满，添加分配
		ElemType* newbase = (ElemType*)realloc((*L)->elem,((*L)->listsize+LISTINCREMENT)*sizeof(ElemType));//增加10个元素的空间
		if(!newbase) exit(OVERFLOW);//内存分配失败
		(*L)->elem=newbase;
		(*L)->length+=LISTINCREMENT; 
	}
	q=(*L)->elem+i-1;
	p=(*L)->elem+(*L)->length-1;
	for(;p>=q;--p)
		*(p+1)=*p;
	*q=e;
	(*L)->length++; 
	return OK;
}
Status ListDelete(ListPointer *L,int i,ElemType *e)
{
//	删除L中的第i个元素，并用e返回其值， L长度减一 
	ElemType *q; 
	if(i<1||i>(*L)->length+1) return ERROR;
	q=(*L)->elem+i-1;
	*e=*q;
	//整体前移 
	for(;q<(*L)->elem+(*L)->length-1;q++)//注意这里不是<=，i<=q<=length-2 
	{
		*q=*(q+1);
	}
	(*L)->length--;
	return OK;
}
void ListTraverse(ListPointer L)
{
//	遍历打印 
	ElemType *p=L->elem;
	while(p&&p<L->elem+L->length)
	{
		printf("%d ",*p);
		p++;
	}
	printf("\n");
}
int main()
{
	List list;
	int i;
	ListPointer L=&list;
	if(!InitList(&L)) printf("初始化失败\n");
	for(i=1;i<=10;i++)
		if(!ListInsert(&L,1,i*5)) printf("插入失败\n");
	ListTraverse(L);

}

