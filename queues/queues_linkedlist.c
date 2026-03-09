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
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        struct node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }

    printf("Inserted %d into the queue.\n", n);
    return start;
}

// Dequeue operation (delete from front)
struct node *dequeue(struct node *start) {
    if (start == NULL) {
        printf("\nQUEUE UNDERFLOW! Queue is empty.\n");
        return start;
    }

    struct node *ptr = start;
    start = start->next;
    printf("Deleted element: %d\n", ptr->data);
    free(ptr);

    return start;
}

// Display operation
void display(struct node *start) {
    if (start == NULL) {
        printf("\nQUEUE IS EMPTY!\n");
        return;
    }

    struct node *ptr = start;
    printf("\nQueue elements are: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    struct node *start = NULL;
    int option;

    printf("\n***** LINEAR QUEUE MENU *****");
    printf("\n1. ENQUEUE (Insert)");
    printf("\n2. DEQUEUE (Delete)");
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
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid option! Try again.\n");
        }
    } while (option != 4);

    return 0;
}

