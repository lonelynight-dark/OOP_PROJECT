#include "Company.h"
string Company::getInfo()
{
	string info;
	info =
		"Name: " + name + '\n' +
		"Adress: " + address + '\n';
	return info;
}
double Company::ManagerSalary()
{
	double total = 0.0;

	for (Staff* staff : listStaff)
	{
		if (typeid(staff).name() == "Manager")
		{
			total += staff->viewSalary();
		}
	}

	return total;
}
double Company::EmployeeSalary()
{
	double total = 0.0;

	for (Staff* staff : listStaff)
	{
		if (typeid(staff).name() == "Employee")
		{
			total += staff->viewSalary();
		}
	}

	return total;
}
int Company::Employees()
{
	int count = 0;

	for (Staff* staff : listStaff)
	{
		if (typeid(staff).name() == "Employee")
		{
			++count;
		}
	}

	return count;
}
int Company::Managers()
{
	int count = 0;

	for (Staff* staff : listStaff)
	{
		if (typeid(staff).name() == "Manager")
		{
			++count;
		}
	}

	return count;
}
