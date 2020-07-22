#ifndef _LISTPRODUCT_H_
#define _LISTPRODUCT_H_

#include "Product.h"
#include <vector>

class ListProduct
{
	vector<Product*> listProduct;
	void loadData();
public:
	//ListProduct();
	~ListProduct();
	Product& searchProduct(string ID);
	int getTotalNumberOfProducts();
	ListProduct getListOfExpiredProduct();
	string showInfo();
};

#endif // !_LISTPRODUCT_H_