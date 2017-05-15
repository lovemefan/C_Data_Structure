#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;
typedef char TElemType;
//----------------------------------�������Ķ��������� -------------------------------------- 
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
//----------------------------------����������ṹ----------------------------------------- 
typedef struct qnode	/* ���н��ṹ */
{
   BiTNode elem;
   struct qnode *next;
}QNode,*QueuePtr;

typedef struct			/* ���е�����ṹ */
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
}LinkQueue;


//---------------------------------------���в�������------------------------------------------
Status InitQueue(LinkQueue *Q)
{ 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(LinkQueue *Q,BiTNode e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �洢����ʧ�� */
		exit(OVERFLOW);
	s->elem=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q,BiTNode *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=(p->elem);				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if(Q->rear==p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
		Q->rear=Q->front;
	free(p);
	return OK;
}
//---------------------------------------����������--------------------------------------------------------
Status CreateBiTree(BiTree *T)
{
	//��˳������������н���ֵ ���ո��ʾ������������������ʾ�Ķ�����T 
	char c;
	do
	{
		c=getchar();
	}
	while(c==32 || c=='\n');//�����ո��س� 
	if(c=='#')
		(*T)=NULL;
	else
	{
		if(!((*T)=(BiTree)malloc(sizeof(BiTNode))))
			return ERROR;//�ڴ治�� 
		else
		{
			(*T)->data=c;
			if(CreateBiTree(&(*T)->lchild));
			if(CreateBiTree(&(*T)->rchild));
		} 
	}
	return OK;
}
Status Visit(TElemType elem)
{
	printf("%C ",elem);
	return OK;
}
Status PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
	//	��������������Ĳ������壺
	//	��������Ϊ�գ���ղ���������n  
	//	1�� ���ʸ����
	//	2�� �������������
	//	3�� �������������
	if(T)
	{
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit));
				if(PreOrderTraverse(T->rchild,Visit));
		return OK;
	}
	else
		return ERROR;
}
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�б���������*T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
	//��������������Ĳ������壺
	//	��������Ϊ�գ���ղ���������
	//	1�� �������������
	//	2�� ���ʸ����
	//	3�� �������������
	if(T)
	{
		if(InOrderTraverse(T->lchild,Visit));
			if(Visit(T->data))
				if(InOrderTraverse(T->rchild,Visit));
		return OK;
	}
	else
		return ERROR;
}
Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������*T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
	//��������������Ĳ������壺
	//	��������Ϊ�գ���ղ���������
	//	1�� �������������
	//	2�� �������������
	//	3�� ���ʸ����
	if(T)
	{
		if(PostOrderTraverse(T->lchild,Visit));
			if(PostOrderTraverse(T->rchild,Visit));
				if(Visit(T->data))
		return OK;
	}
	else
		return ERROR;
}
Status LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
	//	��α����������Ĳ������壺
	//	��������Ϊ�գ���ղ���������
	//	1�� ���ϵ���
	//	2�� ͬһ�㣬���������α���
	LinkQueue LQ;
	InitQueue(&LQ);
	BiTNode p;//���ճ����еĽ��
	if(T)
	{
		EnQueue(&LQ,*T);
//		printf("%c",LQ.front->data->data);	
		while(!QueueEmpty(LQ))
		{
			DeQueue(&LQ,&p);
	
			printf("%c ",p.data);
			if(p.lchild!=NULL)
			{
				EnQueue(&LQ,*(p.lchild));
				printf("%c������ ",(p.lchild)->data);
			}
				
			if(p.lchild!=NULL)
			{
				EnQueue(&LQ,*(p.rchild));
				printf("%c������ ",(p.rchild)->data);
			}
				
		}
		
	} 
	return OK; 
}
int  LeafNodeNum(BiTree T)
{
//	��Ҷ�ӽ������� 
	int n1,n2;//����������Ҷ���� 
	if(!T)
			return 0;
	else
	{
		if(!T->lchild&&!T->rchild) 
		{
//			printf("%c��Ҷ��\n",T->data);
			return 1;
		}
		else
		{
			n1=LeafNodeNum(T->lchild);
			n2=LeafNodeNum(T->rchild);
			return n1+n2;
		}
	}

	
}
int SingleNodeNum(BiTree T)
{
//	�󵥽ڵ������ 
	int n1,n2;//���������ĵ��ڵ� 
	if(!T)
		return 0;
	else
	{
		if(T->lchild&&!T->rchild || !T->lchild&&T->rchild)
			return 1;
		else
		{
			n1=SingleNodeNum(T->lchild);
			n2=SingleNodeNum(T->rchild);
			return n1+n2;
		}
	}
	
} 
int DoubleNodeNum(BiTree T)
{
//	��˫�ڵ������ 
	int n1,n2;//����������˫�ڵ� 
	if(!T)
		return 0;
	else
	{
		n1=SingleNodeNum(T->lchild);
		n2=SingleNodeNum(T->rchild);
		if(T->lchild&&T->rchild)
		{	
			return 1+n1+n2;
		}
		else
		{
			return n1+n2;
		}
	}
	
} 
int TreeDepth(BiTree T)
{
//	��������� 
	int n1,n2;//���������ĸ߶�
	if(!T)
		return 0;
	else
	{
		n1=TreeDepth(T->lchild);
		n2=TreeDepth(T->rchild);
		return 1+(n1>n2?n1:n2);	//������������ߵ�����һ 
	} 
	
}
int AllNodeNum(BiTree T)
{
//	�����н����
	int n1,n2;//���������Ľ���� 
	if(!T)
	{
		return  0;
	} 
	else
	{
		n1=AllNodeNum(T->lchild);
		n2=AllNodeNum(T->rchild);
		return 1+n1+n2;
	}
}
int main()
{
	BiTree T;
	int n;
	BiTNode p;
	LinkQueue LQ;
	InitQueue(&LQ);
	printf("�������������Կ���#����\n");
	CreateBiTree(&T);
	printf("\n�������");
	PreOrderTraverse(T,Visit); 
	printf("\n�������");
	InOrderTraverse(T,Visit);
	printf("\n�������");
	PostOrderTraverse(T,Visit);
	
	EnQueue(&LQ,*T);	

	DeQueue(&LQ,&p);

	printf("\n�������");
	LevelOrderTraverse(T,Visit);
	
	n=LeafNodeNum(T);
	printf("\nҶ�ӽڵ��� %d \n",n);
	
	n=SingleNodeNum(T);
	printf("���ڵ��� %d \n",n);
	
	n=DoubleNodeNum(T);
	printf("˫�ڵ��� %d \n",n);
	
	n=AllNodeNum(T);
	printf("�ܽ���� %d \n",n);
	
	n=TreeDepth(T);
	printf("������� %d \n",n);
	
	return 0;
}
