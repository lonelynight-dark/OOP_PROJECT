#include "ListSale.h"
Date ListSale::stoDate(const string& line, const char* delimeter)
{
	Date date;
	int day, month, year;
	char* chr = new char[line.length() + 1];
	strcpy_s(chr, line.length() + 1, line.c_str());
	char* next_token = nullptr;
	char* token = strtok_s(chr, delimeter, &next_token);
	int i = 0;
	if (token == NULL || token == " ")
	{
		token = NULL;
		throw 505;
	}
	while (token)
	{
		if (i == 0) day = stoi(token);
		if (i == 1) month = stoi(token);
		if (i == 2) year = stoi(token);
		++i;
		token = strtok_s(NULL, delimeter, &next_token);
	}
	date.setDate(year, month, day);
	delete[] chr;
	return date;
}
void ListSale::LoadDateSaleList(const string& source)
{
	ifstream fin(source);
	if (!fin.is_open()) return;
	Date* date;
	string strDate;
	while (getline(fin, strDate))
	{
		date = nullptr;
		date = &ListSale::stoDate(strDate, " ");
		saleDate.push_back(date);
	}
	fin.close();
}
void ListSale::LoadDataSaleList()
{
	Sale* tmp;
	string strFile = "";
	for(Date* date : saleDate)
	{
		tmp = nullptr;
		strFile = to_string(date->getDay()) + to_string(date->getMonth()) + to_string(date->getYear());
		tmp->LoadSale(strFile);
		SaleList.push_back(tmp);
	}
	tmp = nullptr;
}
void ListSale::OutputSaleList()
{
	for (Sale* sale : SaleList)
		sale->OutputSale();
}
double ListSale::SumRevenue()
{
	double total = 0.0;
	for (Sale* sale : SaleList)
	{
		total += sale->CalculateRevenue();
	}
	return total;
}
double ListSale::MonthlyRevenue(const int& month, const int& year)
{
	double total = 0.0;
	for (Sale* sale : SaleList)
	{
		if (sale->month_sale_date() == month && sale->year_sale_date() == year)
		{
			total += sale->CalculateRevenue();
		}
	}
	return total;
}
double ListSale::YearlyRevenue(const int& year)
{
	double total = 0.0;
	for (Sale* sale : SaleList)
	{
		if (sale->year_sale_date() == year)
		{
			total += sale->CalculateRevenue();
		}
	}
	return total;
}