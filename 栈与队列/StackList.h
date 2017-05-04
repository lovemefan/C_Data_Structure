#include "stdio.h"    
#include "stdlib.h"   
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status; 
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

/* ˳��ջ�ṹ */
typedef struct
{
        SElemType data[MAXSIZE];
        int length;
        int top; /* ����ջ��ָ�� */
}SqStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  ����һ����ջS */
Status InitStack(SqStack *S)
{ 
        //S->data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); 
        S->top=-1;
        S->length=0;
        return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        S->length=0;
        return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return TRUE;
        else
                return FALSE;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* ��ջ���գ��򷵻�S��ջ��Ԫ��,���򷵻�-1 */
Status GetTop(SqStack S)
{
        if (S.top==-1)
            return -1;
        else
        	return S.data[S.top];
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ջ�� */
        {
                return ERROR;
        }
        S->top++;	
		S->length++;			/* ջ��ָ������һ */
        S->data[S->top]=e;  /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
        return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
        S->top--;	
		S->length--;			/* ջ��ָ���һ */
        return OK;
}

/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
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

