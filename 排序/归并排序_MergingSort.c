#include <stdio.h>
#include <time.h> 
#define OK 1
#define NUM 100 
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000 //��Ҫ����ĸ��� 
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
// ****************�鲢����**********************************  

// �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]  
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	// ��SR�м�¼��С����ز���TR  
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		// ��ʣ���SR[i..m]���Ƶ�TR  
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		// ��ʣ���SR[j..n]���Ƶ�TR  
	}
}


// �ݹ鷨  
// ��SR[s..t]�鲢����ΪTR1[s..t]  
void MSort(int SR[],int TR1[],int s, int t)
{
//	SRΪ���������Ҫ��������飬TR1Ϊ�ź�����յ����� 
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				// ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]  
		MSort(SR,TR2,s,m);		// �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m]  
		MSort(SR,TR2,m+1,t);	// �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]  
		Merge(TR2,TR1,s,m,t);	// ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]  
	}
}

// ��˳���L���鲢����  
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
	
	printf("ԭ����\n");
	TraverseList(sl);
	
	timePast=clock();
	printf("\n�鲢�����\n");
	MergeSort(&sl);
	timeNow=clock();
	TraverseList(sl);
	printf("�鲢������ʱ%f��",(timeNow-timePast)/(CLOCKS_PER_SEC*1.0));
	
	
} 
