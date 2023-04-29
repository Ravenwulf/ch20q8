#include "EmployeeInfo.h"
#include "EmployeeTree.h"

int main() {

	EmployeeTree tree;
	tree.insert(*(new EmployeeInfo()));

	return 0;
}