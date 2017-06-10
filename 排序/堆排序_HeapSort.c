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
void HeapAdjust(SqList *L,int s ,int m)
{
	int j;
	L->r[0]=L->r[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m && L->r[j]<L->r[j+1])
			j++;
		if(L->r[0]>=L->r[j])
			break;
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=L->r[0];
}
void HeapSort(SqList *L)
{
	int i;
	for(i=L->length/2;i>0;i--)
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{
		swap(L,1,i);
		HeapAdjust(L,1,i-1);
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

	HeapSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("堆排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
