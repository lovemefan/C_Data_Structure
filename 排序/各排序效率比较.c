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


typedef struct
{
	SqList L;
	char *inf;//排序的种类（名称） 
	int opration[NUM];
	double averageopration;//一个记录操作次数的数组，和一个记录平均操作数的变量 
	double times[NUM],averagetime;//一个记录操作时间的数组，和一个记录平均时间的变量 
}SortStructure;//排序的一个结构体 

void InitSortStructureSqlist(SortStructure *S,SqList L)
{
	S->L=L;
}
void InitSortStructure(SortStructure *S,char *inf)
{
	S->inf=inf;
} 
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


void BubbleSort(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag用来作为标记 */
	for(i=1;i<L->length && flag;i++) /* 若flag为true说明有过数据交换，否则停止循环 */
	{
		flag=FALSE;				/* 初始为False */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* 交换L->r[j]与L->r[j+1]的值 */
				 flag=TRUE;		/* 如果有数据交换，则flag为true */
			}
		}
	}
}
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						// 将当前下标定义为最小值下标 */
		for (j = i+1;j<=L->length;j++)// 循环之后的数据 */
        {
			if (L->r[min]>L->r[j])
			{	// 如果有小于当前最小值的关键字 */
                min = j;		// 将此关键字的下标赋值给min */

			}		
        }
		if(i!=min)
		{// 若min不等于i，说明找到最小值，交换 */
				swap(L,i,min);		// 交换L->r[i]与L->r[min]的值 */

		}						
				
	}
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

int Partition(SqList *L,int low,int high)
{ 
	L->r[0]=L->r[low]; // 用子表的第一个记录作枢轴记录  
	while(low<high) //  从表的两端交替地向中间扫描  
	{ 
		 while(low<high&&L->r[high]>=L->r[0])
		 {
		 	high--;
		 
		 }
		 swap(L,low,high);// 将比枢轴记录小的记录交换到低端  
	
		 while(low<high&&L->r[low]<=L->r[0])
		 {
		 		low++;
		 		
		 }
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
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}
int main()
{
	SqList sl;
	clock_t timePast;
	clock_t timeNow;
	int i,j,dlta[14]={43,41,37,31,29,23,19,17,13,11,7,5,3,1};
	double temp;

	sl.length=10000;
	
	SortStructure S[9];
	InitSortStructure(&S[0],"冒泡排序"); 
	InitSortStructure(&S[1],"选择排序"); 
	InitSortStructure(&S[2],"插入排序"); 
	InitSortStructure(&S[3],"归并排序");
	InitSortStructure(&S[4],"快速排序"); 
	InitSortStructure(&S[5],"堆排序"); 
	InitSortStructure(&S[6],"希尔排序"); 
	InitSortStructure(&S[7],"基数排序"); 
	InitSortStructure(&S[8],"数组排序"); 
	printf("\n为了演示效果此程序将用各种排序方式排序100组10000个元素的随机数组\n并且取其平均比较次数和平均时间来对比\n"); 
	printf("请耐心等待，大概要一分钟....\n\n");
	for(i=0;i<NUM;i++)
	{
//		完成100次排序 
		for(j=1;j<=sl.length;j++)
			sl.r[j]=rand()%10000;
		for(j=0;j<9;j++)
		{
			InitSortStructureSqlist(&S[j],sl);//设置每次的随机数组 
		}
			
		timePast=clock();	
		BubbleSort(&S[0].L);
		timeNow=clock();
		S[0].times[i]=(timeNow-timePast);
//		printf("%f",S[0].times[i]);
		
		timePast=clock();	
		SelectSort(&S[1].L);
		timeNow=clock();
		S[1].times[i]=(timeNow-timePast);
		
		timePast=clock();	
		InsertSort(&S[2].L);
		timeNow=clock();
		S[2].times[i]=(timeNow-timePast);
		
		timePast=clock();
		MergeSort(&S[3].L);
		timeNow=clock();
		S[3].times[i]=(timeNow-timePast);
		
		timePast=clock();
		QuickSort(&S[4].L);
		timeNow=clock();
		S[4].times[i]=(timeNow-timePast);
			
		timePast=clock();
		HeapSort(&S[5].L);
		timeNow=clock();
		S[5].times[i]=(timeNow-timePast);
		
		timePast=clock();	
		ShellSort(&S[6].L,dlta,14);
		timeNow=clock();
		S[6].times[i]=(timeNow-timePast);
		
		timePast=clock();	
		ArraySort(&S[8].L,10000);
		timeNow=clock();
		S[8].times[i]=(timeNow-timePast);
		
	}
	for(i=0;i<9;i++) 
	{
					
		temp=0;
		for(j=0;j<NUM;j++)
		{
			temp+=S[i].times[j]/NUM;
//			printf(" %f ",S[i].times[j]);
		}
			
		S[i].averagetime=temp/(CLOCKS_PER_SEC*1.0);
	}
	
	for(i=0;i<9;i++) 
	{
		printf("%-10s ",S[i].inf);
		printf(" 平均时间%f秒\n",S[i].averagetime);
	}
	return 0;
} 
