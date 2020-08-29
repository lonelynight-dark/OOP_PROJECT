#include "ListSale.h"
Date ListSale::stoDate(const string& line, const char* delimeter)
{
	Date date;
	int day, month, year, i=0;
	char* next_token = nullptr;
	char* chr = new char[line.length() + 1];
	strcpy_s(chr, line.length() + 1, line.c_str());
	char* token = strtok_s(chr, delimeter, &next_token);

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
	Date date;
	string strDate;

	while (getline(fin, strDate))
	{
		try
		{
			date = ListSale::stoDate(strDate, " ");
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
	for (Date date : saleDate)
		if (date == *arg)
			return false;
	saleDate.push_back(*arg);
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
bool ListSale::LoadDataSaleList(const int& ID, const string& path)
{
	Sale* tmp;
	string strFile = "";

	for(Date date : saleDate)
	{
		tmp = nullptr;
		tmp = new Sale;
		strFile = to_string(ID) + "_" + to_string(date.getDay()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getYear()) + ".txt";
		if (tmp->LoadSale(strFile, path) == false) return false;
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
		if (saleDate[i] == arg)
		{
			return SaleList[i];
		}
	}
	return NULL;
}
bool ListSale::SaveDataSaleList(const int& ID, const string& base)
{
	string source = "";
	ofstream out;

	for (int i = 0; i < SaleList.size(); i++)
	{
		source = Datetostr1(saleDate[i]);
		out.open(base + to_string(ID) + "_" + source + ".txt");
		SaleList[i]->SaveSale(out);
		out.close();
	}

	return true;
}
bool ListSale::SaveDateSaleList(const int& ID, const string& base)
{
	ofstream out;
	string path = base + to_string(ID) + ".txt";
	out.open(path);
	if (!out.is_open()) return false;
	string date;
	
	for (int i = 0; i < saleDate.size(); i++)
	{
		date = Datetostr2(saleDate[i]);
		out << date << endl;
	}

	out.close();
	return true;
}
string ListSale::Datetostr1(Date date)
{
	return to_string(date.getDay()) + "-" + to_string(date.getMonth()) + "-" + to_string(date.getYear());
}

string ListSale::Datetostr2(Date date)
{
	return to_string(date.getDay()) + " " + to_string(date.getMonth()) + " " + to_string(date.getYear());
}
