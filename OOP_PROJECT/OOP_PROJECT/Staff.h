#ifndef _STAFF_H_
#define _STAFF_H_

#include "Date.h"
#include <string>

class Staff
{
	std::string ID;
	std::string name;
	bool gender;
	std::string phoneNumber;
	std::string emailAddress;
	Date yob; // year of birth
	int absentDay;
public:
	Staff();
	virtual ~Staff() {};
	virtual void input();
	virtual double viewSalary() = 0;
	virtual void viewAllProducts() = 0;
	std::string showInfo();
};

#endif // !_STAFF_H_