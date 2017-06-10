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
void ShellInsert(SqList *L,int dk)
{
//	对顺序表L作一趟希尔插入排序，本算法是和一趟直接插入排序相比，作了修改
//  前后记录位置的增量是dk，而不是 1
//  r[0]只是暂存单元，不是哨兵。当j<=0时，插入位置已找到
	int i,j;
	for(i=dk+1;i<=L->length;i++)
		if(L->r[i]<L->r[i-dk])
		{
			L->r[0]=L->r[i];
			for(j=i-dk; j>0&&L->r[0]<L->r[j];j-=dk)
				L->r[j+dk]=L->r[j];//记录后移，查找插入位置 
			L->r[j+dk]=L->r[0];	//插入 
		} 
}
void ShellSort(SqList *L,int *dlta,int t)
{
	int k; 
	for(k=0;k<t;k++)
	{
		ShellInsert(L,dlta[k]);//增量为dlta[k]的插入排序，当dlta[k]为1时，退化为插入排序 
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
	
	printf("原来是\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n希尔排序后\n");

	ShellSort(&sl,dlta,10);
	timeNow=clock();
	TraverseList(sl);
	printf("希尔排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
