#include <iostream>
using namespace std;

int main() {
	int c, m;
	int dp[1001] = {0}, w[101] = {0}, v[101] = {0};
	cin >> c >> m;
	for (int i = 1; i <= m; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = c; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[c] << endl;
	return 0;
}