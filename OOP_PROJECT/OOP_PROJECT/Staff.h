#ifndef _STAFF_H_
#define _STAFF_H_

#include "Date.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Staff
{
	int ID;
	std::string name;
	bool gender;
	std::string phoneNumber;
	std::string emailAddress;
	Date yob; // year of birth
	int absentDay;
public:
	Staff();
	Staff(int, string, bool, string, string, Date, int);
	virtual ~Staff() {};
	virtual double viewSalary() = 0;
	virtual void viewAllProducts() = 0;
	int getID();
	string getName();
	int getAbsentDays();
	virtual void input();
	virtual void output();
	virtual void load(ifstream&);
	virtual void save(ofstream&);
};

#endif // !_STAFF_H_