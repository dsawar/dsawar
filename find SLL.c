#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

// Function to print the linked list
void linkedListTraversal(struct Node* ptr) {
	while (ptr != NULL) {
		printf("Element: %d\n", ptr->data);
		ptr = ptr->next;
	}
}


int main() {
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	struct Node *fifth;

	// Allocate memory for nodes in the linked list
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	fifth = (struct Node *)malloc(sizeof(struct Node));

	// Link first and second nodes
	head->data = 7;
	head->next = second;

	// Link second and third nodes
	second->data = 11;
	second->next = third;

	// Link third and fourth nodes
	third->data = 41;
	third->next = fourth;

	// Link fourth and fifth nodes
	fourth->data = 66;
	fourth->next = fifth;

	// Terminate the list at the fifth node
	fifth->data = 22;
	fifth->next = NULL;

	// Print the original list
	printf("Original List:\n");
	linkedListTraversal(head);

	// Search for an element
	int key;
	printf("search for an element\n");
	scanf("%d",&key);
	int position = 1;  // Start position from 1
	struct Node* current = head;
	// Traverse the list and search for the key
	while (current != NULL) {
		if (current->data == key) {
			printf("Element %d found at position %d\n", key, position);
			return;  // Element found, exit the function
		}
		current = current->next;
		position++;
	}

	// If the element is not found
	printf("Element %d not present in the list\n", key);


	return 0;
}
