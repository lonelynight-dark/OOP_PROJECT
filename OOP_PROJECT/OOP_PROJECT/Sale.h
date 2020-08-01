#ifndef _SALE_H_
#define _SALE_H_
#include "Date.h"
#include "ListProduct.h"
using namespace std;
class Sale
{
private :
	Date saleDate;
	ListProduct listSoldProduct;
public:
	Sale(){}
	~Sale(){}
	double Summary(const string&);
	bool stoDate(const string&, const string&, const char*);
	void LoadSale(const string&);
	double CalculateRevenue();
	int numProduct();
	int numProduct(const string&);
	void OutputSale();
	void OutputDate();
};

#endif // !_SALE_H_