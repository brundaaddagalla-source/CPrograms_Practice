#include<stdio.h>
void main()
{
	int i,n,k,f=0;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter key to be searched: ");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(a[i]==k){
			printf("Key found at %d",i);
			f=1;
			break;
		}
	}
	if(f==0){
		printf("Key not found");
	}
}
