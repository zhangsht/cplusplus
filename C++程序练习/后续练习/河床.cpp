#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;

int main() {
	int n, k;
	int array[30001];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &array[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int count = 0;
		int Max = 0, Min = 100000;
		for (int j = i; j < n; ++j) {
			Max = (Max < array[j] ? array[j] : Max);
			Min = (Min > array[j] ? array[j] : Min);
			if (Max - Min <= k) {
			    count++;
			} else break;
		}

		if (count > ans) ans = count;
	}

	printf("%d\n", ans);
	return 0;
}
