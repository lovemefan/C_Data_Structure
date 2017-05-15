#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;
typedef char TElemType;
//----------------------------------二叉树的二叉链表储存 -------------------------------------- 
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;
//----------------------------------队列链表储存结构----------------------------------------- 
typedef struct qnode	/* 队列结点结构 */
{
   BiTNode elem;
   struct qnode *next;
}QNode,*QueuePtr;

typedef struct			/* 队列的链表结构 */
{
   QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;


//---------------------------------------队列操作函数------------------------------------------
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
	if(!s) /* 存储分配失败 */
		exit(OVERFLOW);
	s->elem=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	Q->rear=s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
Status DeQueue(LinkQueue *Q,BiTNode *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* 将欲删除的队头结点暂存给p，见图中① */
	*e=(p->elem);				/* 将欲删除的队头结点的值赋值给e */
	Q->front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if(Q->rear==p)		/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
		Q->rear=Q->front;
	free(p);
	return OK;
}
//---------------------------------------二叉树操作--------------------------------------------------------
Status CreateBiTree(BiTree *T)
{
	//按顺序输入二叉树中结点的值 ，空格表示空树，构造二叉链表表示的二叉树T 
	char c;
	do
	{
		c=getchar();
	}
	while(c==32 || c=='\n');//跳过空格或回车 
	if(c=='#')
		(*T)=NULL;
	else
	{
		if(!((*T)=(BiTree)malloc(sizeof(BiTNode))))
			return ERROR;//内存不足 
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
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//先序遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
	//	先序遍历二叉树的操作定义：
	//	若二叉树为空，则空操作；否则n  
	//	1） 访问根结点
	//	2） 先序遍历左子树
	//	3） 先序遍历右子树
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
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//中遍历二叉树*T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
	//中序遍历二叉树的操作定义：
	//	若二叉树为空，则空操作；否则
	//	1） 中序遍历左子树
	//	2） 访问根结点
	//	3） 中序遍历右子树
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
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//后序遍历二叉树*T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
	//后序遍历二叉树的操作定义：
	//	若二叉树为空，则空操作；否则
	//	1） 后序遍历左子树
	//	2） 后序遍历右子树
	//	3） 访问根结点
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
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//层序遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
	//	层次遍历二叉树的操作定义：
	//	若二叉树为空，则空操作；否则
	//	1） 从上到下
	//	2） 同一层，从左到右依次遍历
	LinkQueue LQ;
	InitQueue(&LQ);
	BiTNode p;//接收出队列的结点
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
				printf("%c进队列 ",(p.lchild)->data);
			}
				
			if(p.lchild!=NULL)
			{
				EnQueue(&LQ,*(p.rchild));
				printf("%c进队列 ",(p.rchild)->data);
			}
				
		}
		
	} 
	return OK; 
}
int  LeafNodeNum(BiTree T)
{
//	求叶子结点的数量 
	int n1,n2;//左右子树的叶子数 
	if(!T)
			return 0;
	else
	{
		if(!T->lchild&&!T->rchild) 
		{
//			printf("%c是叶子\n",T->data);
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
//	求单节点的数量 
	int n1,n2;//左右子树的单节点 
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
//	求双节点的数量 
	int n1,n2;//左右子树的双节点 
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
//	求树的深度 
	int n1,n2;//左右子数的高度
	if(!T)
		return 0;
	else
	{
		n1=TreeDepth(T->lchild);
		n2=TreeDepth(T->rchild);
		return 1+(n1>n2?n1:n2);	//左右子数中最高的数加一 
	} 
	
}
int AllNodeNum(BiTree T)
{
//	求所有结点数
	int n1,n2;//左右子树的结点数 
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
	printf("先序输入树，以空以#结束\n");
	CreateBiTree(&T);
	printf("\n先序遍历");
	PreOrderTraverse(T,Visit); 
	printf("\n中序遍历");
	InOrderTraverse(T,Visit);
	printf("\n后序遍历");
	PostOrderTraverse(T,Visit);
	
	EnQueue(&LQ,*T);	

	DeQueue(&LQ,&p);

	printf("\n层序遍历");
	LevelOrderTraverse(T,Visit);
	
	n=LeafNodeNum(T);
	printf("\n叶子节点数 %d \n",n);
	
	n=SingleNodeNum(T);
	printf("单节点数 %d \n",n);
	
	n=DoubleNodeNum(T);
	printf("双节点数 %d \n",n);
	
	n=AllNodeNum(T);
	printf("总结点数 %d \n",n);
	
	n=TreeDepth(T);
	printf("树的深度 %d \n",n);
	
	return 0;
}
