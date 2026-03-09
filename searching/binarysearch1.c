#include <stdio.h>
void binary_search(int a[], int n, int key) {
    int l=0,h=n-1,f=0;
    printf("Key Entered: %d\n",key);
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
	int n,i;
    printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    binary_search(a,n,key);
    return 0;
}
