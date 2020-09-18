#pragma once
#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Libary.h"

#include "Employee.h"
//#include "Manager.h"
#include "Account.h"
#include "Company.h"
#include "Admin.h"
class Interface
{
private:
	vector<Account*> acc;
public:
	void AddAccount(string path, string filename, string username);
	std::string InputPassword();
	void ImportFromFile(std::string path, std::string fileName);
	int Login(string path, string userName, string password, string space);
	void ShowTitle(std::string space);
	void ShowMenu(std::string space);
	void ShowStaffMenu(string space, string username, string path, int index);
	void ShowEmployeeMenu(Employee& emp, string space);
	void ShowManagerMenu(Manager& man, string space);
	void ShowAdminMenu(Admin& ad, string space);
	void ExportToFile(ofstream& out);
	~Interface() { for (auto& a : acc) delete a; }
};

#endif // !_INTERFACE_H_