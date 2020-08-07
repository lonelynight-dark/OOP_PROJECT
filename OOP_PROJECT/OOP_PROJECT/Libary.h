#ifndef _LIBARY_H_
#define _LIBARY_H_
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <algorithm>

std::string toUpper(std::string s) { for (char& ch : s) ch = toupper(ch); return s; }

//bool accept(string question) {
//	string answer;
//	do {
//		std::cout << question << "(YES/NO): "; cin >> answer;
//		answer = toUpper(answer);
//	} while (answer == "YES" || answer == "NO");
//	return answer == "YES";
//}

#endif // !_LIBARY_H_
