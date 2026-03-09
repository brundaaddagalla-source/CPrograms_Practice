#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int a[], int n){
	int f,i,j;
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				f=1;
			}
		}
		if(!f) return;
	}
}
int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
    bubble_sort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
