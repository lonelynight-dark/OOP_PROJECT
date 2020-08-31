#ifndef _SALE_H_
#define _SALE_H_
#include "Date.h"
#include "ListProduct.h"
using namespace std;
class Sale final
{
private :
	Date saleDate;
	ListProduct listSoldProduct;
public:
	Sale(){}
	Sale(Date a) { saleDate = a; }
	~Sale(){}

	// Calculate Money of chosen Product
	double Summary(const int&);

	// Calculate Sum all Revenue
	double CalculateRevenue();

	// Number of product
	int numProduct(); // Total Product
	int numProduct(const int&); // Num of chosen Product

	// Another method
	bool LoadSale(const string&, const string&);
	void OutputSale();
	int month_sale_date();
	int year_sale_date();
	void SaveSale(ofstream&);
	bool AddAtttributeSale(Product*, int);
	void AddAtttributeSale(ListProduct products);
	Date getDate();
private:
	void OutputDate();
	bool stoDate(const string&, const char*);
};

#endif // !_SALE_H_