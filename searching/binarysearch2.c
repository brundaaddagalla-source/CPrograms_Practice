#include <stdio.h>

void bubble_sort(int a[], int n){
	int f,i,j,c=0;
	for(i=0;i<n;i++){
		f=0;
		c++;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				f=1;
			}
		}
		if(f==0){
			printf("\nArray sorted after %d passes.\n",c);
			printf("Sorted array: ");
			for(j=0;j<n;j++) printf("%d ",a[j]);
			printf("\n");
			return;	
		}
	}
}
void binary_search(int a[], int n, int key) {
    int l=0,h=n-1,f=0;
    printf("\nKey Entered: %d\n",key);
    while (l<=h) {
        int m=(l+h)/2;
        printf("Middle value being compared: %d\n",a[m]);
        if(a[m]==key){
            printf("Key found at index %d\n", m);
            f=1;
            break;
        }else if (a[m]<key){
            l=m+1;
        }else{
            h=m-1;
        }
    }
    if(f==0) printf("Key not found\n");
}
int main(){
    int n,key,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    bubble_sort(a,n);
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    binary_search(a,n,key);
    return 0;
}
