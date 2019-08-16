#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <string>

//void addnode(Test new_test, node* *head_ref);
//node printList(node *head);

int main() {
	std::string input;
	int input2;
	int choice = 0;
	Test *Newtest = new Test;
	node* head = NULL;
	node thelist;

	//std::cout <<  Newtest->get_name() << "     " << Newtest->get_num();

	while (choice != 40) {
		std::cout << "please make a choice! 1 to add to list, 2 to delete from the list, 7 to print list, 8 to delete the list and 40 to quit\n";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "enter a name\n";
			std::cin >> input;
			Newtest->set_name(input);
			std::cout << "enter a number\n";
			std::cin >> input2;
			Newtest->set_num(input2);
			std::cout << "Is this test object neutered? true (1) or false (0)\n";
			std::cin >> input3;
			Newtest->set_neutered(input3);
			thelist.addnode(*Newtest, &head);
		}

		if (choice == 2) {
			Test *deletechoice = new Test;
			std::cout << "please enter the number you want to delete \n";
			std::cin >> input2;
			deletechoice->set_num(input2);

			thelist.remove(*deletechoice, &head);
		}

		if (choice == 7) {
			thelist.printList(head);
		}
		if (choice == 8) {
			thelist.deletelist(&head);
		}
	}
}
