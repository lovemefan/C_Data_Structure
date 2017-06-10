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
	KeyType r[MAXSIZE+1];//零号元素作为哨兵单元
	int length; 
}SqList;
void swap(SqList *L,int i,int j) 
{ 
//	交换L数组中的i和j元素 
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
// 利用数组来实现排序，前提条件是已知数组元素的范围
	int i,j,k=1,array[range+1];
	for(i=1;i<=range;i++)
		array[i]=0;//现将此数组初始化为零
	for(i=1;i<=L->length;i++)
		array[L->r[i]]++;//利用数组的下标插入到array中，完成排序
	
	for(i=1;i<=range;i++)
	{
		if(array[i])//array[i]表示i有array[i]个 
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
	
	printf("原来是\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n堆排序后\n");

	ArraySort(&sl,1000);
	timeNow=clock();
	TraverseList(sl);
	printf("堆排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
