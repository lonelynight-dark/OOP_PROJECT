#include "Manager.h"

void Manager::addStaff()
{
	Employee* newEmployee = new Employee;
	newEmployee->input();
	List.push_back(newEmployee);
}

void Manager::input()
{
	Staff::input();
}

void Manager::output()
{
	Staff::output();
}

void Manager::viewProd()
{
	prodList.outputList();
}

void Manager::viewEmp()
{
	for (int i = 0; i < nEmp; i++) List[i]->output();
}
