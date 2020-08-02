#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "ListProduct.h"
#include "Staff.h"
#include <string>
#include <vector>
using namespace std;

class Company
{
	string name;
	string address;
	vector<Staff*> listStaff;
	ListProduct listProduct;
public:
	Company(){}
	~Company()
	{
		int n = listStaff.size();
		for (Staff* staff : listStaff) delete staff;
	}
	string getInfo();
};

#endif // !_COMPANY_H_
