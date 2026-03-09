#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Enqueue operation (insert at end)
struct node *enqueue(struct node *start) {
    int n;
    printf("Enter data to insert: ");
    scanf("%d", &n);

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;

    if (start == NULL) {
        new_node->next = new_node;  // Point to itself
        start = new_node;
    } else {
        struct node *ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->next = start;
    }

    return start;
}

// Dequeue operation (delete from front)
struct node *dequeue(struct node *start) {
    if (start == NULL) {
        printf("\nQUEUE EMPTY!");
        return start;
    }

    struct node *ptr = start;

    // Only one element
    if (ptr->next == start) {
        printf("\nDeleted element: %d", ptr->data);
        free(ptr);
        start = NULL;
    } else {
        struct node *temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = start->next;
        printf("\nDeleted element: %d", start->data);
        start = start->next;
        free(ptr);
    }
    return start;
}

// Display operation
void display(struct node *start) {
    if (start == NULL) {
        printf("\nQUEUE EMPTY!");
        return;
    }
    struct node *ptr = start;
    printf("\nQueue elements are: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

// Main function
int main() {
    struct node *start = NULL;
    int option;

    printf("\n***** CIRCULAR QUEUE MENU *****");
    printf("\n1. ENQUEUE");
    printf("\n2. DEQUEUE");
    printf("\n3. DISPLAY");
    printf("\n4. EXIT");

    do {
        printf("\n\nEnter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                start = enqueue(start);
                break;
            case 2:
                start = dequeue(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid option!");
        }
    } while (option != 4);

    return 0;
}

