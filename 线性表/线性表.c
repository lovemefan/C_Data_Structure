#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
// �������״̬���� 
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
//	����һ���յ����Ա� 
	(*L)->elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(!(*L)->elem)	exit(OVERFLOW);//�洢����ʧ��
	(*L)->length = 0;              //�ձ���Ϊ0 
	(*L)->listsize = LIST_INIT_SIZE;//��ʼ������������ElemTypeΪ��λ
	return OK; 
}
void DestroyList(ListPointer *L)
{
//	ɾ�������Ա� 
	free((*L)->elem);
	free(*L);
}
void ClearList(ListPointer *L)
{
//	������Ա��Ԫ������ 
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
{	//1<=i<=ListLength(L) ��e����L�е�i��Ԫ�ص�ֵ 
	if(i<1||i>(*L)->length+1) return ERROR;
		int *p;
		p=(*L)->elem;
		*e=*(p+i-1);
	return OK;
}
int LocateElem(ListPointer L,ElemType e,Status (*compare)(ElemType,ElemType) )
{	//�����Ա��в���e��λ�ã����ҵ��򷵻�����L��λ�򣬷��򷵻�0
	ElemType *p;
	int i;
	i=1;//i�ĳ�ʼֵΪ��һ��Ԫ�ص�λ�� 
	p=L->elem; //p�ĳ�ʼֵΪ��һ��Ԫ�صĴ���λ��
	while(i<=L->length && !(*compare)(*p++,e)) ++i;//��������
	if(i<=L->length)
		return i;
	else
		return 0; 
	
}
Status PriorElem(ListPointer L,ElemType e,ElemType *pre_e)
{
//	�����Ա�����Ҳ��ǵ�һ��������pre_e��������ǰ�� ���������ʧ�ܣ�pre_e�޶��� 
	if(L->length!=0&&L->length!=1&&LocateElem(L,e,compare)!=0)
		*pre_e=*(L->elem+LocateElem(L,e,compare)-2);
	else 
		return  INFEASIBLE;
}
Status NextElem(ListPointer L,ElemType e,ElemType *next_e)
{
	//	�����Ա�����Ҳ������һ����������next_e��������ǰ�� ���������ʧ�ܣ�pre_e�޶��� 
	if(L->length!=0&&L->length!=100&&LocateElem(L,e,compare)!=0)
		*next_e=*(L->elem+LocateElem(L,e,compare));
	else 
		return  INFEASIBLE;
}
Status ListInsert(ListPointer *L,int i,ElemType e)
{
	ElemType *p,*q;
//�����Ա���L��i��λ��֮ǰ����Ԫ��e�����ȼ�һ 
	if(i<1||i>(*L)->length+1) return ERROR;
	if((*L)->length>=(*L)->listsize)
	{
//		��ǰ�ռ���������ӷ���
		ElemType* newbase = (ElemType*)realloc((*L)->elem,((*L)->listsize+LISTINCREMENT)*sizeof(ElemType));//����10��Ԫ�صĿռ�
		if(!newbase) exit(OVERFLOW);//�ڴ����ʧ��
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
//	ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ�� L���ȼ�һ 
	ElemType *q; 
	if(i<1||i>(*L)->length+1) return ERROR;
	q=(*L)->elem+i-1;
	*e=*q;
	//����ǰ�� 
	for(;q<(*L)->elem+(*L)->length-1;q++)//ע�����ﲻ��<=��i<=q<=length-2 
	{
		*q=*(q+1);
	}
	(*L)->length--;
	return OK;
}
void ListTraverse(ListPointer L)
{
//	������ӡ 
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
	if(!InitList(&L)) printf("��ʼ��ʧ��\n");
	for(i=1;i<=10;i++)
		if(!ListInsert(&L,1,i*5)) printf("����ʧ��\n");
	ListTraverse(L);

}

