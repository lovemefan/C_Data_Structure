#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define MAXSIZE 20 
typedef int Status;
typedef char TElemType;
//----------------------------------�������Ķ��������� -------------------------------------- 
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
//----------------------------------����������ṹ----------------------------------------- 
// ****************************  

// �õ��Ķ��нṹ�뺯��**********************************  
// ѭ�����е�˳��洢�ṹ  
typedef struct
{
	BiTNode data[MAXSIZE];
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
Status EnQueue(Queue *Q,BiTNode e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	// ���������ж�  
		return ERROR;
	Q->data[Q->rear]=e;			// ��Ԫ��e��ֵ����β  
	Q->rear=(Q->rear+1)%MAXSIZE;// rearָ�������һλ��,  
								// ���������ת������ͷ��  
	return  OK;
}

// �����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ  
Status DeQueue(Queue *Q,BiTNode *e)
{
	if (Q->front == Q->rear)			// ���пյ��ж�  
		return ERROR;
	*e=Q->data[Q->front];				// ����ͷԪ�ظ�ֵ��e  
	Q->front=(Q->front+1)%MAXSIZE;	// frontָ�������һλ��,  
									// ���������ת������ͷ��  
	return  OK;
}
// ******************************************************  


//---------------------------------------����������--------------------------------------------------------
Status CreateBiTree(BiTree *T)
{
	//��˳������������н���ֵ ���ո��ʾ��������������������ʾ�Ķ�����T 
	//�������򣬺��򣬽���û�кܴ�����ͬ�����������룬ֻ�Ǵ����˳��ͬ 
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
Status InOrderCreateBiTree(BiTree *T)
{
	//��˳������������н���ֵ ���ո��ʾ��������������������ʾ�Ķ�����T 
	//�������򣬺��򣬽���û�кܴ�����ͬ�����������룬ֻ�Ǵ����˳��ͬ 
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
			
			if(CreateBiTree(&(*T)->lchild));
			(*T)->data=c;
			if(CreateBiTree(&(*T)->rchild));
		} 
	}
	return OK;
}
Status PostCreateBiTree(BiTree *T)
{
	//��˳������������н���ֵ ���ո��ʾ��������������������ʾ�Ķ�����T 
	//�������򣬺��򣬽���û�кܴ�����ͬ�����������룬ֻ�Ǵ����˳��ͬ 
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
			
			if(CreateBiTree(&(*T)->lchild));
			if(CreateBiTree(&(*T)->rchild));
			(*T)->data=c;
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
	Queue LQ;
	InitQueue(&LQ);
	BiTNode p;//���ճ����еĽ��
	if(T)
	{
		EnQueue(&LQ,*T);
		while(!QueueEmpty(LQ))
		{
			DeQueue(&LQ,&p);
	 
			printf("%c ",p.data);
			if(p.lchild)
			{
				EnQueue(&LQ,*(p.lchild));
			}
				
			if(p.rchild)
			{
				EnQueue(&LQ,*(p.rchild));
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
Status ExchangeTree(BiTree *T)
{
	//�����������������ҽڵ㣬ʹ�ý����������ԭ������Գ� 
	BiTree temp;
		if(*T)
		{
			temp=(*T)->lchild;
			(*T)->lchild=(*T)->rchild;
			(*T)->rchild=temp;
			
		
			ExchangeTree(&(*T)->lchild);
			ExchangeTree(&(*T)->rchild);
			return OK;
		}
		else
			return ERROR;	
} 
Status EqualTree(BiTree M,BiTree N)
{
//	�ж�M,N�������Ƿ���ͬ 
	if(M&&N)
	{
		if(M->data==N->data)
		{
			if(EqualTree(M->lchild,N->lchild))
			{
				if(EqualTree(M->rchild,N->rchild))
					return OK;
				else
					return ERROR;//��������ͬ 
			}
			else	
				return ERROR;//��������ͬ 
		}
		else
			return ERROR;//�ڵ㲻ͬ 
	} 
	else
	{
		if(M==NULL&&N==NULL)
			return OK;//��Ϊ������ͬ 
		else 
			return ERROR;//ͷ���������һ��Ϊ�� 
	} 
		
}
int main()
{
	BiTree T;
	int n;
	BiTNode p;
	Queue LQ;
	InitQueue(&LQ);
	printf("�������������Կ���#����\n");
	CreateBiTree(&T);
	printf("\n�������");
	PreOrderTraverse(T,Visit); 
	printf("\n�������");
	InOrderTraverse(T,Visit);
	printf("\n�������");
	PostOrderTraverse(T,Visit);
	

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
	
	printf("������Ľ��"); 
	if(!ExchangeTree(&T))
		printf("����ʧ��");
	printf("\n�������");
	PreOrderTraverse(T,Visit); 
	printf("\n�������");
	InOrderTraverse(T,Visit);
	printf("\n�������");
	PostOrderTraverse(T,Visit);
	return 0;
}
