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
 
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* 需将L->r[i]插入有序子表 */
		{
			L->r[0]=L->r[i]; /* 设置哨兵 */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* 记录后移 */
			L->r[j+1]=L->r[0]; /* 插入到正确位置 */
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
	
	printf("原来是\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n插入排序后\n");
	InsertSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("插入排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
