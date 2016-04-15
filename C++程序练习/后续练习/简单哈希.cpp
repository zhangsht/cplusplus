#include <cstdio>
#include <cstring>
using namespace std;

int hash[10001];
int n, m;

void findPosition(int key, int temp) {
	if (hash[key] == -1) hash[key] = temp;
	else {
		for (int i = 1; i <=m; i++)
			if (hash[(key + i) % m] == -1) {
				hash[(key + i) % m] = temp;
				break;
			}
	}
}

int main() {
	int temp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) hash[i] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		findPosition(temp % m, temp);
	}

	for (int i = 0; i < m; i++) {
		if (hash[i] == -1)
			printf("%d#NULL\n", i);
		else printf("%d#%d\n", i, hash[i]);
	}
	return 0;
}
