#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "Date.h"
#include <string>
using namespace std;

class Product
{
	string ID;
	string name;
	double price;
	int stock;
	Date expiredDate;
public: 
	bool isExpired();
	string getName();
	double getPrice();
	int getStock();
	string showInfo();
};

#endif // !_PRODUCT_H_