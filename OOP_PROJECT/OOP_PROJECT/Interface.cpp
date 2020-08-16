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
std::vector<Account> Interface::ImportFromFile(std::string path, std::string fileName) {
	std::vector<Account> acc;
	std::ifstream filein(path + fileName);
	std::string line, u, p;
	while (std::getline(filein, line)) {
		std::getline(filein, u);
		std::getline(filein, p);
		acc.push_back(Account(u, p));
	}
	filein.close();
}
int Interface::Login(string path, string userName, string password, vector<Account>& acc, int& index) {
	string fileName[] = { "Employee.txt" , "Manager.txt" };
	password = HashPassword(password);
	acc = ImportFromFile(path, fileName[0]);
	int n = acc.size();
	bool log = false;
	for (int i = 0; i < n; i++) {
		if (acc[i].isCorrect(userName, password)) {
			index = i;
			log = true;
			break;
		}
	}
	if (userName[0] == 'E' && log) {
		return 1;
	}
	else if (userName[0] == 'M' && log) {
		return 2;
	}
	return 0;
}

void Interface::ShowStaffMenu(Account& acc, Company& company, string space, string username) {
	Staff* s = company.search(username);
	if (s == nullptr) {
		std::cout << space << "Staff is not exist\nPress any key to try again";
		_getch();
		return;
	}
	while (true)
	{
		ShowTitle(space);
		std::cout << space << "Hi " << s->getName() << "!" << endl;
		std::cout << space << "------------------" << endl;
		ShowMenu(space);

		int choice;
		std::cout << "Input choice: ";
		std::cin >> choice;
		if (choice == 1) {
			if (username[0] == 'E') {

			}
			else {

			}
		}
		else if (choice == 2) {
			system("CLS");
			ShowTitle(space);
			std::cout << *s;
			std::cout << "Press any key to return\n";
			_getch();
		}
		else if (choice == 3) {
			acc.ChangePassword(space);
		}
	}
}
void Interface::ShowEmployeeMenu(Employee emp, string space) {
	string command[] =
	{
		//write command here
	};
	int nCommand = 4; // idk
	while (true)
	{
		system("CLS");
		ShowTitle(space);
		std::cout << space << "        Employee Window\n";
		std::cout << "================================================================================\n";
		for (int i = 0; i < nCommand; i++)
		{
			std::cout << i + 1 << ". " << command[i] << endl;
		}

		std::cout << "0. Return\n";
		std::cout << "----------------------------------------\n";

		int choice;
		std::cout << "Input choice: ";
		std::cin >> choice;

		if (choice == 1)
		{
			
		}
		else if (choice == 2)
		{
			
		}
		else if (choice == 3)
		{
			
		}
		else if (choice == 4)
		{
			
		}
		else if (choice == 0)
			return;
		else
		{
			std::cout << "Bad choice\nPress any key to try again";
			_getch();
		}
	}
}
void Interface::ShowManagerMenu(Manager man, string space) {
	string command[] =
	{
		//write command here
	};
	int nCommand = 4; // idk
	while (true)
	{
		system("CLS");
		ShowTitle(space);
		std::cout << space << "        Staff Window\n";
		std::cout << "================================================================================\n";
		for (int i = 0; i < nCommand; i++)
		{
			std::cout << i + 1 << ". " << command[i] << endl;
		}

		std::cout << "0. Return\n";
		std::cout << "----------------------------------------\n";

		int choice;
		std::cout << "Input choice: ";
		std::cin >> choice;

		if (choice == 1)
		{

		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

		}
		else if (choice == 4)
		{

		}
		else if (choice == 0)
			return;
		else
		{
			std::cout << "Bad choice\nPress any key to try again";
			_getch();
		}
	}
}