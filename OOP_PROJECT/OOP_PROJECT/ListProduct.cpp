#include "ListProduct.h"

ListProduct::~ListProduct()
{
	int n = listProduct.size();
	for (int i = 0; i < n; ++i) delete listProduct[i];
}
