#include<stdio.h>
int step;
void main()
{
    int n;
    void hanoi(char,char,char,int);
    printf("please input the num;");
    scanf("%d",&n);
    hanoi('X','Y','Z',n);
}
void hanoi(char x,char y,char z,int n)
{
    if(n==1)
		{
			step++;
			printf("step.%6ld %c->%c\n",step,x,z);
		}
	   
	else
        {
            hanoi(x,z,y,n-1);
			step++;
            printf("step.%6ld %c->%c\n",step,x,z);
            hanoi(y,x,z,n-1);
        }
}
