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
	nEmp += 1;
	cout << "Employee added\n";
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
				nEmp -= 1;
				cout << "Employee deleted\n";
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
				List[i]->edit();
			}
			found = true;
		}
	}
}

double Manager::viewSalary()
{
	double s = Staff::getAbsentDays();
	s *= 1000000;
	s = 5000000 - s;
	return ((s > 0) ? s : 0);
	//double s = 5000000 - Staff::getAbsentDays() * 1000000;
}

double Manager::calculateRevenueByMonth(const int month, const int year)
{
	double prof = 0.0;
	for (Employee* s : List) {
		prof += s->calculateRevenueByMonth(month, year);
	}
	return prof;
}

double Manager::calculateRevenueByMonth(const int year)
{
	double prof = 0.0;
	for (int i = 1; i < 13; i++)
		prof += calculateRevenueByMonth(i, year);
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
	Staff::edit();  
}

void Manager::viewProd()
{
	for (int i = 0; i < nEmp; i++) {
		cout << i + 1 << ". " << List[i]->getID() << endl;
	}
	int choice;
	cout << "Choose an ID (1 - " << nEmp << "): "; cin >> choice;
	for (Employee* e : List) {
		if (choice == 1) {
			e->viewAllProducts();
			break;
		}
		else choice -= 1;
	}
	cout << endl;
}

void Manager::viewEmp()
{
	for (int i = 0; i < nEmp; i++) {
		List[i]->output();
		cout << endl;
	}
}

void Manager::viewEmpSalary()
{
	for (Staff* s : List) {
		s->viewSalary(); 
		cout << endl;
	}
}

Staff* Manager::search(int ID)
{
	Staff* em = nullptr;
	for (int i = 0; i < nEmp; i++)
		if (List[i]->getID() == ID)
			return List[i];
	return em;
}
