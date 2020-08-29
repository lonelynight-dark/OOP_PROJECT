#include "Staff.h"

bool isAllNumber(string s);

Staff::Staff() : ID(0), name("Unknown"), gender(true), phoneNumber("0"),
	address("Unknown"), yob(0), absentDay(0) {}
Staff::Staff(int _ID, string _name, bool _gender, 
	string _phone, string _address, Date _yob, int _nDays) {
	ID = (_ID > 0) ? _ID : 0;
	name = (_name != "") ? _name : "Unknown";
	gender = _gender;
	phoneNumber = (isAllNumber(_phone)) ? _phone : "0";
	address = (_address != "") ? _address : "Unknown";
	Date now(0);
	yob = (_yob <= now) ? _yob : now;
	absentDay = (_nDays >= 0) ? _nDays : 0;
}
bool isAllNumber(string s) {
	for (auto ch : s) if (!isdigit(ch)) return false;
	return true;
}
void Staff::input() {
	do {
		cout << "ID            : "; cin >> ID;
	} while (ID < 0);
	cin.ignore(100,'\n');
	do {
		cout << "Name          : "; getline(cin, name);
	} while (name == "");
	Date now(0);
	do {
		cout << "Date of Birth : "; cin >> yob;
	} while (yob > now);
	string s;
	do {
		cout << "Gender        : "; getline(cin, s);
		gender = (s == "Male");
	} while (s != "Male" && s != "Female");
	do {
		cout << "Address       : "; getline(cin, address);
	} while (address == "");
	do {
		cout << "Phone Number  : "; getline(cin, phoneNumber);
	} while (!isAllNumber(phoneNumber));
	/*do {
		cout << "Absent day: "; cin >> absentDay;
	} while (absentDay < 0);*/
}
void Staff::output() {
	cout << "ID           : " << ID << endl;
	cout << "Name         : " << name << endl;
	cout << "DOB          : " << yob << endl;
	cout << "Gender       : " << ((gender) ? "Male" : "Female") << endl;
	cout << "Address      : " <<  address << endl;
	cout << "Phone Number : " << phoneNumber << endl;
	cout << "Absent day   : " << absentDay << endl;
}

void Staff::load(ifstream& fin)
{
	fin >> ID; fin.ignore(100,'\n');
	getline(fin,name);
	fin >> gender;
	fin >> phoneNumber;
	fin.ignore(100, '\n');
	getline(fin, address);
	fin >> yob >> absentDay;
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
	fout << gender << endl;
	fout << phoneNumber << endl;
	fout << address << endl;
	yob.save(fout); fout << endl;
	fout << absentDay << endl;
}

void Staff::edit()
{
	cout << "Current Info:" << endl;
	output();

	cout << "New Info:" << endl;
	input();
}

void Staff::change(int _ID, string _name, bool _gender, 
	string _phone, string _address, Date _yob, int _nDays)
{
	ID = (_ID > 0) ? _ID : 0;
	name = (_name != "") ? _name : "Unknown";
	gender = _gender;
	phoneNumber = (isAllNumber(_phone)) ? _phone : "0";
	address = (_address != "") ? _address : "Unknown";
	Date now(0);
	yob = (_yob <= now) ? _yob : now;
	absentDay = (_nDays >= 0) ? _nDays : 0;
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

ostream& operator<<(ostream& out ,const Staff& staff) 
{
	out << "ID: " << staff.ID << endl;
	out << "Name: " << staff.name << endl;
	out << "Gender: " << ((staff.gender) ? "Male" : "Female") << endl;
	out << "PhoneNumber: " << staff.phoneNumber << endl;
	out << "Address: " << staff.address << endl;
	out << "Year of Birth: " << staff.yob << endl;
	out << "Absent day: " << staff.absentDay << endl;
	return out;
}
