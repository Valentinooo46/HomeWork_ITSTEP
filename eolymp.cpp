#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include<string>
#include<stack>
using namespace std;



string isCorrect(const string& s) {
	stack<char> Stack;
	string errorPosition = "";
	for (size_t i = 0; i < s.size(); ++i) {
		char ch = s[i];
		if (ch == '(' || ch == '{' || ch == '[') {
			Stack.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']') {
			if (Stack.empty() || (ch == ')' && Stack.top() != '(') ||
				(ch == '}' && Stack.top() != '{') ||
				(ch == ']' && Stack.top() != '[')) {
				errorPosition = s.substr(0, i + 1);
				return errorPosition;
			}
			Stack.pop();
		}
		else if (ch == ';') {
			break;
		}
	}
	if (!Stack.empty()) {
		errorPosition = s.substr(0, s.size());
		return errorPosition;
	}
	return errorPosition;
}


int main() {

	srand(time(0));
	string a1 = "({)1234(";
	string a2 = isCorrect(a1);
	if (a2 == "")
	{
		cout << "correct" << endl;
	}
	else {
		cout << "incorrect" << endl << a2 << endl;
	}

}

