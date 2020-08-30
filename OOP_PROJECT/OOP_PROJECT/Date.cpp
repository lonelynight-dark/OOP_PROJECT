#include "Date.h"

bool isLeapYear(const int year) {
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
int Date::getDaysInMonth(int month, int year) {
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

Date& Date::stoDate(std::string str, const char* deli)
{
	std::string::size_type prev = str.find_first_not_of(deli);
	std::string::size_type found = str.find_first_of(deli, prev); 
	unsigned short i = 0;
	while ((i < 3 && found != std::string::npos) || (i == 2 && found == std::string::npos))
	{
		try {
			if (i == 0) day   = stoi(str.substr(prev, found));
			if (i == 1) month = stoi(str.substr(prev, found));
			if (i == 2) year  = stoi(str.substr(prev, found));
			prev = str.find_first_not_of(deli, found);
			found = str.find_first_of(deli, prev);
			++i;
		}
		catch (...)
		{
			throw ErrorDate::WRONG_DATE_FORMAT;
		}
	}
	if (i != 3) throw ErrorDate::WRONG_DATE_FORMAT; // Not enough data
	if ((year <= 0)
		|| (month <= 0 || month > 12)
		|| (day <= 0   || day > Date::getDaysInMonth(month, year)))
	{
		throw ErrorDate::WRONG_DATE_FORMAT;
	}
	return *this;
}

// input - output operator
std::ostream& operator<<(std::ostream& outDev, const Date& dt) {
	outDev << dt.day << '/' << dt.month << '/' << dt.year;
	return outDev;
}
std::istream& operator>>(std::istream& inDev, Date& dt) {
	std::string str;
	do {
		getline(inDev, str);
	} while (str.empty());
	try {
		dt.stoDate(str, "/ ");
	}
	catch (ErrorDate)
	{
		std::cout << "\n>> Error: WRONG DATE FORMAT..." << std::endl;
		std::cout << "Choose another date: "; std::cin >> dt;
	}
	return inDev;
}

void Date::save(std::ofstream& fout)
{
	fout << day << ' ' << month << ' ' << year;
}


//std::ofstream& operator>>(std::ofstream& outDev,const Date& dt)
//{
//	outDev << dt.day << ' ' << dt.month << ' ' << dt.year;
//	return outDev;
//}

void Date::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}