#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
// Function to create linked list
struct node* create(struct node *start) {
    struct node *newnode, *ptr;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (start == NULL)
            start = newnode;
        else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
        }
    }
    return start;
}
// Display function
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
 		printf("%d ", ptr -> data);
 		ptr = ptr -> next;
	}
	return start;
}
//Insert at begining
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;
	return start;
}
//Insert at ending
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;
	return start;
}
//Insert before a given node
struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value before which the data has to be inserted : ");
	scanf("%d", &val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> data != val)
	{	
		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;
	return start;
}
//Insert after a given node
struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted : ");
	scanf("%d", &val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(preptr -> data != val)
	{	
		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;
	return start;
}
//Deletion at begining
struct node *delete_beg(struct node *start) 
{ 
	struct node *ptr; 
	ptr = start; 
	start = start -> next; 
	free(ptr); 
	return start; 
}
//Deletion at end	
struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != NULL)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = NULL;
	free(ptr);
	return start;
}
//Delete a given node
struct node *delete_node(struct node *start) 
{ 
	struct node *ptr, *preptr; 
	int val; 
	printf("\n Enter the value of the node which has to be deleted : "); 
	scanf("%d", &val); 
	ptr = start; 
	if(ptr -> data == val) 
	{ 
		start = delete_beg(start); 
		return start; 
	} 
	else 
	{
		while(ptr -> data != val)
 		{	
 			preptr = ptr;
 			ptr = ptr -> next;
 		}
 	preptr -> next = ptr -> next;
 	free(ptr);
 	return start;
	}
}
//Delete after a given node
struct node *delete_after(struct node *start) 
{ 
	struct node *ptr, *preptr; 
	int val; 
	printf("\n Enter the value after which the node has to deleted : "); 
	scanf("%d", &val); 
	ptr = start; 
	preptr = ptr; 
	while(preptr -> data != val) 
	{ 
		preptr = ptr; 
		ptr = ptr -> next; 
	} 
	preptr -> next=ptr -> next; 
	free(ptr); 
	return start; 
}
//Sorting in a linked list
struct node *sort_list(struct node *start) 
{ 
	struct node *ptr1, *ptr2; 
	int temp; 
	ptr1 = start; 
	while(ptr1 -> next != NULL) 
	{ 
		ptr2 = ptr1 -> next; 
		while(ptr2 != NULL) 
		{ 
			if(ptr1 -> data > ptr2 -> data) 
			{ 
				temp = ptr1 -> data; 
				ptr1 -> data = ptr2 -> data; 
				ptr2 -> data = temp; 
			} 
			ptr2 = ptr2 -> next; 
		} 
		ptr1 = ptr1 -> next;
	}
	return start;
}
// Main
int main() {
    struct node *start = NULL;
    int choice;
	printf("\n--- LINKED LIST OPERATIONS ---\n");
    printf("1. Create List\n");
    printf("2. Display\n");
    printf("3. Insert at Beginning\n");
    printf("4. Insert at End\n");
    printf("5. Insert After a Given Node\n");
    printf("6. Insert Before a Given Node\n");
    printf("7. Delete at Beginning\n");
    printf("8. Delete at End\n");
    printf("9. Delete After a Given Node\n");
    printf("10. Delete a Given Node\n");
    printf("11. Sort\n");
    printf("12. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: start = create(start); break;
        case 2: display(start); break;
        case 3: start = insert_beg(start); break;
        case 4: start = insert_end(start); break;
        case 5: start = insert_after(start); break;
        case 6: start = insert_before(start); break;
        case 7: start = delete_beg(start); break;
        case 8: start = delete_end(start); break;
        case 9: start = delete_after(start); break;
        case 10: start = delete_node(start); break;
        case 11: start = sort_list(start); break;
        case 12: exit(0);
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
