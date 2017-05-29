#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 9 // �洢�ռ��ʼ������  
#define MAXARC 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	// Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��  
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE  

typedef char VertexType; // ��������Ӧ���û�����     
typedef int ArcType; // ���ϵ�Ȩֵ����Ӧ���û�����  

// �ڽӾ���ṹ  
typedef struct
{
	VertexType vexs[MAXVEX]; // �����  
	ArcType arc[MAXVEX][MAXVEX];// �ڽӾ���,�ɿ����߱�  
	int vexnum, arcnum; // ͼ�е�ǰ�Ķ������ͱ���   
}MGraph;

// �ڽӱ�ṹ******************  
typedef struct ArcNode // �߱���   
{
	int adjvex;    // �ڽӵ���,�洢�ö����Ӧ���±�  
	int weight;		// ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ  
	struct ArcNode *next; // ����,ָ����һ���ڽӵ�   
}ArcNode;

typedef struct VertexNode // �������   
{
	int in,out;	// ������� ����  
	VertexType data; // ������,�洢������Ϣ  
	ArcNode *firstedge;// �߱�ͷָ��     
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList; 
	int vexnum,arcnum; // ͼ�е�ǰ�������ͱ���  
}graphAdjList,*GraphAdjList;
// ****************************  

// �õ��Ķ��нṹ�뺯��**********************************  
// ѭ�����е�˳��洢�ṹ  
typedef struct
{
	int data[MAXSIZE];
	int front;    	// ͷָ��  
	int rear;		// βָ��,�����в���,ָ�����βԪ�ص���һ��λ��  
}Queue;

// ��ʼ��һ���ն���Q  
Status InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

// ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE  
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) // ���пյı�־  
		return TRUE;
	else
		return FALSE;
}

// ������δ��,�����Ԫ��eΪQ�µĶ�βԪ��  
Status EnQueue(Queue *Q,int e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	// ���������ж�  
		return ERROR;
	Q->data[Q->rear]=e;			// ��Ԫ��e��ֵ����β  
	Q->rear=(Q->rear+1)%MAXSIZE;// rearָ�������һλ��,  
								// ���������ת������ͷ��  
	return  OK;
}

// �����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ  
Status DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)			// ���пյ��ж�  
		return ERROR;
	*e=Q->data[Q->front];				// ����ͷԪ�ظ�ֵ��e  
	Q->front=(Q->front+1)%MAXSIZE;	// frontָ�������һλ��,  
									// ���������ת������ͷ��  
	return  OK;
}
// ******************************************************  






