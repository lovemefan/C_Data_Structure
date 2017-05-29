#include "stdio.h"    
#include "stdlib.h"  
#define INFINITY INT_MAX 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 // ��󶥵�����Ӧ���û�����  
typedef enum {DG=1,DN,UDG,UDN} GraphKind;//ö�����ͣ��ֱ��� ����ͼ��������������ͼ�������� 
typedef int Status;	// Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��  
typedef char VertexType; // ��������Ӧ���û�����   
typedef int ArcType; // ���ϵ�Ȩֵ����Ӧ���û�����  
typedef struct
{
	VertexType vexs[MAXVEX]; // �����  
	ArcType arc[MAXVEX][MAXVEX];// �ڽӾ��󣬿ɿ����߱�  
	int vexnum, arcnum; // ͼ�е�ǰ�Ķ������ͱ���   
	GraphKind kind;//ͼ������ 
}MGraph;

// ��������ͼ���ڽӾ����ʾ  
void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("������ͼ�����ͣ�����ͼDG(1)��������DN(2)������ͼUDG(3)��������UDN(4)��\n"); 
	scanf("%d",&(G->kind));
	printf("���붥�����ͱ���:\n");
	scanf("%d %d",&G->vexnum,&G->arcnum); // ���붥�����ͱ���  
	printf("�����%d������\n",G->vexnum);
	for(i = 0;i <G->vexnum;i++) // ���붥����Ϣ,���������  
		scanf(&G->vexs[i]);
	for(i = 0;i <G->vexnum;i++)
		for(j = 0;j <G->vexnum;j++)
			G->arc[i][j]=INFINITY;	// �ڽӾ����ʼ��  
	for(k = 0;k <G->arcnum;k++) // ����arcnum���ߣ������ڽӾ���  
	{
		printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw:\n");
		scanf("%d %d %d",&i,&j,&w); // �����(vi,vj)�ϵ�Ȩw  
		G->arc[i][j]=w; 
		G->arc[j][i]= G->arc[i][j]; // ��Ϊ������ͼ������Գ�  
	}
}

int main(void)
{    
	MGraph G;    
	CreateMGraph(&G);
	
	return 0;
}

