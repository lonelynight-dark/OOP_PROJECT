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
	ListSale(){}
	~ListSale() {}
	double SumRevenue();
	double MonthlyRevenue(const int&, const int&);
	double YearlyRevenue(const int&);
};

#endif // !_LISTSALE_H_