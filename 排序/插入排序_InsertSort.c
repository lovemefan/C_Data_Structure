#include <stdio.h>
#include <time.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000
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
 
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* �轫L->r[i]���������ӱ� */
		{
			L->r[0]=L->r[i]; /* �����ڱ� */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* ��¼���� */
			L->r[j+1]=L->r[0]; /* ���뵽��ȷλ�� */
		}
	}
}

int main()
{
	SqList sl;
	clock_t timePast;
	clock_t timeNow;
	int i;
	sl.length=10000;
	
	
	for(i=1;i<=10000;i++)
		sl.r[i]=rand()%1000;
	
	printf("ԭ����\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n���������\n");
	InsertSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("����������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
