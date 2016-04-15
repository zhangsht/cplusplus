#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int sum = 1;
	for (int i = 0; i < b; i++) {
		sum *= (a % c);
		sum %= c;
	}
	cout << sum << endl;
	return 0;
}