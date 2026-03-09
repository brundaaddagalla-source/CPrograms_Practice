#include<stdio.h>
void main()
{
	int m,n,i,j;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	int t[n][m];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			t[j][i]=a[i][j];
	}
	printf("\nOutput Matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",t[i][j]);
		printf("\n");
	}
}
