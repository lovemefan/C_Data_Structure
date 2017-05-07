#include <stdio.h>
int YangHui(int i,int j)
{
	if(j==0 || i==j)	
		return 1;
	else
		return YangHui(i-1,j)+YangHui(i-1,j-1);
	
}
int main()
{
	int i,j,k,h=10,l=10;
	int a; 
	for(i=0;i<h;i++)
	{
		for(j=0;j<=i;j++)
		{
			a=YangHui(i,j);
			printf("%-d ",a);	
		}
		printf("\n");
	}
		
		
	return 0;
}
