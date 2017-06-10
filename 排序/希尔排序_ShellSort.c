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
void ShellInsert(SqList *L,int dk)
{
//	��˳���L��һ��ϣ���������򣬱��㷨�Ǻ�һ��ֱ�Ӳ���������ȣ������޸�
//  ǰ���¼λ�õ�������dk�������� 1
//  r[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ�����ҵ�
	int i,j;
	for(i=dk+1;i<=L->length;i++)
		if(L->r[i]<L->r[i-dk])
		{
			L->r[0]=L->r[i];
			for(j=i-dk; j>0&&L->r[0]<L->r[j];j-=dk)
				L->r[j+dk]=L->r[j];//��¼���ƣ����Ҳ���λ�� 
			L->r[j+dk]=L->r[0];	//���� 
		} 
}
void ShellSort(SqList *L,int *dlta,int t)
{
	int k; 
	for(k=0;k<t;k++)
	{
		ShellInsert(L,dlta[k]);//����Ϊdlta[k]�Ĳ������򣬵�dlta[k]Ϊ1ʱ���˻�Ϊ�������� 
	}
		
}
void TraverseList(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
int main()
{
	SqList sl;
	clock_t timePast;
	clock_t timeNow;
	int i,dlta[10]={29,23,19,17,13,11,7,5,3,1};
	sl.length=1000;
	
	
	for(i=1;i<=1000;i++)
		sl.r[i]=rand()%1000;
	
	printf("ԭ����\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\nϣ�������\n");

	ShellSort(&sl,dlta,10);
	timeNow=clock();
	TraverseList(sl);
	printf("ϣ��������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
