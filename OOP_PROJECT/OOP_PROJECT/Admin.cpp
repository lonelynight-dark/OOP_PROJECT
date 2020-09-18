#include "Admin.h"

void Admin::AddAccount(ofstream& out, string u, string p) {
	Account* nacc = new Account(u, p, false);
	nacc->savetoFile(out);
	acc.push_back(nacc);
}

Account* Admin::search(string u)
{
	for (auto& a : acc)
	{
		if (a->isCorrectUser(u))
			return a;
	}
	return nullptr;
}


void Admin::DeleteAccount(ofstream& out, string u)
{
	bool isFound = false;

	for (vector<Account*>::iterator a = acc.begin(); a != acc.end(); ++a)
	{
		if ((*a)->isCorrectUser(u))
		{
			acc.erase(a);
			isFound = true;
			break;
		}
	}

	//if (isFound)
		ExportToFile(out);
}

void Admin::ImportFromFile(ifstream& filein)
{
	std::string line, u, p;
	while (!filein.eof()) {
		std::getline(filein, u);
		std::getline(filein, p);
		if (u == "" || p == "") break;
		acc.push_back(new Account(u, p));
	}
	filein.close();
}

void Admin::ExportToFile(ofstream& out)
{
	for (int i = 0; i < acc.size(); ++i) {
		acc[i]->savetoFile(out);
	}
}

bool Admin::isExisted(Account* a) {
	for (Account* b : acc) {
		if (b->isAccount(*a)) {
			return true;
		}
	}
	return false;
}
