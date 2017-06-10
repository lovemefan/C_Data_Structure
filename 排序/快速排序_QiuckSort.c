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
 
int Partition(SqList *L,int low,int high)
{ 

	L->r[0]=L->r[low]; // 用子表的第一个记录作枢轴记录  
	while(low<high) //  从表的两端交替地向中间扫描  
	{ 
		 while(low<high&&L->r[high]>=L->r[0])
			high--;
		 swap(L,low,high);// 将比枢轴记录小的记录交换到低端  
		 while(low<high&&L->r[low]<=L->r[0])
			low++;
		 swap(L,low,high);// 将比枢轴记录大的记录交换到高端  
	}
	return low; // 返回枢轴所在位置  
}

// 对顺序表L中的子序列L->r[low..high]作快速排序  
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=Partition(L,low,high); //  将L->r[low..high]一分为二，算出枢轴值pivot  
			QSort(L,low,pivot-1);		//  对低子表递归排序  
			QSort(L,pivot+1,high);		//  对高子表递归排序  
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
	
	printf("原来是\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n快速排序后\n");
	QuickSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("插入排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
