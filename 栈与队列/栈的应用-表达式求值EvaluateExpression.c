#include <stdio.h>
#include "StackList.h"//��ͷ�ļ�Ϊ����ջ�Ļ�������ͷ�ļ�����StackList.h�����뱾�ļ�ͬ��Ŀ¼�� 
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
	//�ж�c�Ƿ���P�� 
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
		//���� ab������OP�е�λ�� 
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
	SElemType c,e,e2,theta;//cΪɨ��ʱ������ַ���eΪgettop�Ĳ�������������ջ����ֵ��theta��ʱ��������� 
	SElemType num1,num2;//num1num2Ϊ������ʱ�����ֵ 
	SqStack OPTR,OPND;//POTR�ǲ�����ջ��OPOD�ǲ�����ջ
	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR,'#');
	c=getchar();
	while(c!='#' ||'#'!=GetTop(OPTR)&&GetTop(OPTR)!=-1)
	{
//		printf("�����ַ�ջ��Ϊ%c\n",GetTop(OPTR));
		if(!In(c))
		{
			//��c����OP��ʱ��˵��cΪ��ֵ����c����ջ 
			if(c!=32&&c!='\n')
			{ 
			//����ǿո�(ASCIIΪ32)��س����Զ����� 
			Push(&OPND,c-48);//cΪ�ַ�������c-48Ϊ������int��ֵ 
//			printf("��ջ����Ϊ%c\n",c); 
			}
			c=getchar();
		}
		else
		{
			switch(precede(GetTop(OPTR),c))
			{
				case '<' ://ջ������Ȩ�ͣ��������ջ
					Push(&OPTR,c);
//					printf("�����ַ�%c��ջ\n",c);
					c=getchar();//������ȡ��һ�� 
				break;
				case '>' ://ջ������Ȩ�ߣ����������������������һ���������� 
					Pop(&OPND,&num2); 
					Pop(&OPND,&num1);
					Pop(&OPTR,&theta);
					Push(&OPND,Operate(num1,theta,num2));
//					printf("��ջ��Ϊ%d  %c %d=%d \n",num1,theta,num2,GetTop(OPND));				 
				break;
				case '=' ://   '('��')'�Ƚ�ʱ ,��ʱҪȥ���� 
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
	printf("����һ�α��ʽ(Ŀǰ��ֵֻ֧��10���ڵ������ַ�֧�ּӼ��˳�������)����'#'�Ž���\n");
	result=EvaluateExpression();
	printf("\n�����%d ",result);
	return 0;
}
