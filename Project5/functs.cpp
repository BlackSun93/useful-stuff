#include "Header.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include "functs.h"

Test::Test () {}

int Test::get_num() {
	return num;
}
void Test::set_num(int new_num) {
	num = new_num;
}
std::string Test::get_name() {
	return name;
}
void Test::set_name(std::string new_name) {
	name = new_name;
}

void node::addnode(Test new_test, node* *head_ref) {
	node* new_node = new node;
	node* last = *head_ref;
	new_node->data = new_test;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	//or else
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}

void node::remove(Test toremove, node* *head) {
	if (*head == NULL) {
		std::cout << "the list is empty, cannot delete an item from an empty list\n";
		return;
	}

	if (toremove.get_num() == (*head)->data.get_num()) { //had to use (*head) to reference the pointer to the head of the list instead of the head of the list itself.
		temp = *head;
		*head = (*head)->next;
		delete temp;
		std::cout << "Test object deleted at start of the list!\n";
		return;
	}
	temp = (*head)->next;
	while (toremove.get_num() != temp->data.get_num()) {
		prev = temp;
		temp = temp->next;
		if (temp == NULL) {
			std::cout << "the object you wanted to delete wasnt found\n";
			return;
		}
	}
	node *target = temp;

	if (toremove.get_num() == temp->data.get_num()) {
		prev->next = target->next;
		
		//std::cout << "deleting" << &target;
		delete target;
		std::cout << "object deleted!\n";
	}
}
 
