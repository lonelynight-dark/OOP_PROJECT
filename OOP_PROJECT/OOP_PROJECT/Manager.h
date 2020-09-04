#ifndef _MANAGER_H_
#define _MANGAGER_H_

#include "Employee.h"
#include <fstream>
#include "Staff.h"
#include <vector>

class Manager: public Staff
{
public:
	Manager() :Staff() { nEmp = 0; }
	~Manager() { for (int i = 0; i < nEmp; i++) delete List[i]; }

	void load(ifstream& fi) { Staff::load(fi); }
	void save(ofstream& fo) { Staff::save(fo); }
	string getType() { return "Manager"; }

	void loadStaff(ifstream& fi);
	void saveStaff(ofstream& fo);

	Employee* addStaff();
	void deleteStaff();
	void editStaff();
	double viewSalary();

	double calculateRevenueByMonth(const int month, const int year);
	double calculateRevenueByMonth(const int year);

	// keyboard input functions
	void input();
	void output();
	void edit();

	void viewProd();
	void viewEmp();
	void viewEmpSalary();

	Staff* search(int ID);
private:
	std::vector<Employee*> List;
	int nEmp;
};

#endif // !_MANAGER_H_