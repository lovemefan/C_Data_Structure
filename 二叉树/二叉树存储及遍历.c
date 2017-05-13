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
	c=getchar();
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
Status preOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
	if(T)
	{
		if(Visit(T->data))
			if(preOrderTraverse(T->lchild,Visit));
				if(preOrderTraverse(T->rchild,Visit));
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
		if(preOrderTraverse(T->lchild,Visit));
			if(Visit(T->data))
				if(preOrderTraverse(T->rchild,Visit));
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
		if(preOrderTraverse(T->lchild,Visit));
			if(preOrderTraverse(T->rchild,Visit));
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
int main()
{
	BiTree T;
	printf("�������������Կ���#����");
	CreateBiTree(&T);
	preOrderTraverse(T,Visit); 
	return 0;
}
