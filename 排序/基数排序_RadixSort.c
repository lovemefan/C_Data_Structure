#include <stdio.h>
#include <time.h> 
#include <math.h>
#include <string.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
#define RADIXNUM 11//�ؼ�����������ʱ��ʮ���������Ļ��� 
typedef int Status;
typedef int KeyType;
typedef struct 
{
	char *c;
	int length;
}String;//��������ʱ��������Ϊ�ַ����� 
typedef struct 
{
	KeyType r[MAXSIZE+1];//���Ԫ����Ϊ�ڱ���Ԫ
	int length; 
}SqList;//��Ž�Ҫ��������� 
typedef struct 
{
	String data;
	string *next;
}RadixCell;
typedef struct 
{
	RadixCell* radixcell[RADIXNUM];//
}Radix;
InitString(String *S,char *c)
{
	int i;
	S->c=c;
	//��c���Ƶ�S�� 
	for(i=0;i<strlen(c);i++)
	{
		S->c[i]=c[i];
	}
	S->length=strlen(c);
}
void printString(String S)
{
	printf("%s\n",S.c);
}
void Distribute(SqList &L,Radix *R)
{
	
}
void collect(SqList &L,Radix *R)
{
}
void TraverseList(SqList L)
{
	int i;
	for(i=1;i<L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
void RadixSort(SqList *L,int range)
{
	// ����������ʵ������ǰ����������֪ͬ��Ҫ֪������Ԫ�صķ�Χ
	//rangeΪ��Ҫ���������ķ�Χ 
	
}
int main()
{
	String a;
	InitString(&a,"1234");
	printString(a);
	return 0;
}
