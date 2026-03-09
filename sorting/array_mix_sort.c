#include<stdio.h>
void main()
{
	int n1,n2,i,j,k=0;
	printf("Enter number of elements for list 1: ");
	scanf("%d",&n1);
	int a1[n1];
	printf("Inputing List 1:");
	for(i=0;i<n1;i++)
		scanf("%d",&a1[i]);
	printf("Enter number of elements for list 2: ");
	scanf("%d",&n2);
	int a2[n2];
	printf("Inputing List 2:");
	for(i=0;i<n2;i++)
		scanf("%d",&a2[i]);
	int a[n1+n2];
	for(i=0;i<n1;i++)
	{
		a[k]=a1[i];
		k++;
	}
	for(i=0;i<n2;i++)
	{
		int s=0;
		for(j=0;j<k;j++)	
		{
			if(a2[i]==a[j])
			{
				s+=1;
				break;
			}
		}
		if(s==0)
		{
			a[k]=a2[i];
			k++;
		}
	}
	for (i=0;i<k-1;i++){
        for (j=i+1;j<k;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
	for(i=0;i<k;i++)
		printf("%d ",a[i]);	
}
