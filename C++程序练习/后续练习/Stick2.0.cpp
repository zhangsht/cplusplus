#include <iostream>
using namespace std;

int main() {
	int n;

	while (cin >> n && n) {
		int temp;
		int remain = 0;
		for(unsigned i = 0; i < n; ++i) {
			cin >> temp;
			remain ^= temp;
		}
		cout << remain << endl;
	}
	return 0;
}