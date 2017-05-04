#include <stdio.h>
#include "StackList.h"//此头文件为线性栈的基本操作头文件，将StackList.h放在与本文件同以目录下 
#define OK 1
#define ERROR 0
char OP[7][7]={
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','@'},
	{'>','>','>','>','@','>','>'},
	{'<','<','<','<','<','@','='}
};
char P[7]={'+','-','*','/','(',')','#'};
int In(char c)
{
	//判断c是否在P中 
	int i;
	for(i=0;i<7;i++)
		if(P[i]==c)
			break;
	if(i!=7)
		return OK;
	else 
		return ERROR;
		
	
}
int precede(char a,char b)
{
	int i,j,index;
	for(index=0;index<7;index++)
	{
		//查找 ab在数组OP中的位置 
		if(P[index]==a)
			i=index;
		if(P[index]==b)
			j=index;
	}
	return OP[i][j];
}
int Operate(int a,char theta,int b)
{
	switch(theta)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
} 

SElemType EvaluateExpression()
{
	SElemType c,e,e2,theta;//c为扫描时读入的字符，e为gettop的参数，用来返回栈顶的值，theta临时储存操作符 
	SElemType num1,num2;//num1num2为储存临时运算的值 
	SqStack OPTR,OPND;//POTR是操作符栈，OPOD是操作数栈
	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR,'#');
	c=getchar();
	while(c!='#' ||'#'!=GetTop(OPTR)&&GetTop(OPTR)!=-1)
	{
//		printf("现在字符栈顶为%c\n",GetTop(OPTR));
		if(!In(c))
		{
			//当c不在OP中时，说明c为数值，将c入数栈 
			if(c!=32&&c!='\n')
			{ 
			//如果是空格(ASCII为32)或回车，自动跳过 
			Push(&OPND,c-48);//c为字符变量，c-48为它本身int的值 
//			printf("进栈的数为%c\n",c); 
			}
			c=getchar();
		}
		else
		{
			switch(precede(GetTop(OPTR),c))
			{
				case '<' ://栈顶优先权低，运算符进栈
					Push(&OPTR,c);
//					printf("现在字符%c入栈\n",c);
					c=getchar();//继续读取下一个 
				break;
				case '>' ://栈顶优先权高，运算数出两个，运算符出一个进行运算 
					Pop(&OPND,&num2); 
					Pop(&OPND,&num1);
					Pop(&OPTR,&theta);
					Push(&OPND,Operate(num1,theta,num2));
//					printf("出栈数为%d  %c %d=%d \n",num1,theta,num2,GetTop(OPND));				 
				break;
				case '=' ://   '('与')'比较时 ,这时要去括号 
				c=getchar();
				Pop(&OPTR,&e); 
				break;
			}
		}
			
	}
	
	return GetTop(OPND);
	 
}

int main()
{
	int result;
	printf("输入一段表达式(目前数值只支持10以内的数，字符支持加减乘除及括号)，以'#'号结束\n");
	result=EvaluateExpression();
	printf("\n结果是%d ",result);
	return 0;
}
