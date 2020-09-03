#include "Admin.h"

void Admin::AddAccount(ofstream& out, string u, string p) {
	Account* acc = new Account(u, p, false);
	acc->savetoFile(out);
}