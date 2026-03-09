#include <stdio.h>
void insertion_sort(int a[], int n){
	int i;
	for(i=1;i<n;i++){
		int j=i-1;
		int temp=a[i];
		while((temp<a[j])&&(j>=0)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
    insertion_sort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
