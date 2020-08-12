#include "Manager.h"

void Manager::loadStaff(ifstream& fi)
{
	if (fi.is_open()) {
		fi >> nEmp;
		for (int i = 0; i < nEmp; i++) {
			Employee* newEmp = new Employee;
			newEmp->load(fi);
			List.push_back(newEmp);
		}
	}
}

void Manager::saveStaff(ofstream& fo)
{
	fo << nEmp << endl;
	for (int i = 0; i < nEmp; i++)
		List[i]->save(fo);
}

void Manager::addStaff()
{
	Employee* newEmployee = new Employee;
	newEmployee->input();
	List.push_back(newEmployee);
}

void Manager::deleteStaff()
{
	int ID;
	bool found = false;
	cout << "Enter ID: "; cin >> ID;
	for (int i = 0; i < nEmp; i++) {
		if (List[i]->getID() == ID) {
			List[i]->output();
			int opt;
			cout << "Do you want to delete (0:NO / 1:YES): ";
			cin >> opt;
			if (opt == 1) {
				delete List[i];
				List.erase(List.begin() + i);
			}
			found = true;
		}
	}
	if (!found) cout << "No employee with that ID!\n";
}

void Manager::editStaff()
{
	int ID;
	bool found = false;
	cout << "Enter ID: "; cin >> ID; 
	for (int i = 0; i < nEmp; i++) {
		if (List[i]->getID() == ID) {
			List[i]->output();
			int opt;
			cout << "Do you want to edit this employee (0:NO / 1:YES): ";
			cin >> opt;
			if (opt == 1) {
				//List[i].edit();
			}
			found = true;
		}
	}
}

double Manager::profit()
{
	double prof = 0.0;
	for (int i = 0; i < nEmp; i++) {
		//prof += List[i]->profit();
	}
	return prof;
}

void Manager::input()
{
	Staff::input();
}

void Manager::output()
{
	Staff::output();
}

void Manager::edit()
{
	//Staff::edit(); <- 
}

void Manager::viewProd()
{
	prodList.outputList();
}

void Manager::viewEmp()
{
	for (int i = 0; i < nEmp; i++) List[i]->output();
}

void Manager::viewEmpSalary()
{
	for (Staff* s : List) {
		cout << "ID: " << s->getID() << endl;
		cout << "Name: " << s->getName() << endl;
		cout << "Salary: " << s->viewSalary() << endl << endl;
	}
}

Staff* Manager::search(string user)
{
	Staff* em = nullptr;
	for (int i = 0; i < nEmp; i++)
		if (List[i]->isCorrectAccount(user))
			return List[i];
	return em;
}
