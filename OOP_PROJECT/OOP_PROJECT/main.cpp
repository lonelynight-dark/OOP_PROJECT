#include "Interface.h"
using namespace std;
int main() {
	std::string pathAccount = "data/Account/";
	std::string space = "                            ";
	int nCommand = 5;
	Interface i;
	while (true)
	{
		vector<Employee> emp;
		vector<Manager> mag;

		i.ShowTitle(space);
		cout << "             Leave Empty Username And Press Enter To Get Out Of Program\n\n";
		string username, password;
		cout << "                 Username > ";
		getline(cin, username);
		if (username == "")
			return 0;
		cout << "                 Password > ";


	}
	// write something here...
	return 0;
}