#include "Employee.h"
Employee::Employee() :Staff()
{

}
Employee::Employee(int _ID, string _name, bool _gender, string _phone, string _email, Date _yob, int _nDays):Employee( _ID,  _name,  _gender,  _phone,  _email,  _yob,  _nDays)
{
}
double Employee::viewSalary()
{
	double s = 5000000 - Staff::getAbsentDays() * 1000000;
	return (s<0?0:s);
	
}

void Employee::viewAllProducts()
{
	stock.outputList();
}

void Employee::EnterProductInfo()
{
	cout << "Enter product info :\n";
	Product tmp;
	tmp.input();
	stock.addProduct(tmp);

	
}

void Employee::exportInvoice()
{
	
}

Product Employee::searchProductById(int _id)
{
	Product* result = stock.searchProductByID(_id);
	if (result == nullptr)
		cout << "Not Found!\n";
	return *result;
}

Product Employee::searchProductByName(string _name)
{
	Product* result = stock.searchProductByName( _name);
	if (result == nullptr)
		cout << "Not Found!\n";
	return *result;
}

void Employee::viewTradeHistory()
{
	listSale.OutputSaleList();
}

void Employee::sellProduct()
{
	cout << "**********SELL PRODUCT**********\n";
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
		} while (is_number(tmpQuantity));
	}
	Product* soldProducts = stock.searchProductByID(stoi(tmpID));
	if (stock.searchProductByID(stoi(tmpID)) == nullptr)
	{
		cout << "Product:ID " << tmpID << " are out of Stock";
		system("pause");
		return;
	}

	soldProducts -= stoi(tmpQuantity);

	//stock.deleteProduct(stoi(tmpID));

	listSale.LoadDateSaleList("DateFile.txt");
	listSale.LoadDataSaleList();
	Date today;

	Sale todaySale=listSale.FindSale(today.now());//if not exit create a new one

	//Today.AddAtttributeSale(Product* soldProducts,int quantity);
	//listSale.add(todaySale);

	listSale.SaveDataSaleList();


}


bool Employee::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	++it;
	return !s.empty() && it == s.end();
}