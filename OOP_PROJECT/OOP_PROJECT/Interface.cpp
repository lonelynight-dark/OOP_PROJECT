#include "Interface.h"

std::string Interface::InputPassword() {
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
std::string Interface::HashPassword(std::string passWord)
{
	SHA256 sha256;
	std::string hashPass = sha256(passWord);
	return hashPass;
}

void Interface::ShowTitle(std::string space)
{
	system("CLS");
	std::cout << space << "Selling Management System\n";
	std::cout << "================================================================================\n";
}
void ShowMenu(std::string space)
{
	std::string command[] =
	{
		"Show Menu",
		"View Profile",
		"Change Password",
		"Logout"
	};
	int nCommand = 4;
	for (int i = 0; i < nCommand; i++)
	{
		std::cout << space << i + 1 << ". " << command[i] << std::endl;
	}
}
bool Interface::InputChangePassword(std::string& passWord, std::string& newPassword, std::string& retypePassword, std::string space)
{
	ShowTitle(space);
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
void Interface::ShowMenu(std::string space)
{
	std::string command[] =
	{
		"Show Menu",
		"View Profile",
		"Change Password",
		"Logout"
	};
	int nCommand = 4;
	for (int i = 0; i < nCommand; i++)
	{
		std::cout << space << i + 1 << ". " << command[i] << std::endl;
	}
}

