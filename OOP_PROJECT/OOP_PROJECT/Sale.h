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

	// Calculate Summary of Product
	double Summary(const int&);

	// Calculate Total Revenue
	double CalculateRevenue();

	// Number of product
	int numProduct();
	int numProduct(const int&);

	// Another method
	bool LoadSale(const string&);
	void OutputSale();
	int month_sale_date();
	int year_sale_date();
	bool SaveSale(const string&);
	bool AddAtttributeSale(Product*, int);
	bool AddAtttributeSale(ListProduct products);
private:
	void OutputDate();
	bool stoDate(const string&, const char*);
};

#endif // !_SALE_H_