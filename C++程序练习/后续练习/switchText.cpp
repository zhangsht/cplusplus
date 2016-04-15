#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check(const string &str) {
	int len = str.size();
	if (len == 0) return false;
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') return true;
	}
	return false;
}

int main() {
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		if (check(str2)) {
			string s1, s2;
			int len = str2.size();
			reverse(str2.begin(), str2.end());
			s1.append(str2.begin(), str2.begin() + len / 2);
			s2.append(str2.begin() + len / 2, str2.end());
			cout << s2 << s1 << endl;
		}
		if (check(str1)) {
			string s1, s2;
			int len = str1.size();
			reverse(str1.begin(), str1.end());
			s1.append(str1.begin(), str1.begin() + len / 2);
			s2.append(str1.begin() + len / 2, str1.end());
			cout << s2 << s1 << endl;
		}
		str1.clear(), str2.clear();
	}
	return 0;
}
