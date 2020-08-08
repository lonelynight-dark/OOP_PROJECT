#include "Account.h"

bool Account::isCorrect(std::string u, std::string p) {
	return username == u && password == p;
}
