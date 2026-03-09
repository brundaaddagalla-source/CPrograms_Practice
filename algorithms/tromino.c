#include <stdio.h>
#define MAX 20
int board[MAX][MAX];
int tile = 1;
// function to check power of 2
int isPowerOfTwo(int n)
{
    return (n > 1) && ((n & (n - 1)) == 0);
}
void tromino(int n, int top, int left, int frow, int fcol)
{
    int i, j;
    if (n == 2)
    {
        for (i = top; i < top + 2; i++)
        {
            for (j = left; j < left + 2; j++)
            {
                if (i != frow || j != fcol)
                {
                    board[i][j] = tile;
                }
            }
        }
        tile++;
        return;
    }
    int t = tile++;
    int mid = n / 2;
    int centerRow = top + mid;
    int centerCol = left + mid;
    // Top Left
    if (frow < centerRow && fcol < centerCol)
        tromino(mid, top, left, frow, fcol);
    else
    {
        board[centerRow-1][centerCol-1] = t;
        tromino(mid, top, left, centerRow-1, centerCol-1);
    }
    // Top Right
    if (frow < centerRow && fcol >= centerCol)
        tromino(mid, top, left+mid, frow, fcol);
    else
    {
        board[centerRow-1][centerCol] = t;
        tromino(mid, top, left+mid, centerRow-1, centerCol);
    }
    // Bottom Left
    if (frow >= centerRow && fcol < centerCol)
        tromino(mid, top+mid, left, frow, fcol);
    else
    {
        board[centerRow][centerCol-1] = t;
        tromino(mid, top+mid, left, centerRow, centerCol-1);
    }
    // Bottom Right
    if (frow >= centerRow && fcol >= centerCol)
        tromino(mid, top+mid, left+mid, frow, fcol);
    else
    {
        board[centerRow][centerCol] = t;
        tromino(mid, top+mid, left+mid, centerRow, centerCol);
    }
}
void printBoard(int n)
{
    int i, j;
    printf("\nFinal Board:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d ", board[i][j]);
        printf("\n");
    }
}
int main()
{
    int i, j, n;
    int frow, fcol;
    printf("Enter board size: ");
    scanf("%d", &n);
    if (!isPowerOfTwo(n))
    {
        printf("Error: Board size must be power of 2 (2,4,8,16)\n");
        return 0;
    }
    printf("Enter forbidden square indices: ");
    scanf("%d %d", &frow, &fcol);
    if (frow < 0 || frow >= n || fcol < 0 || fcol >= n)
    {
        printf("Error: Forbidden square out of range\n");
        return 0;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = 0;
    board[frow][fcol] = -1;
    tromino(n, 0, 0, frow, fcol);
    printBoard(n);
    return 0;
}
