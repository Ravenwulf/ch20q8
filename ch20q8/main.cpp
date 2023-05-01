#include "EmployeeInfo.h"
#include "EmployeeTree.h"
#include <iostream>

int main() {

	EmployeeTree tree;
	tree.insert(*(new EmployeeInfo(5, "jon")));
	tree.insert(*(new EmployeeInfo(7, "jack")));
	tree.insert(*(new EmployeeInfo(3, "mark")));
	tree.insert(*(new EmployeeInfo(6, "kate")));
	tree.insert(*(new EmployeeInfo(4, "austin")));
	tree.insert(*(new EmployeeInfo(10, "jim")));
	tree.insert(*(new EmployeeInfo(8, "bill")));
	tree.insert(*(new EmployeeInfo(1, "susan")));
	tree.insert(*(new EmployeeInfo(11, "ben")));
	tree.insert(*(new EmployeeInfo(14, "mack")));
	tree.showInColor();

	bool searching = true;
	int id;
	char yesno;
	while (searching) {
		std::cout << "\nEnter an employee id to lookup: ";
		std::cin >> id;
		std::cin.ignore();
		std::cout << "Searching for employee #" << id << " ...\n";
		try {
			tree.search(id);
		} catch (EmployeeNotFound e) {
			std::cout << "ERROR: Employee Not Found";
		}
		
		std::cout << "\nSearch for another employee? (y/n) ";
		std::cin >> yesno;
		yesno == 'y' ? searching = true : searching = false;
	}

	return 0;
}