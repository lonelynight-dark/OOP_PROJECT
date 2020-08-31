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
	cout << std::setprecision(0) << std::showpoint << std::fixed;
	cout << "Salary:" << (s < 0 ? 0 : s) << endl;
	return (s<0?0:s);
	
}

void Employee::viewAllProducts()
{
	/*ifstream fin("Stock.txt");*/
	/*stock.loadList(fin);*/
	stock.outputList();
}

void Employee::EnterProductInfo()
{
	cout << "Enter product info :\n";
	Product tmp;
	tmp.input();
	ListProduct tmpList;
	tmpList.addProduct(tmp);

	stock.concat(tmpList);

	ofstream fout("Stock.txt");
	stock.saveList(fout);
	
}

void Employee::DeleteProduct(int _id)
{
	stock.deleteProduct(_id);
	ofstream fout("Stock.txt");
	stock.saveList(fout);
}

void Employee::exportInvoice(ListProduct soldProduct)
{
	cout << "*** STAFF INFO ***\n";
	Staff::output();
	cout << endl;
	cout << "*** BILL ***\n";
	soldProduct.outputList();
	cout << "================================\n";
	cout << "TOTAL:" << soldProduct.totalPrice()<<endl;

}

Product* Employee::searchProductById(int _id)
{
	Product* result = stock.searchProduct(_id);
	if (result == nullptr)
		return nullptr;
	return result;
}

Product* Employee::searchProductByName(string _name)
{
	Product* result = stock.searchProduct( _name);
	if (result == nullptr)
		return nullptr;
	return result;
}

void Employee::viewTradeHistory()
{
	cout << "**********TRADE HISTORY**********\n\n";

	listSale.LoadDateSaleList(".\\Data\\Sale\\" +to_string(this->getID()) + ".txt");
	listSale.LoadDataSaleList(this->getID(),".\\Data\\Sale\\");
	listSale.OutputSaleList();
}

void Employee::sellProduct()
{
	cin.clear();
	cin.ignore(1);
	char ch='y';
	ListProduct soldProducts;
	do
	{
	system("CLS");
	cout << "**********SELL PRODUCT**********\n\n";
		
		cout << "Enter product:\n";
		cout << "ID:";
		string tmpID;
		getline(cin, tmpID);
		
		if (!is_number(tmpID))
		{
			
			do
			{
				
				cout << "ID must be a number!\n";
				cout << "Please enter again:";
				getline(cin, tmpID);
				
			} while (!is_number(tmpID));
		}

		cout << "Quantity:";
		string tmpQuantity;
		getline(cin, tmpQuantity);
		if (!is_number(tmpQuantity))
		{
			
			do
			{
				
				cout << "Quantity must be a number!\n";
				cout << "Please enter again:";
				getline(cin, tmpQuantity);
				
			} 
			while (!is_number(tmpQuantity));
		}
		

		Product* ProductInStock = stock.searchProduct(stoi(tmpID));
		if (ProductInStock == nullptr||ProductInStock->getStock()<stoi(tmpQuantity))
		{
			cout << "Product " << tmpID << " are out of Stock\n";
			cout << "Please enter again!\n";
			system("pause");
			continue;
		}
		Product* tmpProduct =new Product(*ProductInStock);
		(*tmpProduct) -= ((*ProductInStock).getStock() - stoi(tmpQuantity));
		
		soldProducts.addProduct(*tmpProduct);

		*ProductInStock -= stoi(tmpQuantity);

		cout << "More product ?\nPress y - Yes \nPress any else key - No\n";
		
		cin >> ch;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (ch == 'y');

	listSale.LoadDateSaleList(".\\Data\\Sale\\" + to_string(this->getID()) + ".txt");
	listSale.LoadDataSaleList(this->getID(),".\\Data\\Sale\\");
	Date* today=new Date;
	Sale* todaySale = nullptr;
	
	todaySale = listSale.FindSale(today->now());

	//if not exit create a new one
	if (todaySale == nullptr)
	{
		listSale.AddSaleDate(today);
		todaySale = new Sale(*today);
	}
	todaySale->AddAtttributeSale(soldProducts);///soldProdcut is ListProduct obj
	listSale.AddSaleData(todaySale);
	listSale.SaveDateSaleList(this->getID(), ".\\Data\\Sale\\");
	listSale.SaveDataSaleList(this->getID(), ".\\Data\\Sale\\");
	ofstream fout("Stock.txt");
	stock.saveList(fout);

	
	system("CLS");
	cout << "********** INVOICE **********\n\n";
	
	exportInvoice(soldProducts);

}


bool Employee::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	++it;
	return !s.empty() && it == s.end();
}

void Employee::displayExpiredProduct()
{
	ListProduct listExpiredProduct=stock.getListOfExpiredProduct();
	listExpiredProduct.outputList();
}

void Employee::displayEmptyProduct()
{
	ListProduct listEmptyProduct = stock.getListOfZeroStock();
	listEmptyProduct.outputList();
}
