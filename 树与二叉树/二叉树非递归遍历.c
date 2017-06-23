#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;
typedef char TElemType;
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;
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
			(*T)->data=c;
			if(CreateBiTree(&(*T)->lchild));
			if(CreateBiTree(&(*T)->rchild));
		} 
	}
	return OK;
}
int main()
{
	return 0;	
} 
