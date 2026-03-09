#include<stdio.h>
#include<stdlib.h>
void main()
{
	void digits(int n,int c);
	int n,c=0;
	printf("Enter number: ");
	scanf("%d",&n);
	digits(n,c);
}
void digits(int n,int c)
{
	if(n<=0)
	{
		printf("The number of digits in the given number is: %d",c);
		exit(0);
	}
	c++;
	n/=10;
	digits(n,c);
}
