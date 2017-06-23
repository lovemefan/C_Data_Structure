/*�����ѹ���洢 ��ϡ�����
* ����ֵ������ ��������һЩ�׼��ܸ߷�������ʱΪ�˽�ʡ�洢�ռ䣬����
����ѹ���洢 

*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 12500
#define TRUE  1
#define FLASE 0
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct
{//��Ԫ��˳���iΪ�����б꣬jΪ�����б꣬eΪ����Ԫ�� 
	int i,j;
	ElemType e;
}Triple;

typedef struct 
{
	Triple Data[MAXSIZE+1];
	int mu,nu,tu;//muΪ������� ��nuΪ������У�tuΪ���������� 
}TSMatrix;

Status InitData(TSMatrix *data,int m,int n)
{
// ��ʼ��һ������ 
	data->mu=m  ;
	
}
Status CreateSMatrix(TSMatrix *M)
{
//	����һ��ϡ����� 
} 
void DestroySMatrix(TSMatrix *M)
{
//	ɾ��һ������ 
} 
Status PrintSMatrix(TSMatrix M)
{
//	��ʼ����  ϡ������Ѵ��� ����ӡ������M 
 
} 
Status CopySMatrix(TSMatrix M,TSMatrix *N)
{
//	��ʼ����  ϡ������Ѵ���  ��������M����N�� 
}
Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	��ʼ����  ϡ������Ѵ���  ����ϡ�����M��N�ĺ� Q=M+N
	int  pa=1,pb=1,pc=1; 
	int row,ce; 
	if(M.mu!=N.mu && M.nu!=N.nu) return ERROR;//M,N��һ�£��޷���� 
	Q->mu=M.mu;
	Q->nu=M.nu;
	Q->tu=0;
	for(row=1;row<=M.mu;row++)
	{
		while(M.Data[pa].i<row && pa<M.tu) 
			pa++; //����ɨ��M 
			
		while(N.Data[pb].i<row && pb<N.tu) 
			pb++; //����ɨ��N
		
		while(M.Data[pa].i==row && N.Data[pb].i==row && pa<=M.tu && pb<=N.tu) 
		{
			if(M.Data[pa].j=N.Data[pb].j)
			{
				ce=M.Data[pa].e+N.Data[pb].e;
				if(ce)
				{
					Q->Data[pc].i=row;
					Q->Data[pc].j=M.Data[pa].j;
					Q->Data[pc].e=ce;
					pa++;
					pb++;
					pc++;
					
				}
			}
			else
			{
				if(M.Data[pa].j>N.Data[pb].j)
				{
					Q->Data[pc].i=row;
					Q->Data[pc].j=N.Data[pb].j;
					Q->Data[pc].e=N.Data[pb].e;
					pb++;
					pc++;
				}
				else
				{
					Q->Data[pc].i=row;
					Q->Data[pc].j=M.Data[pa].j;
					Q->Data[pc].e=M.Data[pa].e;
					pa++;
					pc++;
					
				}
			}
//				printf("&&&&&&&&&");
		}
		
//		��ʣ�µĸ��Ƶ�Q�� 
		while(M.Data[pa].i==row && pa<=M.tu)
		{
			Q->Data[pc].i=row;
			Q->Data[pc].j=M.Data[pa].j;
			Q->Data[pc].e=M.Data[pa].e;
			pa++;
			pc++;
		}
		while(N.Data[pb].i==row && pb<=N.tu)
		{
			Q->Data[pc].i=row;
			Q->Data[pc].j=N.Data[pb].j;
			Q->Data[pc].e=N.Data[pb].e;
			pb++;
			pc++;
		}
		
			printf("________  ");
	} 

	Q->tu=pc-1;
 
}
Status SubtMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	��ʼ����  ϡ������Ѵ���  ����ϡ�����M,N�Ĳ� Q=M-N
}
Status MultMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	��ʼ����  ϡ������Ѵ���  ����ϡ�����M,N�ĳ˻� Q=M*N
}
Status TransposeSMatrix(TSMatrix M,TSMatrix *T)
{
//	��ʼ����  ϡ������Ѵ��� ��������ת�þ��� 
	int q,p,col,t;
	int num[M.nu+1],cpot[M.nu+1];//num������ԭ����ÿ�У�ת�ƾ������������Ԫ�ظ��� ,��ʹ��num[0]
	(*T).mu=M.nu;
	(*T).nu=M.mu; 
	(*T).tu=M.tu;
	if((*T).tu)
		{
		
			for(col=1;col<=M.nu;col++) num[col]=0; //�Ƚ�num����ȫ����ʼ��Ϊ��
			for(t=1;t<M.tu;t++) ++num[M.Data[t].j];//ͳ��ÿ��Ԫ�صĸ��������ŵ�num������
			cpot[1]=1;//��ʼλ��Ϊ1
			for(col=2;col<=M.nu;col++) cpot[col]=cpot[col-1]+num[col-1];//���������ÿ�У�ת�ƾ������������һ��Ԫ�صĳ�ʼλ�� 
			for(p=1;p<=M.tu;p++)
			{
				col=M.Data[p].j; q=cpot[col];//qΪ��Ҫ�����λ�� 
				(*T).Data[q].i=M.Data[p].j; 
				(*T).Data[q].j=M.Data[p].i; 
				(*T).Data[q].e=M.Data[p].e;
				++cpot[col];// ÿ�У�ת�ƾ������������һ��Ԫ�صĳ�ʼλ�ü�һ 
					
			} 
			
		}	
 	return OK; 
} 
Status InverseSMatrix(TSMatrix M,TSMatrix *T)
{
//	��ʼ����  ϡ������Ѵ��� ������������� 
 
} 
Status MatrixToSMatrix(int M[6][6],int c,int r,TSMatrix *SM)
{
	//
	int i,j;
	int k=1;//���Ԫ�ز��� 
//	printf("%d",*(*(M+1)+1));
	if(!SM) return ERROR;
	if(c<0||r<0) return ERROR;
	for(i=0;i<c;i++)
		for(j=0;j<r;j++)
		{
			if(M[i][j])
			{
				SM->Data[k].i=i+1;
				SM->Data[k].j=j+1;
				SM->Data[k++].e=M[i][j];
			}
				
		}
	SM->mu=c;
	SM->nu=r;
	SM->tu=k-1;
	return OK;

}
void SMarixTraverse(TSMatrix M)
{
	int i;
	for(i=1;i<=M.tu;i++)
	{
		printf("(%d,%d,%d) ",M.Data[i].i,M.Data[i].j,M.Data[i].e);
	}
	printf("\n");
}
int main()
{
	TSMatrix SM,SQ,Q;
	int a[6][6]={
		{0,0,1,0,0,0},
		{0,0,0,0,8,0},
		{4,0,1,0,0,0},
		{0,3,2,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,6,0}
		
	}; 
	int b[6][6]={
		{0,0,0,0,5,0},
		{0,0,0,0,8,0},
		{6,0,-1,0,0,0},
		{0,3,2,0,0,0},
		{0,0,0,8,0,0},
		{0,0,2,0,6,0}
		
	}; 
	InitData(&SM,6,6);
	InitData(&SQ,6,6);
	MatrixToSMatrix(a,6,6,&SM);
	MatrixToSMatrix(b,6,6,&SQ);
	SMarixTraverse(SM);
	SMarixTraverse(SQ);
	AddSMatrix(SM,SQ,&Q);

	SMarixTraverse(Q);
	return 0;
}

