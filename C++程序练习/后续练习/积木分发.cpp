#include <iostream>
#include <algorithm>
using namespace std;

struct Block {
	int hold, absence;
};

Block block[10001];

bool cmp(const Block& a, const Block& b) {
	return a.absence < b.absence;
}

int main() {
	int n, s;
	while (cin >> n >> s && n) {
		int i;
		for (i = 0; i < n; i++) {
			cin >> block[i].hold >> block[i].absence;
		}
		sort(block, block + n, cmp);

		for (i = 0; i < n; i++) {
			if (s >= block[i].absence) s += block[i].hold;
			else break;
		}

		if (i == n) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}