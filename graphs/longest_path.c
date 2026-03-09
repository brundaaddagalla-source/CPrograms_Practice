#include <stdio.h>
#define MAX 100

int r,c;
int a[MAX][MAX];
int dp[MAX][MAX]; 
int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x, int y) 
{
    if(dp[x][y]!=-1) 
		return dp[x][y];
    int d,mL=1;
    for(d=0;d<4;d++) 
	{
        int nX=x+directions[d][0];
        int nY=y+directions[d][1];

        if(nX>=0&&nX<r&&nY>=0&&nY<c&&a[nX][nY]>a[x][y]) 
		{
            if(mL<1+dfs(nX,nY))
            	mL=1+dfs(nX,nY);
        }
    }
    dp[x][y]=mL;
    return mL;
}
void main() 
{
    int i,j;
    printf("Enter no. of rows and columns: ");
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    		scanf("%d",&a[i][j]);
	}
    for(i=0;i<r;i++) 
	{
        for(j=0;j<c;j++) 
		{
            dp[i][j]=-1;
        }
    }
    int maxPath=0;
    for(i=0;i<r;i++) 
	{
        for(j=0;j<c;j++) 
		{
            if(maxPath<dfs(i,j))
            	maxPath=dfs(i,j);
        }
    }
    printf("\nThe length of the longest increasing path is: %d\n", maxPath);
}

