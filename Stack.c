#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void push(Node** head, int data);
void pop(Node** head);
void printNodes(Node* head);
int top(Node* head);
int isEmpty(Node* head);

void push(Node** head, int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	
	if(new_node == NULL) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void pop(Node** head) {
	if(isEmpty(*head)) {
		printf("Unable to pop() as the stack is empty.\n");
		return;
	}
	
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void printNodes(Node* head) {
	
	if(head == NULL) {
		printf("Unable to printNodes() as the stack is empty.\n");
		return;
	}
	
	Node* temp = head;
	
	while(temp != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
		
		if (temp != NULL) {
			printf(", ");
		}
	}
	
	printf("\n");
}

int isEmpty(Node* head) {
	return (head == NULL);
}

int top(Node* head){
	if (isEmpty(head)){
		printf("Unable to use top() as the stack is empty.\n");
		return -1;
	} else {
		return head->data;
	}
}

int main(){
	Node* head = NULL;
	printf("%d\n", top(head));
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	printNodes(head);
	pop(&head);
	printf("%d\n", top(head));
	printNodes(head);
	pop(&head);
	pop(&head);
	pop(&head);
	pop(&head);
	printNodes(head);
	return 0;
}
