#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "ListProduct.h"
#include "Staff.h"
#include "Manager.h"
#include <string>
#include <vector>
using namespace std;

class Company final
{
	string name;
	string address;
	vector<Manager*> listManager;
public:
	Company();
	~Company();

	void load(ifstream&);
	void save(ofstream&);
	// Calculate Salary
	double ManagerSalary();
	double EmployeeSalary();

	// Count staffs
	int countEmployees();
	int countManagers();

	// Absent day

	// Output Staff
	void output();
	
	void addManager();
	void deleteManager();
	void editManager();

	Staff* search(string username);
};

#endif // !_COMPANY_H_
