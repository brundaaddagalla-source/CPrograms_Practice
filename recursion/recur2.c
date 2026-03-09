#include<stdio.h>
#include<stdlib.h>
void main()
{
	void factorial(int n,int f,int c);
	int n,f=1,c=1;
	printf("Enter number: ");
	scanf("%d",&n);
	factorial(n,f,c);
}
void factorial(int n, int f,int c)
{
	if(c>n)
	{
		printf("Factorial of %d is %d",n,f);
		exit(0);
	}
	f=f*c;
	c++;
	factorial(n,f,c);
}
