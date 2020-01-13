//============================================================================
// Name        : LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Linked List, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

// add a node at the end of the linked list
void append(Node *node, int data) {

	Node *last = new Node();
	last->data = data;
	last->next = NULL;

	while (node->next != NULL)
		node = node->next;

	node->next = last;
}

// insert a node after a given node
void insertAfter(Node *node, Node *ref, int data) {
	cout << "inserting after data=" << ref->data << endl;

	while((node != ref) && (node->next != NULL)) {
		node = node->next;
	}
	cout << "data: " << node->data << endl;

	Node *temp = new Node();
	temp->data = data;
	temp->next = node->next;
	node->next = temp;
}

// iterate through list
void printList(Node *node) {
	cout << "--- printList ---" << endl;

	while (node != NULL) {
		cout << "data: " << node->data << endl;
		node = node->next;
	}
}

// insert a node at the front of the linked list
void push(Node **head, int data) {
	Node *temp = new Node();
	temp->next = *head;
	temp->data = data;
	*head = temp;
}

//==============================================
int main() {
	cout << "Hello linked list" << endl;

	Node *head = NULL;

	printList(head);

	push(&head,3);
	push(&head,1);
	printList(head);

	append(head,22);
	push(&head,99);
	printList(head);

	insertAfter(head,(head->next)->next,51);
	insertAfter(head,head,15);
	printList(head);

	return 0;
}
//==============================================
