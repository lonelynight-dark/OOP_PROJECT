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
	int nCommand = sizeof(command) / sizeof(command[0]);
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
int Interface::Login(string path, string userName, string password, string space) {
	string fileName[] = { "Employee.txt" , "Manager.txt", "Admin.txt" };
	if (userName[0] == 'E' || userName[0] == 'M')
		ImportFromFile(path, fileName[userName[0] == 'M']);
	else {
		ImportFromFile(path, fileName[2]);
	}
	int n = acc.size();
	int log = 0;
	for (int i = 0; i < n; i++) {
		if (acc[i]->isCorrect(userName, password)) {
			log = 1;
			ShowStaffMenu(space, userName, path, i);
			break;
		}
	}
	return log;
}

void Interface::ShowStaffMenu(string space, string username, string path, int index) {
	Staff* s = Company::getInstance()->search(username);
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
			else if (s->getType() == "Manager") {
				Manager* m = (Manager*)s;
				ShowManagerMenu(*m, space);
			}
			else {
				ShowAdminMenu(*(Admin*)s, space);
			}

			Company::getInstance()->saveAll();
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
			else if (s->getType() == "Manager") {
				outfile.open(path + "Manager.txt");
				ExportToFile(outfile);
			}
			else {
				outfile.open(path + "Admin.txt");
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
	int nCommand = sizeof(command) / sizeof(command[0]);
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


				cout << "Continue to delete ?\n y/n > ";
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
				else 
					cout << "Not found!\n";
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
		"Add Staff",					//1
		"Delete Staff",					//2
		"Edit Staff",					//3
		"See salary",					//4
		"Watch revenue by month",		//5
		"Watch revenue by year",		//6
		"View employee",				//7
		"View employee's salary",		//8
		"View product",					//9
		"Check attendance"				//10
	};
	int nCommand = sizeof(command) / sizeof(command[0]);
	while (true)
	{
		system("CLS");
		ShowTitle(space);
		std::cout << space << "        Staff Window\n";
		std::cout << "================================================================================\n";
		std::cout << "0. Return\n";
		for (int i = 0; i < nCommand; i++)
		{
			std::cout << i + 1 << ". " << command[i] << endl;
		}

		std::cout << "----------------------------------------\n";

		int choice;
		std::cout << "Input choice: ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			return;
		case 1:
			man.addStaff(); break;
		case 2:
			man.deleteStaff(); break;
		case 3: 
			man.editStaff(); break;
		case 4:
			cout << std::setprecision(0) << std::showpoint << std::fixed;
			cout << "Salary: " << man.viewSalary() << endl; break;
		case 5: {
			int month, year;
			cout << "Month: "; cin >> month;
			cout << "Year: "; cin >> year;
			cout << "Revenue in " << month << " of " << year << ": " << man.calculateRevenueByMonth(month, year) << endl;
			break;
		}
		case 6: {
			int year;
			double p = 0;
			cout << "Year: "; cin >> year;
			for (int i = 1; i < 13; i++) {
				p += man.calculateRevenueByMonth(i, year);
				cout << i << " / " << year << " revenue: " << p << endl;
			}
			cout << "Revenue in " << year << ": " << p << endl;
			break;
		}
		case 7:
			man.viewEmp();
			break;
		case 8:
			man.viewEmpSalary();
			break;
		case 9: 
			man.viewProd();
			break;
		case 10:
			man.checkAttendance();
			break;
		default:
		{
			std::cout << "Bad choice";
		}
		}
		char k;
		cout << "\nPress any key to continue!";
		k = _getch();
	}
}

void Interface::ShowAdminMenu(Admin& ad, string space) {
	string u, p;
	ofstream out;
	Staff* man;
	int ID;
	bool isExist = false;
	string command[] = {
		"Add Manager",
		"Delete Manager",
		"Edit Manager",
		"Search Manager",
		"View All Manager"
	};
	int nCommand = sizeof(command) / sizeof(command[0]);
	Company* c = Company::getInstance();
	// call function of company to 
	// 
	string filename[] = { "Employee.txt", "Manager.txt" };
	ifstream fin;
	fin.open("data/Account/Manager.txt");
	ad.ImportFromFile(fin);
	fin.close();
	while (true)
	{
		system("CLS");
		ShowTitle(space);
		std::cout << space << "        Admin Window\n";
		std::cout << "================================================================================\n";
		std::cout << "0. Return\n";
		for (int i = 0; i < nCommand; i++)
		{
			std::cout << i + 1 << ". " << command[i] << endl;
		}

		std::cout << "----------------------------------------\n";

		int choice;
		std::cout << "Input choice: ";
		std::cin >> choice;
		enum adminMenu {
			EXIT = 0,
			ADD,
			DELETE,
			EDIT,
			SEARCH,
			VIEW
		};
		int ID;
		switch (choice) {
		case EXIT:
			return;
		case ADD:
			out.open("data/Account/Manager.txt", ios::app);
			man = c->addManager();  
			if (man == nullptr)
			{
				cout << "User existed !" << endl;
				cout << "Press any key to choose again" << endl;
			}
			else
			{
				u = "M" + to_string(man->getID());
				ad.AddAccount(out, u, "1");
				cout << "Add manager OK...!";
			}
			out.close();
			break;
		case DELETE:
			out.open("data/Account/Manager.txt");
			ID = c->deleteManager(); 
			if (ID != -1)
			{
				u = "M" + to_string(ID);
				ad.DeleteAccount(out, u);
			}
			out.close();
			break;
		case EDIT:
			c->editManager();
			cout << "Edit OK...";
			break;
		case SEARCH:
			cout << "ID to search: "; cin >> ID;
			c->output(ID);
			break;
		case VIEW:
			c->output();
			break;
		default:
			std::cout << "Bad choice !" << endl;
			cout << "Press any key to choose again!" << endl;
		}
		_getch();
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