//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long sum = a + b;
	bool flag = false;

	if (sum < 0) {
		sum = -sum;
		flag = true;
	} else if (sum == 0) {
		cout << '0' << endl;
	}

	string s = "";
	while (sum) {
	    s += ((sum % 10) + '0');
	    sum /= 10;
	}

	stack<char> num;
	for (int i = 0, len = s.size(); i < len; i++) {
		num.push(s[i]);
		if ((i + 1) % 3 == 0 && (i + 1) != len) num.push(',');
	}
	if (flag) cout << '-';
	while (!num.empty()) {
	    cout << num.top();
	    num.pop();
	}
	cout << endl;
	return 0;
}
