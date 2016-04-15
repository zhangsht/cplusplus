//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <string>
using namespace std;

bool is_find(char c, string& s) {
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == c) {
			s.erase(i, 1);
			return true;
		}
	}
	return false;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	int cnt = 0;
	for (int i = 0; i < len2; i++) {
		if (is_find(s2[i], s1))
			cnt++;
	}
	if (cnt == len2) cout << "Yes " << len1 - len2 << endl;
	else cout << "No " << len2 - cnt << endl;
	return 0;
}
