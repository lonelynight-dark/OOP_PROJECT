#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "ListProduct.h"
#include "Staff.h"
#include <string>
#include <vector>
using namespace std;

class Company final
{
	string name;
	string address;
	vector<Staff*> listStaff;
	ListProduct listProduct;
public:
	Company(){}
	~Company()	
	{
		for (Staff* staff : listStaff) delete staff;
	}
	// Calculate Salary
	double ManagerSalary();
	double EmployeeSalary();

	// Count staffs
	int Employees();
	int Managers();

	// Absent day

	// Output Staff
	void OutputStaff();
	// Another method
	string getInfo();
};

#endif // !_COMPANY_H_
