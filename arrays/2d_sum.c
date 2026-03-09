#include<stdio.h>
void main()
{
	int i,j,m,n,s=0;
	printf("Enter number of rows and columns: ");
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	int max;
	for(i=0;i<m;i++)
	{
		max=a[i][0];
		for(j=1;j<n;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				s+=max;
			}
		}
	}
	printf("%d",s);
}
