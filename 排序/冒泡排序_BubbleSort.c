#include <stdio.h>
#include <time.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int Status;
typedef int KeyType;
typedef struct 
{
	KeyType r[MAXSIZE+1];//���Ԫ����Ϊ�ڱ���Ԫ
	int length; 
}SqList;
void swap(SqList *L,int i,int j) 
{ 
//	����L�����е�i��jԪ�� 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}

void TraverseList(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
// ��˳���L����ѡ������ */
/* ��˳���L����������ð����������棩 */
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);/* ����L->r[i]��L->r[j]��ֵ */
			}
		}
	}
}

/* ��˳���L��ð������ */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)  /* ע��j�ǴӺ���ǰѭ�� */
		{
			if(L->r[j]>L->r[j+1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				 swap(L,j,j+1);/* ����L->r[j]��L->r[j+1]��ֵ */
			}
		}
	}
}

/* ��˳���L���Ľ�ð���㷨 */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag������Ϊ��� */
	for(i=1;i<L->length && flag;i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
	{
		flag=FALSE;				/* ��ʼΪFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* ����L->r[j]��L->r[j+1]��ֵ */
				 flag=TRUE;		/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}
int main()
{
	SqList sl;
	clock_t timePast;
	clock_t timeNow;
	int i;
	sl.length=1000;
	
	
	for(i=1;i<=1000;i++)
		sl.r[i]=rand()%1000+1;
	
	printf("ԭ����\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\nð�������\n");
	BubbleSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("ð��������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
