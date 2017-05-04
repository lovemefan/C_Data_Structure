#include "stdio.h"    
#include "stdlib.h"   
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
        SElemType data[MAXSIZE];
        int length;
        int top; /* 用于栈顶指针 */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  构造一个空栈S */
Status InitStack(SqStack *S)
{ 
        //S->data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); 
        S->top=-1;
        S->length=0;
        return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        S->length=0;
        return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* 若栈不空，则返回S的栈顶元素,否则返回-1 */
Status GetTop(SqStack S)
{
        if (S.top==-1)
            return -1;
        else
        	return S.data[S.top];
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* 栈满 */
        {
                return ERROR;
        }
        S->top++;	
		S->length++;			/* 栈顶指针增加一 */
        S->data[S->top]=e;  /* 将新插入元素赋值给栈顶空间 */
        return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
        S->top--;	
		S->length--;			/* 栈顶指针减一 */
        return OK;
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(SqStack S)
{
        int i;
        i=S.top;
        for(;i>=0;i--)
        {
                visit(S.data[i]);
        }
        printf("\n");
        return OK;
}

