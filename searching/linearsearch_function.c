#include<stdio.h>
int linearsearch(int n, int a[],int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
			return i;
	}
	return -1;
}
int main()
{
	int linearsearch(int n, int a[],int k);
	int n,i,k,x;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter key to be searched: ");
	scanf("%d",&k);
	x=linearsearch(n,a,k);
	if(x==-1)
		printf("Key not found");
	else
		printf("Key found at %d",x);
	return 0;
}
