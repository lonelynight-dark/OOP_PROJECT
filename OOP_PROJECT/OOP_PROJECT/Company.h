#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "ListProduct.h"
#include "Staff.h"
#include <string>
#include <vector>
using namespace std;

class Company
{
	string name;
	string address;
	vector<Staff*> listStaff;
	ListProduct listProduct;
public:
	Company(){}
	~Company()
	{
		int n = listStaff.size();
		for (Staff* staff : listStaff) delete staff;
	}
	string getInfo();
	// Calculate Salary
	double ManagerSalary();
	double EmployeeSalary();

	// Count staffs
	int Employees();
	int Managers();
};

#endif // !_COMPANY_H_
