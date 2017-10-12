#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
} Node;

typedef struct LinkedList {
	Node * head;	
} LinkedList;

void print_list(LinkedList * list){
	Node * current = list->head;
	while(current != NULL){
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void insert_node(LinkedList * list, Node * node, Node * source){
	Node * current = list->head;
	while(current != NULL){
		if(current == source){
			Node * temp = current->next;
			current->next = node;
			current->next->next = temp;
		}
		current = current->next;
	}
}

void delete_node(LinkedList * list, Node * node){
	Node * current = list->head;
	while(current != NULL){
		if(current->next == node){
			Node * node = current->next;
			current->next = current->next->next;
			free(node);
		}
		current = current->next;
	}
}

void push(LinkedList * linked_list, int val){
	Node * current = linked_list->head;
	while(current->next != NULL){
		current = current->next;
	}

	current->next = malloc(sizeof(Node));
	current->next->value = val;
	current->next->next = NULL;
}

Node * init_node(int val){
	Node * node = malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	return node;
}

LinkedList * init_linked_list(int val){
	LinkedList * linked_list = malloc(sizeof(LinkedList));
	linked_list->head = init_node(val);
	return linked_list;
}

int main(){

	LinkedList * linked_list = init_linked_list(1);

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

	free(linked_list);
	return 0;
}
