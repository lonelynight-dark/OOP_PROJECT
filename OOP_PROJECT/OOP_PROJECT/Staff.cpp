#include "Staff.h"

Staff::Staff() : ID(0), name("Unknown"), gender(true), phoneNumber("0"), 
	emailAddress("Unknown"),yob(0), absentDay(0) {}
Staff::Staff(int _ID, string _name, bool _gender, string _phone, string _email, Date _yob, int _nDays) {
	ID = (_ID > 0) ? _ID : 0;
	name = (_name != "") ? _name : "Unknown";
	gender = _gender;
	phoneNumber = (isAllNumber(_phone)) ? _phone : "0";
	emailAddress = (_email != "") ? _email : "Unknown";
	Date now(0);
	yob = (_yob <= now) ? _yob : now;
	absentDay = (_nDays >= 0) ? _nDays : 0;
}
Staff::~Staff() {};
static bool isAllNumber(string s) {
	for (auto ch : s) if (!isdigit(ch)) return false;
	return true;
}
void Staff::input() {
	do {
		cout << "ID: "; cin >> ID;
	} while (ID < 0);
	cin.ignore();
	do {
		cout << "Name: "; getline(cin, name);
	} while (name == "");
	string s;
	do {
		cout << "Gender(Male/Female): "; getline(cin, s);
		gender = (s == "Male");
	} while (s != "Male" && s != "Female");
	do {
		cout << "PhoneNumber: "; getline(cin, phoneNumber);
	} while (!isAllNumber(phoneNumber));
	do {
		cout << "Email Address: "; getline(cin, name);
	} while (emailAddress == "");
	Date now(0);
	do {
		cout << "Year of Birth: "; cin >> yob;
	} while (yob > now);
	do {
		cout << "Absent day: "; cin >> absentDay;
	} while (absentDay < 0);
}
void Staff::output() {
	cout << "ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " << ((gender) ? "Male" : "Female") << endl;
	cout << "PhoneNumber: " << phoneNumber << endl;
	cout << "Email Address: " <<  emailAddress << endl;
	cout << "Year of Birth: " << yob << endl;
	cout << "Absent day: " << absentDay << endl;
}

void Staff::load(ifstream& fin)
{
	fin >> ID; fin.ignore();
	fin >> name >> gender; fin.ignore();
	fin >> phoneNumber >> emailAddress >> yob >> absentDay;
	if (ID < 0) ID = 0;
	Date now(0);
	if (yob > now) yob = now;
	if (!isAllNumber(phoneNumber)) phoneNumber = "0";
	if (absentDay < 0) absentDay = 0;
}

void Staff::save(ofstream& fout)
{
	fout << ID << endl;
	fout << name << endl;
	fout << ((gender) ? "Male" : "Female") << endl;
	fout << phoneNumber << endl;
	fout << emailAddress << endl;
	fout << yob << endl;
	fout << absentDay << endl;
}

int Staff::getID()
{
	return ID;
}

string Staff::getName()
{
	return name;
}

int Staff::getAbsentDays()
{
	return absentDay;
}
