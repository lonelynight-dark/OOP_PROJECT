#ifndef _STAFF_H_
#define _STAFF_H_

#include "Date.h"
#include "Libary.h"

#ifndef _STD_CALL_
using namespace std;
#endif // !_STD_CALL_


class Staff
{
private:
	int ID;
	std::string name;
	bool gender;
	std::string phoneNumber;
	std::string address;
	Date yob; // year of birth
	int absentDay;
public:
	// constructor & destructor
	Staff();
	Staff(int, string, bool, string, string, Date, int);
	virtual ~Staff() {};
	// view
	virtual double viewSalary() = 0;
	// getter
	int getID();
	string getName();
	int getAbsentDays();
	void absent(); // increase the absentDays + 1
	// input & output
	virtual void input();
	virtual void output();
	virtual void load(ifstream&);
	virtual void save(ofstream&);
	// edit
	virtual void edit();
	virtual void change(int, string, bool, string, string, Date, int);
	/*
		overide function below
		return "Manager" if staff is Manager
		return "Employee" if staff is Employee
	*/
	virtual string getType() = 0;

	friend ostream& operator<<(ostream&,const Staff&) ;
};

#endif // !_STAFF_H_