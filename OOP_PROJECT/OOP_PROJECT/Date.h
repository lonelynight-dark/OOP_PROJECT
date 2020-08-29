/*
	PLEASE WRITE WHAT YOU CHANGED IN THIS FILE CLEARLY IN YOUR COMMIT
*/
#ifndef _DATE_H_
#define _DATE_H_
#include <fstream>
#include <iostream>
#include <string>

enum class ErrorDate {
	WRONG_DATE_FORMAT = -9999
};
class Date
{
public:
	Date(); // default date is 1/1/1900
	Date(int year, int month = 1, int day = 1);
	// declare Date(0) to consruct the Date as the Current date.

	Date& now();// get the current Date
	Date Yesterday();
	Date Tomorrow();
	void setDate(int year, int month, int day);
	static int getDaysInMonth(int month, int year);

	//getter
	int getDay();
	int getMonth();
	int getYear();
	//compare operator
	bool operator==(const Date& dt) const;
	bool operator!=(const Date& dt) const;
	bool operator<(const Date& dt) const;
	bool operator<=(const Date& dt) const;
	bool operator>(const Date& dt) const;
	bool operator>=(const Date& dt) const;

	// calculate operator
	Date& operator++();
	Date& operator--();
	Date& operator++(int);
	Date& operator--(int);

	Date operator+(const int& n);
	Date operator-(const int& n);
	Date& operator+=(const int& n);
	Date& operator-=(const int& n);

	int timeInterval(const Date& dt) const;
	Date& stoDate(std::string str, const char* deli);

	// input - output operator
	friend std::ostream& operator<<(std::ostream& outDev, const Date& dt);
	friend std::istream& operator>>(std::istream& inDev, Date& dt);
	//friend std::ofstream& operator>>(std::ofstream& outDev,const Date& dt);
	void save(std::ofstream&);
private:
	int day, month, year;
};


#endif // !_DATE_H_