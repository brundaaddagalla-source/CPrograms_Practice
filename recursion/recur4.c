#include<stdio.h>
#include<stdlib.h>
void main()
{
	void power(int n,int p,int c,int a);
	int n,p,a=1,c=0;
	printf("Enter number: ");
	scanf("%d",&n);
	printf("Enter power: ");
	scanf("%d",&p);
	power(n,p,c,a);
}
void power(int n,int p,int c,int a)
{
	if(c==p)	
	{
		printf("The answer is %d",a);
		exit(0);
	}
	a*=n;
	c++;
	power(n,p,c,a);
}
