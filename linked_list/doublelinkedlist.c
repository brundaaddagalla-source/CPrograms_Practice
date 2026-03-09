#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
        }

        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("\nList is empty!");
        return start;
    }
    printf("\nList elements are:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;

    if (start != NULL)
        start->prev = new_node;

    start = new_node;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if (start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
    }
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;

    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("Enter the value before which to insert: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("\nValue not found!");
        free(new_node);
        return start;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;

    if (ptr->prev != NULL)
        ptr->prev->next = new_node;
    else
        start = new_node;

    ptr->prev = new_node;
    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;

    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("Enter the value after which to insert: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("\nValue not found!");
        return start;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    new_node->prev = ptr;
    new_node->next = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = new_node;

    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }
    ptr = start;
    start = start->next;
    if (start != NULL)
        start->prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty!");
        return start;
    }
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    if (ptr->prev != NULL)
        ptr->prev->next = NULL;
    else
        start = NULL;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;

    printf("\nEnter the value after which to delete: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL || ptr->next == NULL) {
        printf("\nNo node exists after given value!");
        return start;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = ptr;

    free(temp);
    return start;
}

struct node *delete_before(struct node *start) {
    struct node *ptr, *temp;
    int val;

    printf("\nEnter the value before which to delete: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL || ptr->prev == NULL) {
        printf("\nNo node exists before given value!");
        return start;
    }

    temp = ptr->prev;
    if (temp->prev != NULL)
        temp->prev->next = ptr;
    else
        start = ptr;
    ptr->prev = temp->prev;
    free(temp);
    return start;
}

struct node *delete_list(struct node *start) {
    while (start != NULL)
        start = delete_beg(start);
    printf("\nEntire list deleted!");
    return start;
}

int main() {
    struct node *start = NULL;
    int option;

    printf("\n***** MAIN MENU *****");
    printf("\n1: Create a list");
    printf("\n2: Display the list");
    printf("\n3: Add a node at the beginning");
    printf("\n4: Add a node at the end");
    printf("\n5: Add a node before a given node");
    printf("\n6: Add a node after a given node");
    printf("\n7: Delete a node from the beginning");
    printf("\n8: Delete a node from the end");
    printf("\n9: Delete a node before a given node");
    printf("\n10: Delete a node after a given node");
    printf("\n11: Delete the entire list");
    printf("\n12: EXIT");

    do {
        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: start = create_ll(start); break;
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
            case 12: printf("\nExiting..."); break;
            default: printf("\nInvalid option!");
        }
    } while (option != 12);

    return 0;
}

