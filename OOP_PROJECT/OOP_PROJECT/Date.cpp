#include "Date.h"

bool isLeapYear(const int year) {
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
int getDaysInMonth(int month, int year) {
	const int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((month == 2 && isLeapYear(year)) ? 1 : 0) + days_in_month[month - 1];
}

#include <ctime>
Date& Date::now() {
	time_t now = time(0);
	struct tm tstruct;
	localtime_s(&tstruct, &now);
	day = tstruct.tm_mday;
	month = tstruct.tm_mon + 1;
	year = tstruct.tm_year + 1900;
	return (*this);
}

Date::Date() : Date(1900) {}

Date::Date(int year, int month, int day) {
	// if the date is not valid, make it in to default 
	if (year == 0) { now(); } 
	else {
		if (year < 0) year = 1;
		if (month <= 0 || month > 12) month = 1;
		if (day <= 0 || day > getDaysInMonth(month, year)) day = 1;
		this->day = day; this->month = month; this->year = year;
	}
}
Date Date::Tomorrow() {
	Date dt(*this);
	dt.day++;
	if (dt.day > getDaysInMonth(dt.month, dt.year)) { dt.day = 1; dt.month++; }
	if (dt.month > 12) { dt.month = 1; dt.year++; }
	return dt;
}
Date Date::Yesterday() {
	Date dt(*this);
	if (day == 1 && month == 1 && year == 1) { std::cout << "Can't find the previous date"; } // year should be positive
	else {
		dt.day--;
		if (dt.day == 0) {
			dt.month--;
			if (dt.month == 0) { dt.month = 12; dt.year--; }
			dt.day = getDaysInMonth(dt.month, dt.year);
		}
	}
	return dt;
}

//compare operator
bool Date::operator==(const Date& dt) const {
	return day == dt.day && month == dt.month && year == dt.year;
}
bool Date::operator!=(const Date& dt) const {
	return !(*this == dt);
}
bool Date::operator<(const Date& dt) const {
	if (year != dt.year) return year < dt.year;
	if (month != dt.month) return month < dt.month;
	return day < dt.day;
}
bool Date::operator>(const Date& dt) const {
	if (year != dt.year) return year > dt.year;
	if (month != dt.month) return month > dt.month;
	return day > dt.day;
}
bool Date::operator<=(const Date& dt) const {
	return !(*this > dt);
}
bool Date::operator>=(const Date& dt) const {
	return !(*this < dt);
}

// calculate operator
Date& Date::operator++() {
	return (*this) += 1;
}
Date& Date::operator--() {
	return (*this) -= 1;
}
Date& Date::operator++(int) {
	return (*this) += 1;
}
Date& Date::operator--(int) {
	return (*this) -= 1;
}

Date Date::operator+(const int& n) {
	Date dt(*this);
	dt += n;
	return dt;
}
Date Date::operator-(const int& n) {
	Date dt(*this);
	dt -= n;
	return dt;
}
Date& Date::operator+=(const int& n) {
	for (int i = 0; i < n; ++i) *this = Tomorrow();
	return *this;
}
Date& Date::operator-=(const int& n) {
	for (int i = 0; i < n; ++i) *this = Yesterday();
	return *this;
}

int Date::timeInterval(const Date& dt) const {
	// return the difference between two dates
	if (*this == dt) return 0;
	if (*this > dt) return dt.timeInterval(*this);
	int diff = 0;
	Date tmp(*this);

	while (tmp != dt) {
		diff += 1; tmp++;
	}
	return diff;
}

// type-cast operator
Date::operator int() const {
	Date dtNow(0); // get current date
	Date startDt(dtNow.year); // make the date as the first date of the current year
	return startDt.timeInterval(*this);
}
Date::operator long() const {
	Date startDt(1);  // create a date as 1/1/1
	return startDt.timeInterval(*this);
}

// input - output operator
std::ostream& operator<<(std::ostream& outDev, const Date& dt) {
	outDev << dt.day << '/' << dt.month << '/' << dt.year;
	return outDev;
}
std::istream& operator>>(std::istream& inDev, Date& dt) {
	inDev >> dt.day >> dt.month >> dt.year;
	if (dt.year <= 0)   dt.year = 1900;
	if (dt.month <= 0 || dt.month > 12) dt.month = 1;
	if (dt.day <= 0 || dt.day > getDaysInMonth(dt.month, dt.year)) dt.day = 1;
	return inDev;
}

std::ofstream& operator>>(std::ofstream& outDev,const Date& dt)
{
	outDev << dt.day << ' ' << dt.month << ' ' << dt.year;
	return outDev;
}

void Date::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
