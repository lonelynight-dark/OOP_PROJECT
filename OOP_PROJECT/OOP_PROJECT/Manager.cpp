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

Employee* Manager::addStaff()
{
	Employee* newEmployee = new Employee;
	newEmployee->input();
	List.push_back(newEmployee);
	nEmp += 1;
	cout << "Employee added\n";
	return newEmployee;
}

int Manager::deleteStaff()
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
			}
			found = true;
			return ID;
		}
	}
	if (!found) cout << "No employee with that ID!\n";
	return -1;
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

void Manager::checkAttendance()
{
	for (Employee* e : List)
		cout << e->getID() << endl;
	int N;
	cout << "Absent employeees: ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "Enter ID: ";
		int id;
		cin >> id;
		if (search(id) != NULL){
			(search(id))->absent();
		}
		cout << "Attendance checked\n";
	}
}

Staff* Manager::search(int ID)
{
	for (int i = 0; i < nEmp; i++)
		if (List[i]->getID() == ID)
			return List[i];
	return NULL;
}
