
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char str[9];
	cin >> str;
	int len = strlen(str);
	do {
		cout << str << endl;
	} while (next_permutation(str, str + len));
	return 0;
}
