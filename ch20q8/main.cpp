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
	//tree.showInColor();

	bool searching = true;
	int id;
	char yesno;
	while (searching) {
		std::cout << "\u001b[0m\nEnter an employee id to lookup: \u001b[33;1m";
		std::cin >> id;
		std::cin.ignore();
		std::cout << "\u001b[0mSearching for employee #\u001b[33;1m" << id << "\u001b[0m ...\n";
		try {
			tree.search(id);
		} catch (EmployeeNotFound e) {
			std::cout << "\u001b[31;1mERROR\u001b[0m: Employee Not Found";
		}
		
		std::cout << "\nSearch for another employee? (\u001b[32;1my\u001b[0m/\u001b[31;1mn\u001b[0m)\u001b[35;1m ";
		std::cin >> yesno;
		yesno == 'y' ? searching = true : searching = false;
	}

	return 0;
}