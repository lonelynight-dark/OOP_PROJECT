#include "Company.h"

void Company::output()
{
	int n = listManager.size();
	for (int i = 0; i < n; ++i) 
	{
		listManager[i]->output();
	}
}

Company::Company()
{
	string s;
	ifstream fin;

	s = "_Manager.txt";
	fin.open(s);
	load(fin);
	int n = listManager.size();
	fin.close();

	for (int i = 0; i < n; ++i) {
		s = to_string(listManager[i]->getID()) + "_Staff.txt";
		fin.open(s);
		listManager[i]->loadStaff(fin);
		fin.close();
	}
}

Company::~Company()
{
	//string s = "_Manager.txt";
	//ofstream fout;
	//fout.open(s);
	//save(fout);
	//fout.close();
	for (Manager* staff : listManager) delete staff;
}


void Company::load(ifstream& fin)
{
	int n;
	fin >> n;

	for (int i = 0; i < n; ++i) {
		//listManager.push_back(new Manager);
		listManager[i]->load(fin);
	}
}

void Company::save(ofstream& fout)
{
	int n = listManager.size();
	fout << n;

	for (int i = 0; i < n; ++i) {
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

Staff* Company::search(string username)
{
	int ID = 0;
	try {
		ID = stoi(username.substr(1));
	}
	catch (...)
	{
		throw ErrorCode::Wrong_format;
	}
	cout << ID << endl;
	if (username.size() > 0) 
	{
		if (username[0] == 'M')
		{
			for (Staff* manager : listManager)
			{
				if (manager->getID() == ID)
					return manager;
			}
		}
		else if (username[0] == 'E')
		{
			for (Manager* manager : listManager)
			{
				Staff* employee = manager->search(ID);
				if (employee != nullptr)
					return employee;
			}
		}
		else
			throw ErrorCode::Wrong_format;
	}
	return nullptr;
}
