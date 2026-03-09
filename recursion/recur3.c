#include<stdio.h>
#include<stdlib.h>
void main()
{
	void fibonacci(int n,int c,int p,int cu);
	int n,c=2,p=0,cu=1;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	if(n==0)
		printf("Invalid");
	else if(n==1)
		printf("%d",p);
	else if(n==2)
		printf("%d %d ",p,cu);
	else
	{
		printf("%d %d ",p,cu);
		fibonacci(n,c,p,cu);
	}
}
void fibonacci(int n,int c,int p,int cu)
{
	if(c>=n)
		exit(0);
	int ne=p+cu;
	printf("%d ",ne);
	c++;
	fibonacci(n,c,cu,ne);
}

