#include "stdio.h"    
#include "stdlib.h"   

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 // ��󶥵���,Ӧ���û�����  

typedef int Status;	// Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��  
typedef char VertexType; // ��������Ӧ���û�����  
typedef int ArcType; // ���ϵ�Ȩֵ����Ӧ���û�����  

typedef struct ArcNode // �߱���   
{
	int adjvex;    // �ڽӵ���,�洢�ö����Ӧ���±�  
	ArcType weigh;		// ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ  
	struct ArcNode *next; // ����,ָ����һ���ڽӵ�  
}ArcNode;

typedef struct VertexNode // �������  
{
	VertexType data; // ������,�洢������Ϣ  
	ArcNode *firstarc;// �߱�ͷָ��  
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int nodenum,arcnum; // ͼ�е�ǰ�������ͱ���  
}GraphAdjList;

// ����ͼ���ڽӱ�ṹ  
void  CreateALGraph(GraphAdjList *G)
{
	int i,j,k,weigh;
	ArcNode *e;
	printf("���붥�����ͱ���:\n");
	scanf("%d %d",&G->nodenum,&G->arcnum); // ���붥�����ͱ���  
	for(i = 0;i < G->nodenum;i++) // ���붥����Ϣ,���������  
	{
		scanf(&G->adjList[i].data); 	// ���붥����Ϣ  
		G->adjList[i].firstarc=NULL; 	// ���߱���Ϊ�ձ�  
	}
	
	
	for(k = 0;k < G->arcnum;k++)// �����߱�  
	{
		printf("�����(vi,vj)�ϵĶ�����ź�Ȩֵ:\n");
		scanf("%d %d %d",&i,&j,&weigh); // �����(vi,vj)�ϵĶ������  
		e=(ArcNode *)malloc(sizeof(ArcNode)); // ���ڴ�����ռ�,���ɱ߱���  
		e->adjvex=j;	
		e->weigh=weigh;				// �ڽ����Ϊj                           
		e->next=G->adjList[i].firstarc;	// ��e��ָ��ָ��ǰ������ָ��Ľ��  
		G->adjList[i].firstarc=e;		// ����ǰ�����ָ��ָ��e                 
		e=(ArcNode *)malloc(sizeof(ArcNode)); // ���ڴ�����ռ�,���ɱ߱���  
		e->adjvex=i;					// �ڽ����Ϊi                           
		e->next=G->adjList[j].firstarc;	// ��e��ָ��ָ��ǰ������ָ��Ľ��  
		G->adjList[j].firstarc=e;		// ����ǰ�����ָ��ָ��e                 
	}
}

int main(void)
{    
	GraphAdjList G;    
	CreateALGraph(&G);
	
	return 0;
}

