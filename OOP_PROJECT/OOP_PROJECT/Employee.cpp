#include "Employee.h"
Employee::Employee() :Staff()
{

	ifstream fin("Stock.txt");
	stock.loadList(fin);
}
Employee::Employee(int _ID, string _name, bool _gender, string _phone, string _email, Date _yob, int _nDays):Staff( _ID,  _name,  _gender,  _phone,  _email,  _yob,  _nDays)
{
	ifstream fin("Stock.txt");
	stock.loadList(fin);
}
double Employee::viewSalary()
{
	cout << "Name:" << Staff::getName() << endl;
	cout << "ID:" << Staff::getID() << endl;
	
	double s = 5000000 - Staff::getAbsentDays() * 1000000;
	cout << std::setprecision(3) << std::showpoint << std::fixed;
	cout << "Salary:" << (s < 0 ? 0 : s) << endl;
	return (s<0?0:s);
	
}

void Employee::viewAllProducts()
{
	ifstream fin("Stock.txt");
	stock.loadList(fin);
	stock.outputList();
}

void Employee::EnterProductInfo()
{
	cout << "Enter product info :\n";
	Product tmp;
	tmp.input();
	stock.addProduct(tmp);
	ofstream fout("Stock.txt");
	stock.saveList(fout);
	
}

void Employee::exportInvoice(ListProduct soldProduct)
{
	cout << "***STAFF INFO***\n";
	Staff::output();
	cout << endl;
	cout << "***BILL***\n";
	soldProduct.outputList();
	cout << "================================\n";
	cout << "TOTAL:" << soldProduct.totalPrice()<<endl;

}

Product Employee::searchProductById(int _id)
{
	Product* result = stock.searchProduct(_id);
	if (result == nullptr)
		cout << "Not Found!\n";
	return *result;
}

Product Employee::searchProductByName(string _name)
{
	Product* result = stock.searchProduct( _name);
	if (result == nullptr)
		cout << "Not Found!\n";
	return *result;
}

void Employee::viewTradeHistory()
{
	cout << "**********TRADE HISTORY**********\n";
	listSale.LoadDateSaleList("ID_1.txt");
	listSale.LoadDataSaleList();
	listSale.OutputSaleList();
}

void Employee::sellProduct()
{
	//system("CLS");
	char ch;
	ListProduct soldProducts;
	cout << "**********SELL PRODUCT**********\n";
	do
	{
		
		cout << "Enter product:\n";
		cout << "ID:";
		string tmpID;
		getline(cin, tmpID);
		
		if (!is_number(tmpID))
		{
			do
			{
				cout << "ID must be a number!\n";
				getline(cin, tmpID);
			} while (is_number(tmpID));
		}

		cout << "Quantity:";
		string tmpQuantity;
		getline(cin, tmpQuantity);
		if (!is_number(tmpQuantity))
		{
			do
			{
				cout << "Quantity must be a number!\n";
				getline(cin, tmpQuantity);
			} 
			while (is_number(tmpQuantity));
		}
		
		Product* soldProduct = stock.searchProduct(stoi(tmpID));
		if (stock.searchProduct(stoi(tmpID)) == nullptr)
		{
			cout << "Product:ID " << tmpID << " are out of Stock";
			system("pause");
			continue;
		}
		Product* tmpProduct =new Product(*soldProduct);
		(*tmpProduct) -= ((*soldProduct).getStock() - stoi(tmpQuantity));
		soldProducts.addProduct(*tmpProduct);

		*soldProduct -= stoi(tmpQuantity);

		cout << "More product ?\nPress y - Yes \nPress any else key - No\n";
		
		cin >> ch;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (ch == 'y');

	listSale.LoadDateSaleList("Data\Sale\ID_1.txt");
	listSale.LoadDataSaleList();
	Date* today=new Date;
	Sale* todaySale = nullptr;
	
	todaySale = listSale.FindSale(today->now());

	//if not exit create a new one
	if (todaySale == nullptr)
	{
		listSale.AddSaleDate(today);
		todaySale = new Sale(*today);
	}
	todaySale->AddAtttributeSale(soldProducts);
	listSale.AddSaleData(todaySale);
	listSale.SaveDataSaleList();

	ofstream fout("Stock.txt");
	stock.saveList(fout);

	exportInvoice(soldProducts);

}


bool Employee::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	++it;
	return !s.empty() && it == s.end();
}