void CreateMGraph(MGraph *G)
{
	//Ϊ�˵������趨��һ���ڽӾ��� 
	int i, j;

	G->arcnum=15;
	G->vexnum=9;

	// ���붥����Ϣ,���������   
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->vexnum; i++)// ��ʼ��ͼ  
	{
		for ( j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

	
	for(i = 0; i < G->vexnum; i++)
	{
		for(j = i; j < G->vexnum; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
 
// �����ڽӾ��󹹽��ڽӱ�  
void CreateALGraph(MGraph G,GraphAdjList *GL)
{
	int i,j;
	ArcNode *e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->vexnum=G.vexnum;
	(*GL)->arcnum=G.arcnum;
	for(i= 0;i <G.vexnum;i++) // ���붥����Ϣ,���������     
	{
		(*GL)->adjList[i].in=0;
		(*GL)->adjList[i].data=G.vexs[i];
		(*GL)->adjList[i].firstedge=NULL; 	// ���߱���Ϊ�ձ�  
	}
	
	for(i=0;i<G.vexnum;i++) // �����߱�  
	{ 
		for(j=0;j<G.vexnum;j++)
		{
			if (G.arc[i][j]==1)
			{
				e=(ArcNode *)malloc(sizeof(ArcNode));
				e->adjvex=j;					// �ڽ����Ϊj                           
				e->next=(*GL)->adjList[i].firstedge;	// ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e  
				(*GL)->adjList[i].firstedge=e;		// ����ǰ�����ָ��ָ��e     
				(*GL)->adjList[j].in++;//j����ȼ�һ 
				(*GL)->adjList[i].out++;//i�ĳ��ȼ�һ 
				
			}
		}
	}
	
}
//void  CreateALGraph2(GraphAdjList *G)
//{
//	//�û����봴��һ���ڽӱ� 
//	int i,j,k,weigh;
//	ArcNode *e;
//	printf("���붥�����ͱ���:\n");
//	scanf("%d %d",&(G->vexnum),&(G->arcnum)); // ���붥�����ͱ���  
//	for(i = 0;i < G->nodenum;i++) // ���붥����Ϣ,���������  
//	{
//		scanf(&G->adjList[i].data); 	// ���붥����Ϣ  
//		G->adjList[i].firstarc=NULL; 	// ���߱���Ϊ�ձ�  
//	}
//	
//	
//	for(k = 0;k < G->arcnum;k++)// �����߱�  
//	{
//		printf("�����(vi,vj)�ϵĶ�����ź�Ȩֵ:\n");
//		scanf("%d %d %d",&i,&j,&weigh); // �����(vi,vj)�ϵĶ������  
//		e=(ArcNode *)malloc(sizeof(ArcNode)); // ���ڴ�����ռ�,���ɱ߱���  
//		e->adjvex=j;	
//		e->weight=weigh;				// �ڽ����Ϊj                           
//		e->next=G->adjList[i].firstarc;	// ��e��ָ��ָ��ǰ������ָ��Ľ��  
//		G->adjList[i].firstarc=e;		// ����ǰ�����ָ��ָ��e                 
//		e=(ArcNode *)malloc(sizeof(ArcNode)); // ���ڴ�����ռ�,���ɱ߱���  
//		e->adjvex=i;					// �ڽ����Ϊi                           
//		e->next=G->adjList[j].firstarc;	// ��e��ָ��ָ��ǰ������ָ��Ľ��  
//		G->adjList[j].firstarc=e;		// ����ǰ�����ָ��ָ��e                 
//	}
//}



Boolean visited[MAXSIZE]; // ���ʱ�־������  

// �ڽӱ��������ȵݹ��㷨  
void DFS(GraphAdjList GL, int i)
{
	ArcNode *p;
 	visited[i] = TRUE;
 	printf("%c ",GL->adjList[i].data);// ��ӡ����,Ҳ������������  
	p = GL->adjList[i].firstedge;
	while(p)
	{
 		if(!visited[p->adjvex])
 			DFS(GL, p->adjvex);// ��Ϊ���ʵ��ڽӶ���ݹ����  
		p = p->next;
 	}
}

// �ڽӱ����ȱ�������  
void DFSTraverse(GraphAdjList GL)
{
	int i;
 	for(i = 0; i < GL->vexnum; i++)
 		visited[i] = FALSE; // ��ʼ���ж���״̬����δ���ʹ�״̬  
	for(i = 0; i < GL->vexnum; i++)
 		if(!visited[i]) // ��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ��   
			DFS(GL, i);
}


void BFSTraverse(GraphAdjList GL)
{
	// �ڽӱ�Ĺ�ȱ����㷨  ,���㷨������������������ 
	int i,j;
    ArcNode *p;
	Queue Q;
	for(i = 0; i < GL->vexnum; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);
   	for(i = 0; i < GL->vexnum; i++)
   	{
		if (!visited[i])
		{
			visited[i]=TRUE;
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&j);
				printf("%c ",GL->adjList[j].data);
				p = GL->adjList[j].firstedge;	// �ҵ���ǰ����ı߱�����ͷָ��  
				while(p)
				{
					if(!visited[p->adjvex])	// ���˶���δ������  
 					{
 						visited[p->adjvex]=TRUE;
						EnQueue(&Q,p->adjvex);	// ���˶��������  
					}
					p = p->next;	// ָ��ָ����һ���ڽӵ�  
				}
			}
		}
	}
}

int main(void)
{    
	MGraph G;  
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);

	printf("\n��ȱ���:");
	DFSTraverse(GL);
	printf("\n��ȱ���:");
	BFSTraverse(GL);
	return 0;
}

