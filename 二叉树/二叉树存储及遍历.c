#include <stdio.h>
#include <stdlib.h> 
typedef int Status;
typedef char TElemType;
//----------------�������Ķ��������� ---------------- 
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,BiTree;
Status CreateBiTree(BiTree *T)
{
	//��˳������������н���ֵ ���ո��ʾ������������������ʾ�Ķ�����T 
}
Status preOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
}
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�б���������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
}
Status PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
}
Status LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	//���ö���������ṹ��Visit �ǶԽ������ĺ���
	//�������������T����ÿ�������ú���Visit����ֻ��һ�� 
	//һ��Visitʧ�ܣ������ʧ��	
}
int main()
{

	return 0;
}
