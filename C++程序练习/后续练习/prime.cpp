#include <iostream>
#include <cmath>
using namespace std;
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	int m = 0, x = 2;
	while (m != n) {
		if (prime(x++)) m++;
	}
	cout << x - 1 <<  endl;
	return 0;
}
