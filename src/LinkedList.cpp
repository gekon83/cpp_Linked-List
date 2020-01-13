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

	Node *temp = new Node();
	temp->data = data;
	temp->next = node->next;
	node->next = temp;
}

// insert a node before a given node
void insertBefore(Node *node, Node *ref, int data) {
	cout << "inserting before data=" << ref->data << endl;

	while((node->next != ref) && (node->next != NULL)) {
		node = node->next;
	}

	Node *temp = new Node();
	temp->data = data;
	temp->next = node->next;
	node->next = temp;
}

// iterate through list and print
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

int countNodes(Node *node, int reset) {
	static int count = 0;
	if (!reset)
		count = 0;

	if (node != NULL) {
		count++;
		countNodes(node->next, 1);
	}
	return count;
}

int sumNodes(Node *node, int reset) {
	static float sum = 0.0;
	if (!reset)
		sum = 0.0;

	if (node != NULL) {
		sum += node->data;
		//cout << "sum: " << sum << endl;
		sumNodes(node->next, 1);
	}
	return sum;
}

// returns mean value of all nodes
int meanNodes(Node *node, int reset) {
	static int count = 0;
	static float sum = 0.0;
	if (!reset) {
		count = 0;
		sum = 0.0;
	}

	if (node != NULL) {
		count++;
		sum += node->data;
		meanNodes(node->next, 1);
	}

	if (count)	return sum/count;
	else		return 0;
}
//==============================================
int main() {
	cout << "Hello linked list" << endl;

	Node *head = NULL;

	printList(head);
	cout << "mean: " << meanNodes(head,0) << endl;

	push(&head,3);
	push(&head,1);
	printList(head);
	cout << "mean: " << meanNodes(head,0) << endl;

	append(head,22);
	push(&head,99);
	printList(head);
	cout << "mean: " << meanNodes(head,0) << endl;

	insertAfter(head,(head->next)->next,51);
	insertAfter(head,head,15);
	printList(head);
	cout << "mean: " << meanNodes(head,0) << endl;

	insertBefore(head,head->next,-2);
	printList(head);
	//cout << "count: " << countNodes(head,0) << endl;
	//cout << "sum: " << sumNodes(head,0) << endl;
	cout << "mean: " << meanNodes(head,0) << endl;

	return 0;
}
//==============================================
