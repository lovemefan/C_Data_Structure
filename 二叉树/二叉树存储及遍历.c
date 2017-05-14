#include <stdio.h>
#include <stdlib.h> 
#define OK 1
#define ERROR 0
typedef int Status;
typedef char TElemType;
//----------------�������Ķ��������� ---------------- 
typedef struct Node{
	TElemType data;
	struct Node *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
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
	printf("�������������Կ���#����\n");
	CreateBiTree(&T);
	printf("\n�������");
	PreOrderTraverse(T,Visit); 
	printf("\n�������");
	InOrderTraverse(T,Visit);
	printf("\n�������");
	PostOrderTraverse(T,Visit);
	
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
