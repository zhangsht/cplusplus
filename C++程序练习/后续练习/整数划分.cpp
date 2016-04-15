#include <iostream>
#include <vector>
using namespace std;

void split(vector<int>& v, int n, int len) {
	if (n == 0) {
		for (int i = 0; i < len - 1; i++)
			cout << v[i] << '+';
		cout << v[len - 1] << endl;
	} else {
		for (int i = n; i >= 1; i--) {
			if (len == 0 || i <= v[len - 1]) {
				v[len] = i;
				split(v, n - i, len + 1);
			}
		}
	}
}
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n);
		split(v, n, 0);
	}
	return 0;
}
