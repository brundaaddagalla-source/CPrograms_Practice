#include<stdio.h>
void main()
{
	int m,n,i,j,s;
	printf("Enter number of rows and columns: ");
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(s=0;s<n;s++)
	{
		i=0;
		j=s;
		while(i<m&&j>=0)
		{
			printf("%d ",a[i][j]);
			i++;
			j--;
		}
		printf("\n");
	}
	for(s=1;s<m;s++)
	{
		i=s;
		j=n-1;
		while(i<m&&j>=0)
		{
			printf("%d ",a[i][j]);
			i++;
			j--;
		}
		printf("\n");
	}
}
