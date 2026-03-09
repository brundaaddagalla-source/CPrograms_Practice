#include<stdio.h>
void main()
{
	int m,n,i,j;
	printf("Enter number of rows and columns: ");
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	int max,min;
	max=min=a[0][0];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>max)
				max=a[i][j];
			if(a[i][j]<min)
				min=a[i][j];
		}
	}
	printf("Maximum: %d\nMinimum: %d",max,min);
}
