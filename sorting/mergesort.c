#include <stdio.h>

void combine(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}
void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}
int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
    mergesort(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

