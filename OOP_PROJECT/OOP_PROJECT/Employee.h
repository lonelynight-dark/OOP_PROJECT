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
		double viewSalary();// inherited from class Staff
		void viewAllProduct();// view all product in stock..
		void EnterProductInfo();// Enter product to stock..
		void exportInvoice();//export to text file(comming soon)
		Product searchProduct();//(comming soon)
		void viewTradeHistory(); // get data from listSale(comming soon)
		void sellProduct(); //(haven't managed trade history yet)
};

#endif