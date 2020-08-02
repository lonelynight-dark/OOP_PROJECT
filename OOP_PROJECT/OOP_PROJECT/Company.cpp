#include "Company.h"

Company::Company() 
{
}

Company::~Company()
{
	int n = listStaff.size();
	for (int i = 0; i < n; ++i) delete listStaff[i];
}

string Company::getInfo()
{
	string info;
	info =
		"Name: " + name + '\n' +
		"Adress: " + address + '\n';
	return info;
}
