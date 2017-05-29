#include "stdio.h"    
#include "stdlib.h"  
#define INFINITY INT_MAX 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 // 最大顶点数，应由用户定义  
typedef enum {DG=1,DN,UDG,UDN} GraphKind;//枚举类型，分别是 有向图，有向网，无向图，无向网 
typedef int Status;	// Status是函数的类型,其值是函数结果状态代码，如OK等  
typedef char VertexType; // 顶点类型应由用户定义   
typedef int ArcType; // 边上的权值类型应由用户定义  
typedef struct
{
	VertexType vexs[MAXVEX]; // 顶点表  
	ArcType arc[MAXVEX][MAXVEX];// 邻接矩阵，可看作边表  
	int vexnum, arcnum; // 图中当前的顶点数和边数   
	GraphKind kind;//图的类型 
}MGraph;

// 建立无向图的邻接矩阵表示  
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("请输入图的类型（有向图DG(1)，有向网DN(2)，无向图UDG(3)，无向网UDN(4)）\n"); 
	scanf("%d",&(G->kind));
	printf("输入顶点数和边数:\n");
	scanf("%d %d",&G->vexnum,&G->arcnum); // 输入顶点数和边数  
	printf("输入各%d个顶点\n",G->vexnum);
	for(i = 0;i <G->vexnum;i++) // 读入顶点信息,建立顶点表  
		scanf(&G->vexs[i]);
	for(i = 0;i <G->vexnum;i++)
		for(j = 0;j <G->vexnum;j++)
			G->arc[i][j]=INFINITY;	// 邻接矩阵初始化  
	for(k = 0;k <G->arcnum;k++) // 读入arcnum条边，建立邻接矩阵  
	{
		printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
		scanf("%d %d %d",&i,&j,&w); // 输入边(vi,vj)上的权w  
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; // 因为是无向图，矩阵对称  
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}

