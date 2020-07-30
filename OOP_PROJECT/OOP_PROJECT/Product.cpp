#include "Product.h"

bool Product::isExpired()
{
	Date now(0);
	return now >= EXP;
}

Product::Product() : ID(0), stock(0), price(0), name("Unknown"), MFG(), EXP() {}

Product::Product(int id, string name, double price, int stock, Date MFG, Date EXP)
	: ID(id), name(name), price(price), stock(stock), MFG(MFG), EXP(EXP) {}

string Product::getName()
{
	return name;
}
double Product::getPrice() {
	return price;
}
int Product::getStock() {
	return stock;
}

void Product::load(ifstream& fin) {
	fin >> ID;
	fin.ignore();
	getline(fin, name);
	fin >> price >> stock >> MFG >> EXP;
	if (price < 0) price = 0;
	if (stock < 0) stock = 0;
	if (ID < 0) ID = 0;
	if (name == "") name = "Unknown";
	if (MFG < EXP) swap(MFG, EXP);
}

void Product::input()
{
	do {
		cout << "ID:    "; cin >> ID;
	} while (ID < 0);
	cin.ignore();
	do {
		cout << "Name:  ";  getline(cin, name);
	} while (name == "");
	do {
		cout << "Price: "; cin >> price;
	} while (price < 0);
	do {
		cout << "Stock: "; cin >> stock;
	} while (stock < 0);
	cout << "MFG:   "; cin >> MFG;
	do {
		cout << "EXP:   "; cin >> EXP;
		if (EXP < MFG) cout << ">> Error: EXP cannot be before the MFG...!" << endl;
	} while (EXP < MFG);
}
void Product::save(ofstream& fout) {
	fout << ID << endl;
	fout << name << endl;
	fout << price << endl;
	fout << stock << endl;
	fout << MFG << endl;
	fout << EXP << endl;
}
void Product::output()
{
	cout << "ID:    " << ID    << endl;
	cout << "Name:  " << name  << endl;
	cout << "Price: " << price << endl;
	cout << "Stock: " << stock << endl;
	cout << "MFG:   " << MFG   << endl;
	cout << "EXP:   " << EXP   << endl;
}