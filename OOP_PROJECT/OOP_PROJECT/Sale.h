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
	double Summary();
	double CalculateRevenue();
	int numProduct();
};

#endif // !_SALE_H_