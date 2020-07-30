#include "ListProduct.h"

ListProduct::~ListProduct()
{
	for (auto& x : listProduct) if (x) delete x;
}

ListProduct::ListProduct(const ListProduct& list) 
{
	for (Product* product : list.listProduct) addProduct(*product);
}

ListProduct& ListProduct::operator=(ListProduct list)
{
	swap(listProduct, list.listProduct);
}

void ListProduct::addProduct(const Product& product)
{
	listProduct.push_back(new Product(product));
}

Product* ListProduct::searchProduct(int ID)
{
	if (ID < 0) return nullptr;
	for (Product*& product : listProduct) 
		if (product->getID() == ID) return product;
	return nullptr;
}
int ListProduct::totalProducts() {
	return listProduct.size();
}
ListProduct ListProduct::getListOfExpiredProduct()
{
	ListProduct list;
	for (auto& product : listProduct) 
		if (product->isExpired()) list.addProduct(*product);
	return list;
}
void ListProduct::outputList() {
	int n = totalProducts();
	cout << "Number of type of products: " << n << endl;
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << "Product " << i + 1 << " :" << endl;
		listProduct[i]->output();
	}
}
void ListProduct::loadList(const string& sourceProducts){
	ifstream fin(sourceProducts);
	int n;
	fin >> n;
	Product* p;
	for (int i = 0; i < n; ++i) {
		p = new Product;
		p->load(fin);
		listProduct.push_back(p);
	}
	fin.close();
}
void ListProduct::inputList() {
	int n; Product* p;
	cout << "Number of type of products: "; cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << "Product " << i + 1 << " :" << endl;
		p = new Product;
		p->input();
		listProduct.push_back(p);
	}
}
void ListProduct::saveList(const string& sourceProducts) {
	ofstream fout(sourceProducts);
	fout << listProduct.size();
	for (Product*& product : listProduct) product->save(fout);
	fout.close();
}