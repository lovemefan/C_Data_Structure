#include <stdio.h>   
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 // 存储空间初始分配量  

typedef int Status;	// Status是函数的类型,其值是函数结果状态代码，如OK等   
typedef int ElemType;

// 二叉树的二叉链表结点结构定义  
typedef  struct BiTNode	// 结点结构  
{
	ElemType data;	// 结点数据  
	struct BiTNode *lchild, *rchild;	// 左右孩子指针  
} BiTNode, *BiTree;


// 递归查找二叉排序树T中是否存在key,  
// 指针f指向T的双亲，其初始调用值为NULL  
// 若查找成功，则指针p指向该数据元素结点，并返回TRUE  
// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE  
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{  
	if (!T)	//  查找不成功  
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) //  查找成功  
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  //  在左子树中继续查找  
	else  
		return SearchBST(T->rchild, key, T, p);  //  在右子树中继续查找  
}


//  当二叉排序树T中不存在关键字等于key的数据元素时，  
//  插入key并返回TRUE，否则返回FALSE  
Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) // 查找不成功  
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;			//  插入s为新的根结点  
		else if (key<p->data) 
			p->lchild = s;	//  插入s为左孩子  
		else 
			p->rchild = s;  //  插入s为右孩子  
		return TRUE;
	} 
	else 
		return FALSE;  //  树中已有关键字相同的结点，不再插入  
}

// 从二叉排序树中删除结点p，并重接它的左或右子树。  
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL) // 右子树空则只需重接它的左子树（待删结点是叶子也走此分支)  
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) // 只需重接它的右子树  
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else // 左右子树均不空  
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) // 转左，然后向右到尽头（找待删结点的前驱）  
		{
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data; //  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值）  
		if(q!=*p)
			q->rchild=s->lchild; //  重接q的右子树   
		else
			q->lchild=s->lchild; //  重接q的左子树  
		free(s);
	}
	return TRUE;
}

// 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点,  
// 并返回TRUE；否则返回FALSE。  
Status DeleteBST(BiTree *T,int key)
{ 
	if(!*T) // 不存在关键字等于key的数据元素   
		return FALSE;
	else
	{
		if (key==(*T)->data) // 找到关键字等于key的数据元素   
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}
Status Visit(ElemType elem)
{
	printf("%d ",elem);
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
Status CreateBiTree(BiTree *T)
{
	//按顺序输入二叉树中结点的值 ，空格表示空树，先序构造二叉链表表示的二叉树T 
	//先序，中序，后序，建树没有很大区别，同样以先序输入，只是搭建树的顺序不同 
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
			(*T)->data=c-48;
			if(CreateBiTree(&(*T)->lchild));
			if(CreateBiTree(&(*T)->rchild));
		} 
	}
	return OK;
}
int main(void)
{    
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	
	CreateBiTree(&T);
//	for(i=0;i<10;i++)
//	{
//		InsertBST(&T, a[i]);
//	}
	printf("先序\n");
	PreOrderTraverse(T,Visit);
	printf("\n中序\n");
	InOrderTraverse(T,Visit);
	DeleteBST(&T,3);
//	DeleteBST(&T,35);
	
	printf("\n删除后\n先序\n");
	PreOrderTraverse(T,Visit);
	printf("\n中序\n");
	InOrderTraverse(T,Visit);
	
	return 0;
}
