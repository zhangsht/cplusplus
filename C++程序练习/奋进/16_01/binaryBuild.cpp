//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <cstdio>
using namespace std;

struct node {
	char c;
	int l, r;
};

int main() {
	int n, k;
	int root = 0;
	node vtr[1001];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> k >> vtr[k].c >> vtr[k].l >> vtr[k].r;
			root ^= k;
			root ^= vtr[k].l;
			root ^= vtr[k].r;
		}
		cout << root << endl;
	}
	return 0;
}
