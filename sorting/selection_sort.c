#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selection_sort(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		int imin=i;
		int j;
		for(j=i+1;j<n;j++){
			if(a[j]<a[imin]) imin=j;
		}
		if(imin!=i) swap(&a[i],&a[imin]);
	}
}
int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
    selection_sort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
