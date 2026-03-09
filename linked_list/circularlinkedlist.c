#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create the circular linked list
struct node *create_list(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL) {
            start = new_node;
            new_node->next = start;
        } else {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
        }

        printf("Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

// Display the circular linked list
struct node *display(struct node *start) {
    struct node *ptr = start;

    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }

    printf("\nCircular Linked List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    printf("\n");
    return start;
}

// Insert at beginning
struct node *insert_beg(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter data to insert at beginning: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        new_node->next = new_node;
        start = new_node;
        return start;
    }

    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;

    ptr->next = new_node;
    new_node->next = start;
    start = new_node;

    return start;
}

// Insert at end
struct node *insert_end(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter data to insert at end: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        new_node->next = new_node;
        start = new_node;
        return start;
    }

    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;

    ptr->next = new_node;
    new_node->next = start;

    return start;
}

// Insert before a given node
struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, val;

    printf("\nEnter data to insert: ");
    scanf("%d", &num);
    printf("Enter the value before which to insert: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }

    if (start->data == val) {
        return insert_beg(start);
    }

    ptr = start;
    while (ptr->next != start && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr->data != val) {
        printf("\nValue not found!");
        free(new_node);
        return start;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}

// Insert after a given node
struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;

    printf("\nEnter data to insert: ");
    scanf("%d", &num);
    printf("Enter the value after which to insert: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    while (ptr->data != val && ptr->next != start)
        ptr = ptr->next;

    if (ptr->data != val) {
        printf("\nValue not found!");
        free(new_node);
        return start;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    return start;
}

// Delete from beginning
struct node *delete_beg(struct node *start) {
    struct node *ptr = start;

    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }

    if (start->next == start) {
        free(start);
        start = NULL;
        return start;
    }

    while (ptr->next != start)
        ptr = ptr->next;

    struct node *temp = start;
    ptr->next = start->next;
    start = start->next;
    free(temp);

    return start;
}

// Delete from end
struct node *delete_end(struct node *start) {
    struct node *ptr = start, *preptr;

    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }

    if (start->next == start) {
        free(start);
        start = NULL;
        return start;
    }

    while (ptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = start;
    free(ptr);

    return start;
}

// Delete before a given node
struct node *delete_before(struct node *start) {
    struct node *ptr, *preptr, *temp;
    int val;

    printf("\nEnter the value before which node is to be deleted: ");
    scanf("%d", &val);

    if (start == NULL || start->next == start) {
        printf("\nList is too short!");
        return start;
    }

    // If the node before the first one has to be deleted (not possible)
    if (start->data == val) {
        printf("\nNo node exists before the first node!");
        return start;
    }

    ptr = start;
    preptr = NULL;

    while (ptr->next != start && ptr->next->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr->next->data != val) {
        printf("\nValue not found!");
        return start;
    }

    // ptr is the node before the node with val
    if (ptr == start) {
        start = delete_beg(start);
        return start;
    } else {
        temp = preptr->next;
        preptr->next = ptr->next;
        free(ptr);
    }

    return start;
}

// Delete after a given node
struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;

    printf("\nEnter the value after which node is to be deleted: ");
    scanf("%d", &val);

    if (start == NULL || start->next == start) {
        printf("\nList is too short!");
        return start;
    }

    ptr = start;
    while (ptr->data != val && ptr->next != start)
        ptr = ptr->next;

    if (ptr->data != val) {
        printf("\nValue not found!");
        return start;
    }

    temp = ptr->next;
    if (temp == start)
        start = delete_beg(start);
    else
        ptr->next = temp->next;

    free(temp);
    return start;
}

// Delete entire list
struct node *delete_list(struct node *start) {
    struct node *ptr = start, *temp;

    if (start == NULL)
        return NULL;

    while (ptr->next != start) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    free(ptr);
    start = NULL;
    printf("\nCircular linked list deleted.\n");

    return start;
}

// Main menu
int main() {
    struct node *start = NULL;
    int option;

    printf("\n***** CIRCULAR LINKED LIST MENU *****");
    printf("\n1. Create List");
    printf("\n2. Display List");
    printf("\n3. Insert at Beginning");
    printf("\n4. Insert at End");
    printf("\n5. Insert Before a Given Node");
    printf("\n6. Insert After a Given Node");
    printf("\n7. Delete from Beginning");
    printf("\n8. Delete from End");
    printf("\n9. Delete Before a Given Node");
    printf("\n10. Delete After a Given Node");
    printf("\n11. Delete Entire List");
    printf("\n12. EXIT");

    do {
        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: start = create_list(start); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_before(start); break;
            case 6: start = insert_after(start); break;
            case 7: start = delete_beg(start); break;
            case 8: start = delete_end(start); break;
            case 9: start = delete_before(start); break;
            case 10: start = delete_after(start); break;
            case 11: start = delete_list(start); break;
            case 12: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid option! Try again.");
        }
    } while (option != 12);

    return 0;
}

