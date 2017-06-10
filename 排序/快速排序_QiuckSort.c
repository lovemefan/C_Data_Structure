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
 
int Partition(SqList *L,int low,int high)
{ 

	L->r[0]=L->r[low]; // ���ӱ�ĵ�һ����¼�������¼  
	while(low<high) //  �ӱ�����˽�������м�ɨ��  
	{ 
		 while(low<high&&L->r[high]>=L->r[0])
			high--;
		 swap(L,low,high);// ���������¼С�ļ�¼�������Ͷ�  
		 while(low<high&&L->r[low]<=L->r[0])
			low++;
		 swap(L,low,high);// ���������¼��ļ�¼�������߶�  
	}
	return low; // ������������λ��  
}

// ��˳���L�е�������L->r[low..high]����������  
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); //  ��L->r[low..high]һ��Ϊ�����������ֵpivot  
			QSort(L,low,pivot-1);		//  �Ե��ӱ�ݹ�����  
			QSort(L,pivot+1,high);		//  �Ը��ӱ�ݹ�����  
	}
}
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
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
	printf("\n���������\n");
	QuickSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("����������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
