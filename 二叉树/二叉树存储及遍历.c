#include <stdio.h>
#include <stdlib.h> 
typedef int Status;
typedef char TElemType;
//----------------二叉树的二叉链表储存 ---------------- 
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,BiTree;
Status CreateBiTree(BiTree *T)
{
	//按顺序输入二叉树中结点的值 ，空格表示空树，构造二叉链表表示的二叉树T 
}
Status preOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//先序遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
}
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//中遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
}
Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//后序遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
}
Status LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//采用二叉链表储存结构，Visit 是对结点操作的函数
	//层序遍历二叉树T，对每个结点调用函数Visit有且只有一次 
	//一旦Visit失败，则操作失败	
}
int main()
{

	return 0;
}
