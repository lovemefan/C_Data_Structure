#include <stdio.h>
#include <time.h> 
#include <math.h>
#include <string.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
#define RADIXNUM 11//关键数基数，此时是十进制整数的基数 
typedef int Status;
typedef int KeyType;
typedef struct 
{
	char *c;
	int length;
}String;//基数排序时将数字作为字符处理 
typedef struct 
{
	KeyType r[MAXSIZE+1];//零号元素作为哨兵单元
	int length; 
}SqList;//存放将要排序的数组 
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
	//将c复制到S中 
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
	// 利用数组来实现排序，前提条件是已知同样要知道数组元素的范围
	//range为将要排序的数组的范围 
	
}
int main()
{
	String a;
	InitString(&a,"1234");
	printString(a);
	return 0;
}
