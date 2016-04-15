#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	int position;
	for (int i = 1; i <= n; i++) {
		cin >> position >> str;
		cout << i << ' ' << str.erase(position - 1, 1) << endl;
	}
}
