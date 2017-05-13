/*矩阵的压缩存储 （稀疏矩阵）
* 在数值计算中 经常出现一些阶级很高发矩阵。有时为了节省存储空间，可以
进行压缩存储 

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
{//三元组顺序表，i为矩阵行标，j为矩阵列标，e为矩阵元素 
	int i,j;
	ElemType e;
}Triple;

typedef struct 
{
	Triple Data[MAXSIZE+1];
	int mu,nu,tu;//mu为矩阵的行 ，nu为矩阵的列，tu为矩阵非零个数 
}TSMatrix;

Status InitData(TSMatrix *data,int m,int n)
{
// 初始化一个矩阵 
	data->mu=m  ;
	
}
Status CreateSMatrix(TSMatrix *M)
{
//	创建一个稀疏矩阵 
} 
void DestroySMatrix(TSMatrix *M)
{
//	删除一个矩阵 
} 
Status PrintSMatrix(TSMatrix M)
{
//	初始条件  稀疏矩阵已存在 。打印出矩阵M 
 
} 
Status CopySMatrix(TSMatrix M,TSMatrix *N)
{
//	初始条件  稀疏矩阵已存在  。将矩阵M拷贝N中 
}
Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	初始条件  稀疏矩阵已存在  。求稀疏矩阵M，N的和 Q=M+N
	int  pa=1,pb=1,pc=1; 
	int row; 
	if(!M || !N) return ERROR;
	if(M.mu!=N.mu && M.nu!=N.nu) return ERROR;//M,N不一致，无法相加 
	*Q->mu=M.mu;
	*Q->nu=M.nu;
	*Q->tu=0;
	for(row=1;row<=M.mu;row++)
	{
		while(M.Data[pa].i<row && pa<M.tu) 
			pa++; //依次扫描M 
			
		while(M.Data[pb].i<row && pb<N.tu) 
			pb++; //依次扫描N
		
		while() 
		
	} 

 
}
Status SubtMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	初始条件  稀疏矩阵已存在  。求稀疏矩阵M,N的差 Q=M-N
}
Status MultMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) 
{
//	初始条件  稀疏矩阵已存在  。求稀疏矩阵M,N的乘积 Q=M*N
}
Status TransposeSMatrix(TSMatrix M,TSMatrix *T)
{
//	初始条件  稀疏矩阵已存在 。求矩阵的转置矩阵 
	int q,p,col,t;
	int num[M.nu+1],cpot[M.nu+1];//num数组存放原矩阵每列（转制矩阵的行数）的元素个数 ,不使用num[0]
	(*T).mu=M.nu;
	(*T).nu=M.mu; 
	(*T).tu=M.tu;
	if((*T).tu)
		{
		
			for(col=1;col<=M.nu;col++) num[col]=0; //先将num数组全部初始化为零
			for(t=1;t<M.tu;t++) ++num[M.Data[t].j];//统计每列元素的个数，并放到num数组中
			cpot[1]=1;//初始位置为1
			for(col=2;col<=M.nu;col++) cpot[col]=cpot[col-1]+num[col-1];//计算出矩阵每列（转制矩阵的行数）第一个元素的初始位置 
			for(p=1;p<=M.tu;p++)
			{
				col=M.Data[p].j; q=cpot[col];//q为将要插入的位置 
				(*T).Data[q].i=M.Data[p].j; 
				(*T).Data[q].j=M.Data[p].i; 
				(*T).Data[q].e=M.Data[p].e;
				++cpot[col];// 每列（转制矩阵的行数）第一个元素的初始位置加一 
					
			} 
			
		}	
 	return OK; 
} 
Status InverseSMatrix(TSMatrix M,TSMatrix *T)
{
//	初始条件  稀疏矩阵已存在 。求矩阵的逆矩阵 
 
} 
int main()
{
	
	return 0;
}
