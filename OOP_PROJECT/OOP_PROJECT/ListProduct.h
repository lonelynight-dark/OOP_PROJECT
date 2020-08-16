#ifndef _LISTPRODUCT_H_
#define _LISTPRODUCT_H_

#include "Product.h"
#include <vector>

enum class ErrorCode {
	Unable_to_find = -200,
	Not_enough_stock,
	Wrong_format,
	ID_existed
};

class ListProduct
{
private:
	vector<Product*> listProduct;
public:
	// constructor & destructor
	ListProduct() {};
	ListProduct(const ListProduct&);
	~ListProduct();
	// operator
	ListProduct& operator=(ListProduct);
	// add & delete products 
	void addProduct(Product&) ; // throw ErrorCode::ID_existed if ID already existed
	void deleteProduct(int ID); 
	void importProduct(int ID, int stock);
	void exportProduct(int ID, int stock); // might throw ErrorCode::Not_enough_stock 
	// count methods
	int size(); // return number of type of products 
	int totalProducts();  // return sum of all stocks of products
	int countProduct(int ID); // return stock of product
	// get ListProduct 
	ListProduct& getListOfExpiredProduct();
	ListProduct& getListOfZeroStock();
	// calculate methods
	double getPrice(int ID);
	double totalPrice();
	// input & output methods
	void inputList();
	void outputList();
	void loadList(ifstream&);
	void saveList(ofstream&);
	// other search function
	Product* searchProduct(int ID);
	Product* searchProduct(string name);
	// concat 2 List Product
	void concat(const ListProduct&);
};

#endif // !_LISTPRODUCT_H_