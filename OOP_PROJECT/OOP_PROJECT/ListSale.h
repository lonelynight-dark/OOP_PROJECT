#ifndef _LISTSALE_H_
#define _LISTSALE_H_
#include "Libary.h"
#include "Sale.h"
#include "Date.h"
using namespace std;
class ListSale final
{
private:
	vector<Sale*> SaleList;
	vector<Date> saleDate;
public:
	ListSale(){}
	~ListSale() {
		for (Sale* sale : SaleList)
			delete sale;
	}
	// Single sale
	Sale* FindSale(const Date&);

	// Total Revenue
	double SumRevenue();

	// Revenue 
	double MonthlyRevenue(const int&, const int&);
	double YearlyRevenue(const int&);

	// Another method
	bool AddSaleDate(Date*);
	bool AddSaleData(Sale*);
	bool LoadDataSaleList(const int&);
	bool LoadDateSaleList(const string&);
	bool SaveDataSaleList();
	void OutputSaleList();
	Date stoDate(const string&, const char*);
	string Datetostr(Date);
};

#endif // !_LISTSALE_H_