#pragma once
#ifndef _account_h_
#define _account_h_
#include "Libary.h"
#include "sha256.h"
class Account {
	std::string username;
	std::string password;
	std::string InputPassword();
	bool InputChangePassword(std::string& passWord, std::string& newPassword, std::string& retypePassword, std::string space);
	std::string HashPassword(std::string passWord);
public:
	Account(std::string, std::string);
	Account(std::string, std::string, bool isHashed);
	bool isCorrect(std::string, std::string);
	bool isAccount(const Account&);
	bool isCorrectPass(std::string);
	bool isCorrectUser(std::string);
	void ChangePassword(std::string space);
	void savetoFile(std::ofstream& out);
};
#endif // !_account_h_