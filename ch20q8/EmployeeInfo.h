#pragma once
#include <string>

class EmployeeInfo {
public:
	int id;
	std::string name;
	EmployeeInfo(int i, std::string n) {
		id = i;
		name = n;
	}
};