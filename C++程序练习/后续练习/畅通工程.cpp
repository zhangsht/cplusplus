#include <iostream>
#define inf 999999

using namespace std;
int n, m;
int map[201][201];

int Floyd(int start, int end) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];

	if (map[start][end] == inf) return -1;
	return map[start][end];
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			map[i][j] = map[j][i] = inf;
		map[i][i] = 0;
	}
} 

int main() {
	while (cin >> n) {
		cin >> m;
		int start, finish, weight;

		init();

		for (int i = 0; i < m; i++) {
			cin >> start >> finish >> weight;
			if (map[start][finish] > weight)
				map[start][finish] = map[finish][start] = weight;
		}

		int begin, end;
		cin >> begin >> end;
		cout << Floyd(begin, end) << endl;
	}
	return 0;
}
