#include<stdio.h>
#include<malloc.h>
struct node{
	struct node *left;
	int data;
	struct node *right;
};

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
		return NULL;
	}
	struct node *root=create_node(n);
	printf("Enter left child of %d:",n);
	root->left=insert();
	printf("\nEnter right child of %d:",n);
	root->right=insert();
	return root;
}
void pre_order(struct node *root){
	if(root==NULL) return;
	printf("%d ",root->data);
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(struct node *root){
	if(root==NULL) return;
	post_order(root->left);
	post_order(root->right);
	printf("%d ",root->data);
}
void in_order(struct node *root){
	if(root==NULL) return;
	in_order(root->left);
	printf("%d ",root->data);
	in_order(root->right);
}
int main(){
	printf("Creation of tree:\n");
	struct node *root=insert();
	printf("\n\nCreation of tree completed");
	printf("\n\nPreorder Traversal: \n");
	pre_order(root);
	printf("\n\nPostorder Traversal: \n");
	post_order(root);
	printf("\n\nInorder Traversal: \n");
	in_order(root);
	return 0;
}

