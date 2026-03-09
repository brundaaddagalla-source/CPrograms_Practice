#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start){
	int n;
	printf("Enter value or -1 to stop: ");
	scanf("%d",&n);
	while(n!=-1){
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=n;
		if(start==NULL){
			new_node->next=NULL;
			start=new_node;
		}else{
			struct node *ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;	
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("Element inserted.\n");
		printf("Enter value or -1 to stop: ");
		scanf("%d",&n);
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr=start;
	printf("The elements in the linked list are: ");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
}
int linear_search(struct node *start, int num){
	struct node *ptr=start;
	int index=0;
	printf("Data to be searched is %d.\n",num);
	while(ptr!=NULL){
		if(ptr->data==num){
			return index;
		}
		ptr=ptr->next;
		index++;
	}
	return -1;
}
int main(){
	printf("Creation of a linked list:\n");
	struct node *start=NULL;
	start=create(start);
	printf("Linked List Creation Completed.\n");
	printf("\nDisplay the linked list:\n");
	start=display(start);
	printf("\nLinear Search in Linked List:");
	printf("\nEnter element to be searched: ");
	int n,x;
	scanf("%d",&n);
	x=linear_search(start,n);
	if(x==-1) printf("Element not found.");
	else printf("Element found at index %d",x);
	return 0;
}
