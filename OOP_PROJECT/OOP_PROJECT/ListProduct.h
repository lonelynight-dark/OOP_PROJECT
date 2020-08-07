#ifndef _LISTPRODUCT_H_
#define _LISTPRODUCT_H_

#include "Product.h"
#include <vector>

enum class ErrorCode {
	OK = 0,
	Unable_to_find,
	Not_enough_stock,
	Invalid_parameter
};

class ListProduct
{
	vector<Product*> listProduct;
public:
	// constructor & destructor
	ListProduct() {};
	ListProduct(const ListProduct&);
	~ListProduct();
	// operator
	ListProduct& operator=(ListProduct);
	// add & delete products /* be carefull here */	
	/*
		BEWARE OF INT (ERROR CODE) RETURN
		YOU SHOULD PUT "==0" IF THE FUNCTIONS BELOW IS IN THE IF CONDITION
	*/
	int addProduct(Product&) ;
	int deleteProduct(int ID); 
	int importProduct(int ID, int stock);
	int exportProduct(int ID, int stock);
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
	void loadList(const string& sourceProducts);
	void saveList(const string& sourceProducts);
	// other search function
	Product* searchProduct(int ID);
	Product* searchProduct(string name);
	//Product* searchProductByID(int _id);
	//Product* searchProductByName(string _name);
};

#endif // !_LISTPRODUCT_H_