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
	vector<Date*> saleDate;
public:
	ListSale()
	{
	}
	~ListSale() {
		for (Sale* sale : SaleList)
			delete sale;
		for (Date* date : saleDate)
			delete date;
	}
	// Single sale
	Sale& FindSale(const Date& arg);

	// Total Revenue
	double SumRevenue();

	// Revenue 
	double MonthlyRevenue(const int&, const int&);
	double YearlyRevenue(const int&);

	// Another method
	bool LoadDataSaleList();
	bool LoadDateSaleList(const string&);
	bool SaveDataSaleList();
	void OutputSaleList();
	Date stoDate(const string&, const char*);
	string Datetostr(Date);
};

#endif // !_LISTSALE_H_