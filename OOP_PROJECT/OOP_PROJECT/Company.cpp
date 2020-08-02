#include "Company.h"

string Company::getInfo()
{
	string info;
	info =
		"Name: " + name + '\n' +
		"Adress: " + address + '\n';
	return info;
}
