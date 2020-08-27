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
void Interface::ImportFromFile(std::string path, std::string fileName) {
	acc.clear();
	std::ifstream filein(path + fileName);
	if (!filein.is_open()) {
		cout << "cannot open file !" << endl;
		exit(0);
	}
	std::string line, u, p;
	while (!filein.eof()) {
		std::getline(filein, u);
		std::getline(filein, p);
		if (u == "" || p == "") break;
		acc.push_back(new Account(u, p));
	}
	filein.close();
}
int Interface::Login(string path, string userName, string password, Company& com, string space) {
	string fileName[] = { "Employee.txt" , "Manager.txt" };
	if (userName[0] == 'E' || userName[0] == 'M')
		ImportFromFile(path, fileName[userName[0] == 'M']);
	else return 0;
	int n = acc.size();
	int log = 0;
	for (int i = 0; i < n; i++) {
		if (acc[i]->isCorrect(userName, password)) {
			log = 1;
			ShowStaffMenu(com, space, userName, path, i);
			break;
		}
	}
	return log;
}

void Interface::ShowStaffMenu(Company& company, string space, string username, string path, int index) {
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
			if (s->getType() == "Employee") {
				Employee* e = (Employee*)s;
				ShowEmployeeMenu(*e, space);
			}
			else {
				Manager* m = (Manager*)s;
				ShowManagerMenu(*m, space);
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
			acc[index]->ChangePassword(space);
			// xuất ra file
			ofstream outfile;
			if (s->getType() == "Employee") {
				outfile.open(path + "Employee.txt");
				ExportToFile(outfile);
			}
			else {
				outfile.open(path + "Manager.txt");
				ExportToFile(outfile);
			}
			outfile.close();
		}
		else if (choice == 4) {
			return;
		}
	}
}
void Interface::ShowEmployeeMenu(Employee& emp, string space) {
	string command[] =
	{
		"View Salary",
		"View items in stock",
		"View expired items in stock",
		"View empty items in stock",
		"Add products to stock",
		"Delete products",
		"Search product",
		"View trade history",
		"Sell product"
	};
	int nCommand =9; // idk
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
		system("CLS");
		if (choice == 1)
		{
			cout << "********** SALARY **********\n\n";
			emp.viewSalary();
		}
		else if (choice == 2)
		{
			cout << "********** VIEW ALL PRODUCT **********\n\n";
			emp.viewAllProducts();
		}
		else if (choice == 3)
		{
			cout << "********** VIEW EXPIRED PRODUCT **********\n\n";

			emp.displayExpiredProduct();
		}
		else if (choice == 4)
		{
			cout << "********** VIEW EMPTY PRODUCT **********\n\n";

			emp.displayEmptyProduct();
		}
		else if (choice == 5)
		{
			
			char ch;
			do

			{
				system("CLS");

				cout << "********** INSERT PRODUCT **********\n\n";
				emp.EnterProductInfo();

				cout << "Insert sucessfully!\n";
				

				cout << "Continue to insert ?\n y/n > ";
				cin >> ch;
			} 
			while (ch == 'y');
		}
		else if (choice == 6)
		{
			char ch;
			do

			{
				system("CLS");
				cout << "********** DELETE PRODUCT **********\n\n";

				cout << "Enter ID:";
				int id = 0;
				cin >> id;
				if (emp.searchProductById(id) == nullptr)

					cout << "Not found!\n";
				else
				{
					emp.DeleteProduct(id);


					cout << "Delete sucessfully!\n";
				}


				cout << "Continue to insert ?\n y/n > ";
				cin >> ch;
			} while (ch == 'y');
		}
		else if (choice == 7)
		{
			cout << "********** SEARCH **********\n\n";
			cout << "Press 1 - Search by ID\n";
			cout << "Press 2 - Search by product name\n";
			int n;
			cin >> n;
			if (n == 1)
			{
				system("CLS");
				cout << "********** SEARCH BY ID **********\n\n";
				cout << "Enter ID:";
				int id=0;
				cin >> id;
				if(emp.searchProductById(id)!=nullptr)
				emp.searchProductById(id)->output();
				else cout << "Not found!\n";
			}
			else
			{
				system("CLS");
				cout << "********** SEARCH BY NAME **********\n\n";
				cin.clear();
				cin.ignore(1);
				cout << "Enter product name:";
				string name;
				getline(cin, name);
				if (emp.searchProductByName(name) != nullptr)
					emp.searchProductByName(name)->output();
				else cout << "Not found!\n";
			}

		}
		else if (choice == 8)
		{
			emp.viewTradeHistory();
		}
		else if (choice == 9)
		{
			emp.sellProduct();
		}
		else if (choice == 0)
			return;
		else
		{
			std::cout << "Bad choice\nPress any key to try again";
		}
			_getch();
	}
}
void Interface::ShowManagerMenu(Manager& man, string space) {
	string command[] =
	{
		"123"
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

void Interface::ExportToFile(ofstream& out) {
	for (int i = 0; i < acc.size(); ++i) {
		acc[i]->savetoFile(out);
	}
}

void Interface::AddAccount(string path, string filename, string username) {
	ImportFromFile(path, filename);
	//check if existed
	for (int i = 0; i < acc.size(); ++i) {
		if (acc[i]->isCorrectUser(username)) {
			cout << "Username has already existed !" << endl;
		}
	}
	acc.push_back(new Account(username, "1"));
	
}