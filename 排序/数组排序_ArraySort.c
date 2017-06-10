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
void ArraySort(SqList *L,int range)
{
// ����������ʵ������ǰ����������֪����Ԫ�صķ�Χ
	int i,j,k=1,array[range+1];
	for(i=1;i<=range;i++)
		array[i]=0;//�ֽ��������ʼ��Ϊ��
	for(i=1;i<=L->length;i++)
		array[L->r[i]]++;//����������±���뵽array�У��������
	
	for(i=1;i<=range;i++)
	{
		if(array[i])//array[i]��ʾi��array[i]�� 
		{
			 for(j=0;j<array[i];j++)
			 	L->r[k++]=i;
		} 
	} 
	
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
	printf("\n�������\n");

	ArraySort(&sl,1000);
	timeNow=clock();
	TraverseList(sl);
	printf("��������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
