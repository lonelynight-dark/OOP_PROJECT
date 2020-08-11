#include "ListSale.h"
Date ListSale::stoDate(const string& line, const char* delimeter)
{
	Date date;
	int day, month, year, i;
	char* next_token = nullptr;
	char* chr = new char[line.length() + 1];
	char* token = strtok_s(chr, delimeter, &next_token);
	strcpy_s(chr, line.length() + 1, line.c_str());

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
bool ListSale::LoadDateSaleList(const string& source)
{
	ifstream fin(source);
	if (!fin.is_open()) return false;
	Date* date;
	string strDate;

	while (getline(fin, strDate))
	{
		try
		{
			date = nullptr;
			date = &ListSale::stoDate(strDate, " ");
			saleDate.push_back(date);
		}
		catch (int)
		{
			return false;
		}
	}

	fin.close();
	return true;
}
bool ListSale::AddSaleDate(Date* arg)
{
	for (Date* date : saleDate)
		if (date == arg)
			return false;
	saleDate.push_back(arg);
	return true;
}
bool ListSale::AddSaleData(Sale* sale)
{
	for (Sale* saleDate : SaleList)
		if (saleDate == sale)
			return false;
	SaleList.push_back(sale);
	return true;
}
bool ListSale::LoadDataSaleList()
{
	Sale* tmp;
	string strFile = "";

	for(Date* date : saleDate)
	{
		tmp = nullptr;
		strFile = to_string(date->getDay()) + to_string(date->getMonth()) + to_string(date->getYear());
		if (tmp->LoadSale(strFile) == false) return false;
		SaleList.push_back(tmp);
	}

	tmp = nullptr;
	return true;
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
Sale* ListSale::FindSale(const Date& arg)
{
	for (int i = 0; i < saleDate.size(); i++)
	{
		if (*saleDate[i] == arg)
		{
			return SaleList[i];
		}
	}
	return NULL;
}
bool ListSale::SaveDataSaleList()
{
	string source = "";
	for (int i = 0; i < SaleList.size(); i++)
	{
		source = ListSale::Datetostr(*saleDate[i]);
		if (SaleList[i]->SaveSale(source) == false) return false;
	}
	return true;
}
string ListSale::Datetostr(Date date)
{
	return to_string(date.getDay()) + "_" + to_string(date.getMonth()) + "_" + to_string(date.getYear());
}