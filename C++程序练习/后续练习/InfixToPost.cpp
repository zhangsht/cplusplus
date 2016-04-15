#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cctype>
using namespace std;

int main() {
	map<char, int> myMap;
	myMap['+'] = myMap['-'] = 1;
	myMap['*'] = myMap['/'] = myMap['%'] = 2;

	string infixExp, postfixExp = "";
	stack<char> myStack;

	cin >> infixExp;
	int lenth = infixExp.size();

	for (int i = 0; i < lenth; i++) {
		char c = infixExp[i];
		if (isalpha(c)) {
			postfixExp += c;
		} else {
			if (myStack.empty()) myStack.push(c);
			else if (myMap[c] > myMap[myStack.top()]) myStack.push(c);
			else {
				while (!myStack.empty() && (myMap[c] <= myMap[myStack.top()])) {
					postfixExp += myStack.top();
					myStack.pop();
				}
				myStack.push(c);
			}

		}
	}
	while (!myStack.empty()) {
		postfixExp += myStack.top();
		myStack.pop();
	}
	cout << postfixExp;
	return 0;
}
