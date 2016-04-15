#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		if (n % 2) cout << "Bob\n";
		else cout << "Alice\n";
	}
	return 0;
}