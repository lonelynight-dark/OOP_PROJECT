#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "Date.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product
{
	int ID;
	string name;
	double price;
	int stock;
	Date MFG;
	Date EXP;
public: 
	Product();
	Product(int id, string name, double price, int stock, Date MFG, Date EXP);

	// getter
	int getID();
	string getName();
	double getPrice();
	int getStock();
	// input
	void load(ifstream& fin);
	void input();
	// output
	void save(ofstream& fout);
	void output();
	// other methods
	bool isExpired();
};

#endif // !_PRODUCT_H_