#pragma once
#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Libary.h"

#include "Employee.h"
//#include "Manager.h"
#include "Account.h"
#include "Company.h"
class Interface
{
public:
	std::string InputPassword();
	std::vector<Account> ImportFromFile(std::string path, std::string fileName);
	int Login(string path, string userName, string password, vector<Account>& acc, int& index);
	std::string HashPassword(std::string passWord);
	void ShowTitle(std::string space);
	void ShowMenu(std::string space);
	void ShowStaffMenu(string username, Company& company, string space);
};

#endif // !_INTERFACE_H_