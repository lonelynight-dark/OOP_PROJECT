#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "ListProduct.h"
#include "Staff.h"
#include "Manager.h"
#include "Admin.h"
#include <string>
#include <vector>
using namespace std;

class Company final
{
private:
	vector<Manager*> listManager;
	static Company INSTANCE;
	static Admin admin;
	Company();
	~Company();

	void loadAll();
public:
	void saveAll();
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;

	static Company* getInstance();

	void load(ifstream&);
	void save(ofstream&);

	//void output();
	void output(int ID);
	//void input();
	// Calculate Salary
	double ManagerSalary();
	double EmployeeSalary();

	// Count staffs
	int countEmployees();
	int countManagers();

	// Absent day

	// Output Staff
	void output();
	
	Staff* addManager();
	int deleteManager();
	Staff* editManager();

	Staff* search(int ID, string TYPE);
	Staff* search(string username); // might throw ErrorCode::Wrong_format
};

#endif // !_COMPANY_H_
