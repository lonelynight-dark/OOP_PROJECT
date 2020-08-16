#include "ListProduct.h"
#include "Libary.h"

ListProduct::~ListProduct()
{
	for (auto& x : listProduct)
		if (x)
			delete x;
}

ListProduct::ListProduct(const ListProduct& list)
{
	for (Product* product : list.listProduct)
		addProduct(*product);
}

ListProduct& ListProduct::operator=(ListProduct list)
{
	swap(listProduct, list.listProduct);
	return *this;
}

void ListProduct::addProduct(Product& product)
{
	if (!searchProduct(product.getID()))
	{
		listProduct.push_back(new Product(product));
	}
	else
	{
		throw ErrorCode::ID_existed;
	}
}

void ListProduct::deleteProduct(int ID)
{
	for (vector<Product*>::iterator x = listProduct.begin(); x != listProduct.end(); ++x)
	{
		if ((*x)->getID() == ID)
		{
			delete* x; *x = nullptr;
			listProduct.erase(x);
			return;
		}
	}
}

void ListProduct::importProduct(int ID, int stock)
{
	if (stock < 0 || ID < 0) return;
	Product* p = searchProduct(ID);
	if (p)
		*p += stock;
}

void ListProduct::exportProduct(int ID, int stock)
{
	if (stock < 0 || ID < 0) return;
	Product* p = searchProduct(ID);
	if (p)
	{
		if (p->getStock() < stock)
			throw ErrorCode::Not_enough_stock;
		*p -= stock;
	}
}

Product* ListProduct::searchProduct(int ID)
{
	if (ID < 0)
		return nullptr;
	for (Product*& product : listProduct)
		if (product->getID() == ID)
			return product;
	return nullptr;
}

Product* ListProduct::searchProduct(string name)
{
	for (Product*& product : listProduct)
		if (product->getName() == name)
			return product;
	return nullptr;
}

int ListProduct::size()
{
	return listProduct.size();
}

int ListProduct::totalProducts()
{
	int n = 0;
	for (auto& product : listProduct)
		n += product->getStock();
	return n;
}

int ListProduct::countProduct(int ID)
{
	return searchProduct(ID)->getStock();
}

ListProduct& ListProduct::getListOfExpiredProduct()
{
	ListProduct* list = new ListProduct;
	for (auto& product : listProduct)
		if (product->isExpired())
			list->addProduct(*product);
	return *list;
}

ListProduct& ListProduct::getListOfZeroStock()
{
	ListProduct* list = new ListProduct;
	for (auto& product : listProduct)
		if (product->getStock() == 0)
			list->addProduct(*product);
	return *list;
}

double ListProduct::getPrice(int ID)
{
	Product* p = searchProduct(ID);
	return (p) ? p->getPrice() : -1;
}

double ListProduct::totalPrice()
{
	double total = 0.0;
	for (auto& product : listProduct)
		total += product->getStock() * product->getPrice();
	return total;
}

void ListProduct::outputList()
{
	int n = listProduct.size();
	cout << "Number of type of products: " << n << endl;
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "Product " << i + 1 << " :" << endl;
		listProduct[i]->output();
	}
}

void ListProduct::loadList(ifstream& fin)
{
	int n;
	fin >> n;
	Product p;
	for (int i = 0; i < n; ++i)
	{
		p.load(fin);
		try {
			this->addProduct(p);
		}
		catch (ErrorCode) {
			cout << "ID (" << p.getID() << ") existed..." << endl;
		}
	}
}

void ListProduct::inputList()
{
	int n;
	Product p;
	cout << "Number of type of products: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Product " << i + 1 << " :" << endl;
		p.input();
		try {
			this->addProduct(p);
		}
		catch (ErrorCode) {
			cout << "ID (" << p.getID() << ") existed..." << endl;
		}
	}
}

void ListProduct::saveList(ofstream& fout)
{
	fout << listProduct.size() << endl;
	for (Product*& product : listProduct)
		product->save(fout);
}

void ListProduct::concat(const ListProduct& list)
{
	for (auto& product : list.listProduct) {
		try {
			addProduct(*product);
		}
		catch (ErrorCode) {
			cout << "ID (" << product->getID() << ") existed..." << endl;
		}
	}
}