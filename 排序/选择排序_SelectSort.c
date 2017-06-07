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
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						// ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=L->length;j++)// ѭ��֮������� */
        {
			if (L->r[min]>L->r[j])	// �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				// ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if(i!=min)						// ��min������i��˵���ҵ���Сֵ������ */
			swap(L,i,min);				// ����L->r[i]��L->r[min]��ֵ */
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
		sl.r[i]=rand()%1000;
	
	printf("ԭ����\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\nѡ�������\n");
	SelectSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("��ͨ������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
