#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
// Create a new node
struct node *create_node(int val) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}
// Insert into BST
struct node *insert(struct node *root, int val) {
    if (root == NULL)
        return create_node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
// Find minimum value node (used in deletion)
struct node *find_min(struct node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
// Delete node from BST
struct node *delete_node(struct node *root, int val) {
    if (root == NULL) return root;
    if (val < root->data)
        root->left = delete_node(root->left, val);
    else if (val > root->data)
        root->right = delete_node(root->right, val);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
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
// Height of BST
int height(struct node *root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
// Total number of nodes
int num_nodes(struct node *root) {
    if (root == NULL) return 0;
    return num_nodes(root->left) + num_nodes(root->right) + 1;
}
// Number of Internal nodes
int internal_num_nodes(struct node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return internal_num_nodes(root->left) + internal_num_nodes(root->right) + 1;
}
// Number of External (leaf) nodes
int external_num_nodes(struct node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return external_num_nodes(root->left) + external_num_nodes(root->right);
}
// Search a node
int search(struct node *root, int key) {
    if (root == NULL)
        return 0;
    if (key == root->data)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
// Main function
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
    // Print menu once
    printf("\n===== BINARY SEARCH TREE MENU =====\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Search Node\n");
    printf("4. Preorder Traversal\n");
    printf("5. Inorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Height of BST\n");
    printf("8. Total Nodes\n");
    printf("9. Internal Nodes\n");
    printf("10. External (Leaf) Nodes\n");
    printf("11. Exit\n");
    printf("===================================\n");
    // Menu loop
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete_node(root, val);
                printf("Node deleted (if existed).\n");
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Value found in BST.\n");
                else
                    printf("Value not found in BST.\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Height of BST: %d\n", height(root));
                break;
            case 8:
                printf("Total nodes: %d\n", num_nodes(root));
                break;
            case 9:
                printf("Internal nodes: %d\n", internal_num_nodes(root));
                break;
            case 10:
                printf("External (leaf) nodes: %d\n", external_num_nodes(root));
                break;
            case 11:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
