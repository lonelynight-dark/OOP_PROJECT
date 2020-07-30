#ifndef _LISTPRODUCT_H_
#define _LISTPRODUCT_H_

#include "Product.h"
#include <vector>

class ListProduct
{
	vector<Product*> listProduct;
	Product* searchProduct(int ID);
public:
	ListProduct() {};
	~ListProduct();
	ListProduct(const ListProduct&);
	ListProduct& operator=(ListProduct);
	void addProduct(const Product&);
	int totalProducts();
	ListProduct getListOfExpiredProduct();
	void loadList(const string& sourceProducts);
	void inputList();
	void saveList(const string& sourceProducts);
	void outputList();
};

#endif // !_LISTPRODUCT_H_