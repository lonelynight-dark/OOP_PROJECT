#include "Employee.h"
Employee::Employee() :Staff()
{

}
Employee::Employee(int _ID, string _name, bool _gender, string _phone, string _email, Date _yob, int _nDays):Employee( _ID,  _name,  _gender,  _phone,  _email,  _yob,  _nDays)
{
}
double Employee::viewSalary()
{
	// insert info about salary of employee
	return 0;
}

void Employee::viewAllProduct()
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

void Employee::viewTradeHistory()
{
	listSale.OutputSaleList();
}

void Employee::sellProduct()
{
	cout << "**********SELL PRODUCT**********\n";
	cout << "Enter product info:\n";
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
	stock.deleteProduct(stoi(tmpID));
	

}


bool Employee::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	++it;
	return !s.empty() && it == s.end();
}