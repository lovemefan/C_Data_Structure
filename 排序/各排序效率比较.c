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


typedef struct
{
	SqList L;
	char *inf;//��������ࣨ���ƣ� 
	int opration[NUM];
	double averageopration;//һ����¼�������������飬��һ����¼ƽ���������ı��� 
	double times[NUM],averagetime;//һ����¼����ʱ������飬��һ����¼ƽ��ʱ��ı��� 
}SortStructure;//�����һ���ṹ�� 

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


void BubbleSort(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;			/* flag������Ϊ��� */
	for(i=1;i<L->length && flag;i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
	{
		flag=FALSE;				/* ��ʼΪFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				 swap(L,j,j+1);	/* ����L->r[j]��L->r[j+1]��ֵ */
				 flag=TRUE;		/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						// ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=L->length;j++)// ѭ��֮������� */
        {
			if (L->r[min]>L->r[j])
			{	// �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;		// ���˹ؼ��ֵ��±긳ֵ��min */

			}		
        }
		if(i!=min)
		{// ��min������i��˵���ҵ���Сֵ������ */
				swap(L,i,min);		// ����L->r[i]��L->r[min]��ֵ */

		}						
				
	}
}
void InsertSort(SqList *L)
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) /* �轫L->r[i]���������ӱ� */
		{
			L->r[0]=L->r[i]; /* �����ڱ� */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; /* ��¼���� */
			L->r[j+1]=L->r[0]; /* ���뵽��ȷλ�� */
		}
	}
}

int Partition(SqList *L,int low,int high)
{ 
	L->r[0]=L->r[low]; // ���ӱ�ĵ�һ����¼�������¼  
	while(low<high) //  �ӱ�����˽�������м�ɨ��  
	{ 
		 while(low<high&&L->r[high]>=L->r[0])
		 {
		 	high--;
		 
		 }
		 swap(L,low,high);// ���������¼С�ļ�¼�������Ͷ�  
	
		 while(low<high&&L->r[low]<=L->r[0])
		 {
		 		low++;
		 		
		 }
		 swap(L,low,high);// ���������¼��ļ�¼�������߶�  
		 
	}
	return low; // ������������λ��  
}

// ��˳���L�е�������L->r[low..high]����������  
void QSort(SqList *L,int low,int high)
{ 
	int pivot;

	if(low<high)
	{
			pivot=Partition(L,low,high); //  ��L->r[low..high]һ��Ϊ�����������ֵpivot  
			QSort(L,low,pivot-1);		//  �Ե��ӱ�ݹ�����  
			QSort(L,pivot+1,high);		//  �Ը��ӱ�ݹ�����  
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
	InitSortStructure(&S[0],"ð������"); 
	InitSortStructure(&S[1],"ѡ������"); 
	InitSortStructure(&S[2],"��������"); 
	InitSortStructure(&S[3],"�鲢����");
	InitSortStructure(&S[4],"��������"); 
	InitSortStructure(&S[5],"������"); 
	InitSortStructure(&S[6],"ϣ������"); 
	InitSortStructure(&S[7],"��������"); 
	InitSortStructure(&S[8],"��������"); 
	printf("\nΪ����ʾЧ���˳����ø�������ʽ����100��10000��Ԫ�ص��������\n����ȡ��ƽ���Ƚϴ�����ƽ��ʱ�����Ա�\n"); 
	printf("�����ĵȴ������Ҫһ����....\n\n");
	for(i=0;i<NUM;i++)
	{
//		���100������ 
		for(j=1;j<=sl.length;j++)
			sl.r[j]=rand()%10000;
		for(j=0;j<9;j++)
		{
			InitSortStructureSqlist(&S[j],sl);//����ÿ�ε�������� 
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
		printf(" ƽ��ʱ��%f��\n",S[i].averagetime);
	}
	return 0;
} 
