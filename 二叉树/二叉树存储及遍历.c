#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
typedef int Status;
typedef char TElemType;
//----------------二叉树的二叉链表储存 ---------------- 
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;
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
	printf("先序输入树，以空以#结束\n");
	CreateBiTree(&T);
	printf("\n先序遍历");
	PreOrderTraverse(T,Visit); 
	printf("\n中序遍历");
	InOrderTraverse(T,Visit);
	printf("\n后序遍历");
	PostOrderTraverse(T,Visit);
	
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
