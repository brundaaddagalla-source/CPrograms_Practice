#include<stdio.h>
#include<stdlib.h>
void main()
{
	void percentage(float n, float c);
	float n,c=1.0;
	printf("Enter number: ");
	scanf("%f",&n);
	percentage(n,c);
}
void percentage(float n, float c)
{
	float p;
	if(c>100)	
		exit(0);
	p=(n*c)/100;
	printf("%.0f percentage: %.2f\n",c,p);
	c++;
	percentage(n,c);
}
