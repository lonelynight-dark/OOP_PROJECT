#include "Company.h"

const string source_Staff = "Data\\Staff\\";

void Company::output()
{
	int n = listManager.size();
	cout << "Number of staff: " << n << endl;
	for (int i = 0; i < n; ++i) 
	{
		cout << "------------------" << endl;
		cout << "Staff " << i + 1 << ":\n";
		cout << "------------------" << endl;
		listManager[i]->output();
		cout << "------------------\n" << endl;
	}
}

void Company::output(int ID)
{
	Staff* staff = search("M" + to_string(ID));
	staff->output();
}

Company::Company()
{
	loadAll();
}

Company::~Company()
{
	saveAll();
	for (Manager* staff : listManager) delete staff;
}

void Company::loadAll()
{
	string s;
	ifstream fin;

	s = source_Staff + "Manager.txt";
	fin.open(s);
	if (fin.is_open()) cout << "Ready..." << endl;
	else {
		cout << "Can't open..." << endl;
		exit(-100);
	}
	load(fin);
	int n = listManager.size();
	fin.close();

	for (int i = 0; i < n; ++i) {
		cout << "Employee Loading ..." << endl;
		s = source_Staff + to_string(listManager[i]->getID()) + "_Staff.txt";
		fin.open(s);
		listManager[i]->loadStaff(fin);
		fin.close();
	}
}

void Company::saveAll()
{
	string s = source_Staff + "Manager.txt";
	ofstream fout;
	fout.open(s);
	save(fout);
	fout.close();

	int n = listManager.size();
	for (int i = 0; i < n; ++i) {
		cout << "Employee Saving ..." << endl;
		s = source_Staff + to_string(listManager[i]->getID()) + "_Staff.txt";
		fout.open(s);
		listManager[i]->saveStaff(fout);
		fout.close();
	}
	fout.close();
}


void Company::load(ifstream& fin)
{
	int n;
	fin >> n;

	for (int i = 0; i < n; ++i) {
		listManager.push_back(new Manager);
		cout << "Manager Loading..." << endl;
		listManager[i]->load(fin);
	}
}

void Company::save(ofstream& fout)
{
	int n = listManager.size();
	fout << n << endl;

	for (int i = 0; i < n; ++i) {
		cout << "Manager saving..." << endl;
		listManager[i]->save(fout);
	}
}

double Company::ManagerSalary()
{
	double total = 0.0;

	for (Manager* manager : listManager)
	{
		total += manager->viewSalary();
	}

	return total;
}
double Company::EmployeeSalary()
{
	double total = 0.0;

	for (Manager* manager : listManager)
	{
		/*
			total += manager->calAllSalary();
		*/
	}

	return total;
}
int Company::countEmployees()
{
	int count = 0;

	for (Manager* manager : listManager)
	{
		/*
			total += manager->allEmployees;
		*/
	}

	return count;
}
int Company::countManagers()
{
	return listManager.size();
}

void Company::addManager()
{
	Manager* newManager = new Manager;
	newManager->input();
	listManager.push_back(newManager);
}

void Company::deleteManager()
{
	int ID;
	bool found = false;
	cout << "Enter ID: "; cin >> ID;
	int n = listManager.size();
	for (int i = 0; i < n; i++) {
		if (listManager[i]->getID() == ID) {
			listManager[i]->output();
			int opt;
			cout << "Do you want to delete (0:NO / 1:YES): ";
			cin >> opt;
			if (opt == 1) {
				delete listManager[i];
				listManager.erase(listManager.begin() + i);
			}
			found = true;
		}
	}
	if (!found) cout << "No manager with that ID!\n";
}

void Company::editManager()
{
	int ID;
	bool found = false;
	cout << "Enter ID: "; cin >> ID;
	int n = listManager.size();
	for (int i = 0; i < n; i++) {
		if (listManager[i]->getID() == ID) {
			listManager[i]->output();
			int opt;
			cout << "Do you want to edit this manager (0:NO / 1:YES): ";
			cin >> opt;
			if (opt == 1) {
				listManager[i]->edit();
			}
			found = true;
		}
	}
	if (!found) cout << "No manager with that ID!\n";
}

Staff* Company::search(int ID, string TYPE)
{
	if (TYPE == "Manager")
	{
		for (Staff* manager : listManager)
		{
			if (manager->getID() == ID)
				return manager;
		}
	}
	else if (TYPE == "Employee")
	{
		for (Manager* manager : listManager)
		{
			Staff* employee = manager->search(ID);
			if (employee != nullptr)
				return employee;
		}
	}
	return NULL;
}

Staff* Company::search(string username)
{
	int ID = 0; string TYPE;
	try {
		ID = stoi(username.substr(1));
		
		if (username[0] == 'M')
		{
			TYPE = "Manager";
		}
		else if (username[0] == 'E')
		{
			TYPE = "Employee";
		}
		else
			throw ErrorCode::Wrong_format;
	}
	catch (...)
	{
		throw ErrorCode::Wrong_format;
	}
	return search(ID, TYPE);
}
