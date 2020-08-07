#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "Staff.h"
#include"ListProduct.h"
#include"ListSale.h"
class Employee :public Staff,public ListProduct
{
	private:
		double Salary;
		ListSale listSale;//used for trade history
		ListProduct stock;
		//other function
		bool is_number(const string& s);
		
		
	public:
		Employee();
		Employee(int _ID, string _name, bool _gender, string _phone, string _email, Date _yob, int _nDays);
		// inherited from class Staff..
		double viewSalary();

		// view all product in stock..
		void viewAllProducts();

		// Enter product to stock..
		void EnterProductInfo();

		//export to text file(comming soon)
		void exportInvoice();

		//(haven't tested)
		Product searchProductById(int _id);

		//(haven't tested)
		Product searchProductByName(string _name);

		
		void viewTradeHistory(); 

		//(haven't managed trade history yet)
		void sellProduct(); 
};

#endif