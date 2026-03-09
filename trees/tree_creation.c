#include<stdio.h>
#include<malloc.h>
struct node{
	int *left;
	int data;
	int *right;
};
struct node *root=NULL;
struct node *create_node(int value){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
struct node *insert(){
	int n;
	printf("\nEnter value or -1 to exit:");
	scanf("%d",&n);
	if(n==-1){
		printf("Creation Completed");
		return root;
	}
	struct node *root=create_node(n);
	printf("Enter left child of %d:",n);
	root->left=insert();
	printf("\nEnter right child of %d:",n);
	root->right=insert();
	return root;
}
int main(){
	printf("Creation of tree:\n");
	insert();
	printf("\n\nCreation of tree completed");
	return 0;
}

