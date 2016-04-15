#include <stdio.h>
#include <algorithm>
using namespace std;

struct cow {
	int breed;
	int position;
};
const int Max = 50000;
cow Cow[Max + 1];
int sum[Max + 1];
int sum_position[2 * Max + 1] = {0};

bool cmp(const cow &a, const cow &b) {
	return a.position < b.position;
}

int main() {
	int n;
	scanf("%d", &n);

	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &Cow[i].breed, &Cow[i].position);
		if (!Cow[i].breed) Cow[i].breed = -1;
	}
	sort(Cow + 1, Cow + n + 1, cmp);

	int max = 0;
	sum[0] = 0;
	for (i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + Cow[i].breed;
		if (sum_position[sum[i]] == 0) sum_position[sum[i]] = i;
		else {
			if (max < Cow[i].position - Cow[sum_position[sum[i]] + 1].position) 
				max = Cow[i].position - Cow[sum_position[sum[i]] + 1].position;
		}
	}
	printf("%d\n", max);
	return 0;
}
