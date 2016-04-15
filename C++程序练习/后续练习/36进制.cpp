#include <iostream>
#include <vector>
#include <string>
using namespace std;

int change(string& str, int m) {
	int result = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] <= '9') result = result * m + str[i] - '0';
		else result = result * m + str[i] - 'A' + 10;
	}
	return result;
}

string changToM(int sum, int m) {
	string ans = "";
	vector<char> v;
	string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (sum == 0) return "0";
	while (sum) {
		v.push_back(str[sum % m]);
		sum /= m;
	}
	for (int i = v.size() - 1; i >= 0; i--) ans += v[i];
	return ans;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int m;
		cin >> m;
		string a, b;
		cin >> a >> b;
		int dividend = change(a, m), divisor = change(b, m);
		int quotient = dividend / divisor, remaind = dividend % divisor;

		cout << changToM(quotient, m) << endl << changToM(remaind, m) << endl;
	}
	return 0;
}
