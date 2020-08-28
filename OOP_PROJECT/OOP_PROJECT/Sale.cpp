#include "Sale.h"
double Sale::Summary(const int& ID)
{
	double sum = 0;
	int count = Sale::numProduct(ID);
	double price = listSoldProduct.getPrice(ID);
	return count * price;
}
bool Sale::stoDate(const string& line, const char* delimeter)
{
	int day, month, year;
	char* chr = new char[line.length() + 1];
	strcpy_s(chr, line.length() + 1, line.c_str());
	char* next_token = nullptr;
	char* token = strtok_s(chr, delimeter, &next_token);
	int i = 0;
	if (token == NULL || token == " ")
	{
		token = NULL;
		return false;
	}
	while (token)
	{
		if (i == 0) day = stoi(token);
		if (i == 1) month = stoi(token);
		if (i == 2) year = stoi(token);
		++i;
		token = strtok_s(NULL, delimeter, &next_token);
	}
	saleDate.setDate(year, month, day);
	delete[] chr;
	return true;
}
bool Sale::LoadSale(const string& source)
{
	ifstream fin(source);
	if (!fin.is_open()) return false;
	string line;
	getline(fin, line);
	char delimeter[] = " ";

	Sale::stoDate(line, delimeter);
	listSoldProduct.loadList(fin);

	fin.close();
	return true;
}
double Sale::CalculateRevenue()
{
	return listSoldProduct.totalPrice();
}
int Sale::numProduct()
{
	return listSoldProduct.totalProducts();
}
void Sale::OutputSale()
{
	Sale::OutputDate();
	listSoldProduct.outputList();
}
void Sale::OutputDate()
{
	cout << "Date : Day/Month/Year" << endl;
	cout << saleDate<<endl;
}
int Sale::numProduct(const int& ID)
{
	return listSoldProduct.countProduct(ID);
}
int Sale::month_sale_date()
{
	return saleDate.getMonth();
}
int Sale::year_sale_date()
{
	return saleDate.getYear();
}
bool Sale::SaveSale(const string& source)
{
	ofstream out(source);
	if (!out.is_open()) return false;

	out << saleDate.getDay() << " " << saleDate.getMonth() << " " << saleDate.getYear() << endl;
	listSoldProduct.saveList(out);

	out.close();
	return true;
}
bool Sale::AddAtttributeSale(Product* product, int quantity)
{
	if (quantity <= 0) return false;
	for (int i = 0; i < quantity; i++)
	{
		listSoldProduct.addProduct(product[i]);
	}
	return true;
}

void Sale::AddAtttributeSale(ListProduct products)
{
	
		listSoldProduct.concat(products);
	
}
