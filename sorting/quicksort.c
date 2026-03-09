#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int a[], int low, int high) {
    int p = a[low];
    int i = low + 1, j = high;
    while (i <= j) {
        while (i <= high && a[i] <= p) i++;
        while (a[j] > p) j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int m = partition(a, low, high);
        quicksort(a, low, m - 1);
        quicksort(a, m + 1, high);
    }
}
int main() {
	int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
    quicksort(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

