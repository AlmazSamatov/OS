#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
	struct Node * prev;
} Node;

typedef struct DoublyLinkedList {
	Node * head;	
} DoublyLinkedList;

void print_list(DoublyLinkedList * list){
	Node * current = list->head;
	while(current != NULL){
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void insert_node(DoublyLinkedList * list, Node * node, Node * source){
	Node * current = list->head;
	while(current != NULL){
		if(current == source){
			Node * temp = current->next;
			current->next = node;
			node->next = temp;
			temp->prev = node;
			node->prev = current;
		}
		current = current->next;
	}
}

void delete_node(DoublyLinkedList * list, Node * node){
	Node * current = list->head;
	while(current != NULL){
		if(current->next == node){
			Node * node = current->next;
			current->next = current->next->next;
			current->next->next->prev = current;
			free(node);
		}
		current = current->next;
	}
}

void push(DoublyLinkedList * linked_list, int val){
	Node * current = linked_list->head;
	while(current->next != NULL){
		current = current->next;
	}

	current->next = malloc(sizeof(Node));
	current->next->value = val;
	current->next->next = NULL;
	current->next->prev = current;
}

Node * init_node(int val){
	Node * node = malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

DoublyLinkedList * init_linked_list(int val){
	DoublyLinkedList * linked_list = malloc(sizeof(DoublyLinkedList));
	linked_list->head = init_node(val);
	return linked_list;
}

int main(){

	DoublyLinkedList * linked_list = init_linked_list(1);

	push(linked_list, 2);
	push(linked_list, 5);
	push(linked_list, 3);

	// try to delete node with value that equal to 2 and print result
	delete_node(linked_list, linked_list->head->next);
	print_list(linked_list);

	Node * node = init_node(6);

	//try to insert node with value that equal 6 and print result
	insert_node(linked_list, node, linked_list->head);
	print_list(linked_list);

	//check whether we can look up previous element
	printf("%d\n", linked_list->head->next->prev->value);

	free(linked_list);
	return 0;
}

