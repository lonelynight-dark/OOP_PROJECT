#pragma once
#ifndef _admin_h_
#define _admin_h_
#include "Staff.h"
#include "Account.h"
class Admin : public Staff {
private:
	vector<Account*> acc;
public:
	~Admin() { for (auto& a : acc) delete a; }
	void ImportFromFile(ifstream& filein);
	void ExportToFile(ofstream& out);
	void AddAccount(ofstream& out, string u, string p);
	Account* search(string);
	void DeleteAccount(ofstream& out, string);
	double viewSalary() { return 0.0; }
	string getType() { return "Admin"; }
};
#endif // !_admin_h_
