#include <stdio.h>
#include <stdlib.h>
// Structure for AVL Tree Node
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
// Get height of a node
int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}
// Get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Create a new node
struct node *createNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1; // leaf node
    return node;
}
// Right rotation (LL Rotation)
struct node *rotateRight(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    // Return new root
    return x;
}
// Left rotation (RR Rotation)
struct node *rotateLeft(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    // Return new root
    return y;
}
// Get balance factor
int getBalance(struct node *n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}
// Insert a node into AVL Tree
struct node *insert(struct node *node, int key) {
    if (node == NULL)
        return createNode(key);
    // Normal BST insertion
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // duplicate not allowed
    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // Get balance factor
    int balance = getBalance(node);
    // Balance tree with rotations
    // LL Case
    if (balance > 1 && key < node->left->data){
    	
        printf("Performing LL Rotation\n");
        return rotateRight(node);
	}
    // RR Case
    if (balance < -1 && key > node->right->data){
    	printf("Performing RR Rotation\n");
		return rotateLeft(node);	
	}
    // LR Case
    if (balance > 1 && key > node->left->data) {
        printf("Performing LR Rotation\n");
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RL Case
    if (balance < -1 && key < node->right->data) {
        printf("Performing RL Rotation\n");
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}
// Traversals
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// ---------------------- MAIN FUNCTION ----------------------
int main() {
    struct node *root = NULL;
    int n, val, i, choice;
    printf("Enter number of nodes to create the BST: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("\nBST created successfully!\n");

    printf("\n=== AVL TREE MENU ===\n");
    printf("1. Insert Node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

