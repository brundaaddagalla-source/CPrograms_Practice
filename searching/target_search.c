#include<stdio.h>
void main()
{
	int m,n,i,j,t,f=0;
	printf("Enter no. of rows and coloumns: ");
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("\nEnter target: ");
	scanf("%d",&t);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==t)
			{
				f=1;
				break;
			}
		}
	}
	if(f==1)
		printf("\nTrue");
	else
		printf("\nFalse");
}
