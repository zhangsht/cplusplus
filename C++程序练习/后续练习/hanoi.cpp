#include <iostream>
using namespace std;

void hanoi(int a, int b, int c, int n) {
	if (n > 0) {
		hanoi(a, c, b, n - 1);
		cout << a << c << endl;
		hanoi(b, a, c, n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	hanoi(1, 2, 3, n);
	return 0;
}