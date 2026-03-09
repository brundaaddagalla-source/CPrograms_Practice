#include<stdio.h>
int s=0;
void main()
{
	int n,r;
	printf("Enter number: ");
	scanf("%d",&n);
	r=sum_digits(n);
	printf("The sum of digits of %d is %d",n,r);
}
int sum_digits(int x)
{
	if(x<=0)	
		return s;
	s+=(x%10);
	sum_digis(x/10);
}
