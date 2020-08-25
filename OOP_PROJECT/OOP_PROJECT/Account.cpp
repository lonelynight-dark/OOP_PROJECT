#include "Account.h"

bool Account::isCorrect(std::string u, std::string p) {
	return username == u && password == HashPassword(p);
}

Account::Account(std::string u, std::string p) {
	username = u;
	password = p;
}

bool Account::isCorrectPass(std::string pwd) {
	return password == HashPassword(pwd);
}

std::string Account::HashPassword(std::string passWord)
{
	SHA256 sha256;
	std::string hashPass = sha256(passWord);
	return hashPass;
}

std::string Account::InputPassword() {
	std::string passWord = "";
	char c = _getch();
	while (c != '\n' && c != '\r')
	{
		if (c == '\b')
		{
			int count = passWord.length();
			if (count > 0)
			{
				std::cout << "\b \b";
				passWord = passWord.substr(0, passWord.length() - 1);
			}
		}
		else
			if (c == 27)
			{
				return "";
			}
			else
			{
				std::cout << "*";
				passWord += c;
			}
		c = _getch();
	}
	std::cout << "\n";
	return passWord;
}
bool Account::InputChangePassword(std::string& passWord, std::string& newPassword, std::string& retypePassword, std::string space)
{
	std::cout << space << "Change Password\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "ESC. Return\n";

	std::cout << "Password > ";
	passWord = InputPassword();
	if (passWord == "")
		return false;

	std::cout << "New password > ";
	newPassword = InputPassword();
	if (newPassword == "")
		return false;

	std::cout << "Retype password > ";
	retypePassword = InputPassword();
	if (retypePassword == "")
		return false;

	passWord = HashPassword(passWord);
	return true;
}
void Account::ChangePassword(std::string space) {
	while (true)
	{
		std::string passWord, newPassword, retypePassword;

		bool isSuccessInput = InputChangePassword(passWord, newPassword, retypePassword, space);
		if (!isSuccessInput)
			return;

		if (!isCorrectPass(passWord))
		{
			std::cout << "Password is wrong\nPress any key to try again";
			_getch();
		}
		else
		{
			if (newPassword != retypePassword)
			{
				std::cout << "Retype password and new password is not match\nPress any key to try again";
				_getch();
			}
			else
			{
				password = HashPassword(newPassword);
				std::cout << "Changed password successfully" << std::endl;
				_getch();
				return;
			}
		}
	}
}

void Account::savetoFile(std::ofstream& out) {
	out << username << std::endl;
	out << HashPassword(password) << std::endl;
}