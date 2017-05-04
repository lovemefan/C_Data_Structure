#include <stdio.h> 
#include <stdlib.h>
typedef int datatype;
struct  stackList{
	datatype data;
	struct list *next;
};
int main()
{
	struct stackList *head=(struct stackList*)malloc(sizeof(struct stackList)); 
	init(&head);
	
	while(1)
	{
		int option;
		system("cls");
		
		printf("\n\n");
		printf("\t\t\t********************ѡ����Ҫִ�е�ָ��*********************��\n");
		printf("\t\t\t*                      1��ջ                              *\n");
		printf("\t\t\t*                      2��ջ                              *\n");
		printf("\t\t\t*                      3���                              *\n");
		printf("\t\t\t***********************************************************\n");
		scanf("%d",&option) ;
		switch(option)
		{	
	 		case 1:push(&head);break;
			case 2:pop(&head);break;
			case 3:printout(head);break;
			default :printf("�����������������\n");break;
	 	}
	 	 system("pause");/*��ͣ*/
	}
	return 0;
}
void push(struct stackList **head)
{
	struct stackList *new;
	datatype n;
	new=(struct stackList *)malloc(sizeof(struct stackList));
	printf("������һ����\n");
	scanf("%d",&n);
	new->data=n;
	new->next=*head;
	*head=new;
	
}

void pop(struct stackList **head)
{
	if((*head)->next==NULL)
	{ 
		printf("ջ�ѿ�");
	}
	else
	{
		struct stackList *p;
		p=*head;
		*head=p->next;
		free(p);
	} 
		
}
void init(struct stackList **head)
{
	(*head)->data=0;
	(*head)->next=NULL;
}
void printout(struct stackList *head)
{
	struct stackList *p;
	p=head;
	printf("\n");
	while(p->next!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	
}
