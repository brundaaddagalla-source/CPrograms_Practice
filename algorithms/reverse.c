#include<stdio.h>
void main()
{
	int n,i,x,j,temp;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	for(x=0;x<n;x++)
		scanf("%d",&a[x]);
	i=0;
	j=n-1;
	printf("Array before reversing: ");
	for(x=0;x<n;x++)
		printf("%d ",a[x]);
	while(i<j){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
	printf("\nArray after reversing: ");
	for(x=0;x<n;x++)
		printf("%d ",a[x]);
}
