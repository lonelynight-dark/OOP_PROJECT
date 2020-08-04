#ifndef _MANAGER_H_
#define _MANGAGER_H_

#include "Employee.h"
#include "Staff.h"
#include <vector>

class Manager: public Staff
{
public:
	Manager() :Staff() { nEmp = 0; }
	~Manager() { for (int i = 0; i < nEmp; i++) delete List[i]; }
	void addStaff();
	void input();
	void output();
	void viewProd();
	void viewEmp();
private:
	std::vector<Employee*> List;
	ListProduct prodList;
	int nEmp;
};

#endif // !_MANAGER_H_