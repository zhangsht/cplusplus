#include <iostream>
using namespace std;

int main() {
	int p, q;
	int a[6000], b[6000];
	cin >> p >> q;

	int Max = p > q ? p : q;
	int lp = 0, lq = 0;
	for (int i = 1; i <= Max; i++) {
		if (i <= p && !(p % i)) a[lp++] = i;
		if (i <= q && !(q % i)) b[lq++] = i;
	}

	for (int i = 0; i < lp; i++)
		for (int j = 0; j < lq; j++)
			cout << a[i] << ' ' << b[j] << endl;
	return 0;
}
