#include "Interface.h"
using namespace std;
int main() {
	Company* company = new Company();
	std::string pathAccount = "Data/Account/";
	std::string space = "                            ";
	int nCommand = 5;
	Interface i;
	while (true)
	{

		i.ShowTitle(space);
		cout << "             Leave Empty Username And Press Enter To Get Out Of Program\n\n";
		string username, password;
		cout << "                 Username > ";
		getline(cin, username);
		if (username == "")
			return 0;
		cout << "                 Password > ";
		password = i.InputPassword();
		int resultLogin = i.Login(pathAccount, username, password, *company, space);
		if (resultLogin == 0) {
			cout << "Wrong username or password\nDo you want to try again?(Y/N) ";
			while (true)
			{
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					cin.ignore();
					break;
				}
				else if (ch == 'n' || ch == 'N')
					return 0;
				else
					cout << "Bad choice, try again\n";
			}
		}

	}
	// write something here...
	return 0;
}