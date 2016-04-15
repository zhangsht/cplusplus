#include <iostream>
#include <vector>
using namespace std;

void split(vector<int>& v, int n, int len, int m) {
	if (n == 0) {
		int i;
		for (i = 0; i < len; i++)
			cout << v[i];
		for (; i < m; i++)
			cout << '0';
		cout << endl;
	} else {
		for (int i = n; i >= 1; i--) {
			if (len == 0 || i <= v[len - 1]) {
				v[len] = i;
				if (len < m)
					split(v, n - i, len + 1, m);
			}
		}
	}
}
int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> v(n);
		split(v, n, 0, m);
	}
	return 0;
}
