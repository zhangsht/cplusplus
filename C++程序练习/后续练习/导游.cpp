#include <iostream>
#include <cmath>
using namespace std;
const int INF = -1;

int cities[101][101];
int N, R;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cities[i][j] = cities[j][i] = INF;
		cities[i][i] = 0;
	}
}

int Floyd(int begin, int end) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				cities[j][k] = max(cities[j][k], min(cities[j][i], cities[i][k]));

	return cities[begin][end];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> R;
		init();

		int start, finish, weight;
		for (int i = 0; i < R; i++) {
			cin >> start >> finish >> weight;
			cities[start][finish] = cities[finish][start] = weight;
		}

		int begin, end, sum;
		cin >> begin >> end >> sum;
		int load = Floyd(begin, end);
		cout << sum / (load - 1) + (sum % load ? 1 : 0) << endl;
	}
	return 0;
}
