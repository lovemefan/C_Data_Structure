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
	struct Node *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
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
int main()
{
	return 0;	
} 
