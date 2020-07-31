#ifndef _LISTSALE_H_
#define _LISTSALE_H_
#include "Libary.h"
#include "Sale.h"
using namespace std;
class ListSale
{
private:
	vector<Sale> SaleList;
public:
	double SumRevenue();
	double MonthlyRevenue();
	double YearlyRevenue();
};

#endif // !_LISTSALE_H_