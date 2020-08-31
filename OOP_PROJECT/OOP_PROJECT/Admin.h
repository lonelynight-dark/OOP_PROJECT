#pragma once
#ifndef _admin_h_
#define _admin_h_
#include "Staff.h"
#include "Account.h"
class Admin : public Staff {
public:
	void AddAccount(ofstream& out, string u, string p);
};
#endif // !_admin_h_
