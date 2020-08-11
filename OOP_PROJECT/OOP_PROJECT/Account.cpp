#include "Account.h"

bool Account::isCorrect(std::string u, std::string p) {
	return username == u && password == p;
}

Account::Account(std::string u, std::string p) {
	username = u;
	password = p;
}