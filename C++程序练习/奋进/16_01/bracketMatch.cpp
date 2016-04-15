//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string express;
		char c;
		stack<char> v;
		cin >> express;

		int j = 0, len = express.size();
		for (; j < len; ++j) {
			c = express[j];
			if (c == '{' || c == '[' || c == '(') {
			    v.push(c);
			} else if (c == '}' || c == ']' || c == ')') {
				if (c - v.top() < 3 && !v.empty()) v.pop();
				else v.push(c);
			}
		}
		if (v.empty()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
