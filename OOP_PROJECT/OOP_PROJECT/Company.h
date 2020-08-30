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
private:
	//string name;
	//string address;
	vector<Manager*> listManager;
	static Company INSTANCE;
	
	Company();
	~Company();
public:
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;

	static Company* getInstance();

	void loadAll();
	void saveAll();

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
	
	void addManager();
	void deleteManager();
	void editManager();

	Staff* search(int ID, string TYPE);
	Staff* search(string username); // might throw ErrorCode::Wrong_format
};

#endif // !_COMPANY_H_
