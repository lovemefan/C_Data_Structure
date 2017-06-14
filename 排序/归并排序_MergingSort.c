#include <stdio.h>
#include <time.h> 
#define OK 1
#define NUM 100 
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000 //需要排序的个数 
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
// ****************归并排序**********************************  

// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]  
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	// 将SR中记录由小到大地并入TR  
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		// 将剩余的SR[i..m]复制到TR  
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		// 将剩余的SR[j..n]复制到TR  
	}
}


// 递归法  
// 将SR[s..t]归并排序为TR1[s..t]  
void MSort(int SR[],int TR1[],int s, int t)
{
//	SR为输入进来将要排序的数组，TR1为排好序接收的数组 
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				// 将SR[s..t]平分为SR[s..m]和SR[m+1..t]  
		MSort(SR,TR2,s,m);		// 递归地将SR[s..m]归并为有序的TR2[s..m]  
		MSort(SR,TR2,m+1,t);	// 递归地将SR[m+1..t]归并为有序的TR2[m+1..t]  
		Merge(TR2,TR1,s,m,t);	// 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]  
	}
}

// 对顺序表L作归并排序  
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
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
	printf("\n归并排序后\n");
	MergeSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("归并排序用时%f秒",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
