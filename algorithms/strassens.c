#include <stdio.h>

int i,j;

int isPowerOfTwo(int n)
{
    if(n<=1) return 0;
    return (n&(n-1))==0;
}

void add(int n,int A[n][n],int B[n][n],int C[n][n],int size)
{
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int n,int A[n][n],int B[n][n],int C[n][n],int size)
{
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int n,int A[n][n],int B[n][n],int C[n][n],int size)
{
    if(size==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int newSize=size/2;

    int A11[n][n],A12[n][n],A21[n][n],A22[n][n];
    int B11[n][n],B12[n][n],B21[n][n],B22[n][n];
    int C11[n][n],C12[n][n],C21[n][n],C22[n][n];
    int P[n][n],Q[n][n],R[n][n],S[n][n];
    int T[n][n],U[n][n],V[n][n];
    int temp1[n][n],temp2[n][n];

    for(i=0;i<newSize;i++)
        for(j=0;j<newSize;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+newSize];
            A21[i][j]=A[i+newSize][j];
            A22[i][j]=A[i+newSize][j+newSize];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+newSize];
            B21[i][j]=B[i+newSize][j];
            B22[i][j]=B[i+newSize][j+newSize];
        }

    add(n,A11,A22,temp1,newSize);
    add(n,B11,B22,temp2,newSize);
    strassen(n,temp1,temp2,P,newSize);

    add(n,A21,A22,temp1,newSize);
    strassen(n,temp1,B11,Q,newSize);

    sub(n,B12,B22,temp2,newSize);
    strassen(n,A11,temp2,R,newSize);

    sub(n,B21,B11,temp2,newSize);
    strassen(n,A22,temp2,S,newSize);

    add(n,A11,A12,temp1,newSize);
    strassen(n,temp1,B22,T,newSize);

    sub(n,A21,A11,temp1,newSize);
    add(n,B11,B12,temp2,newSize);
    strassen(n,temp1,temp2,U,newSize);

    sub(n,A12,A22,temp1,newSize);
    add(n,B21,B22,temp2,newSize);
    strassen(n,temp1,temp2,V,newSize);

    add(n,P,S,temp1,newSize);
    sub(n,temp1,T,temp2,newSize);
    add(n,temp2,V,C11,newSize);

    add(n,R,T,C12,newSize);
    add(n,Q,S,C21,newSize);

    add(n,P,R,temp1,newSize);
    sub(n,temp1,Q,temp2,newSize);
    add(n,temp2,U,C22,newSize);

    for(i=0;i<newSize;i++)
        for(j=0;j<newSize;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+newSize]=C12[i][j];
            C[i+newSize][j]=C21[i][j];
            C[i+newSize][j+newSize]=C22[i][j];
        }
}

int main()
{
    int n;

    printf("Enter size n: ");
    scanf("%d",&n);

    if(!isPowerOfTwo(n))
    {
        printf("Invalid size! Enter power of 2.\n");
        return 0;
    }

    int A[n][n],B[n][n],C[n][n];

    printf("Enter Matrix A:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    strassen(n,A,B,C,n);

    printf("\nResult Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%5d",C[i][j]);
        printf("\n");
    }

    return 0;
}

