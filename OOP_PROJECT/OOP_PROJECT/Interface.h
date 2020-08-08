#pragma once
#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Libary.h"
#include "sha256.h"
#include "Employee.h"
#include "Manager.h"
#include "Account.h"
class Interface
{
public:
	std::string InputPassword();
	
	int Login(string path, string userName, string password, vector<Account> acc, int& index);
	std::string HashPassword(std::string passWord);
	void ShowTitle(std::string space);
	void ShowMenu(std::string space);
	bool InputChangePassword(std::string& passWord, std::string& newPassword, std::string& retypePassword, std::string space);
};

#endif // !_INTERFACE_H_