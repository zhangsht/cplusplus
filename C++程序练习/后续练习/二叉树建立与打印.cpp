#include <iostream>
using namespace std;

struct node {
	bool flag;
	int left, right;
	char c;
};

node array[1001];
int n;

void print(int i) {
	if (i) {
		cout << array[i].c;
		print(array[i].left);
		print(array[i].right);
	}
}

int main() {
	int index, left, right;
	int temp[1001];

	while (cin >> n) {
		int i;
		for (i = 0; i < n; i++) {
			cin >> index;
			temp[i] = index;
			cin >> array[index].c >> array[index].left >> array[index].right;
			array[index].flag = true;
		}

		for (i = 0; i < n; i++) {
			left = array[temp[i]].left;
			right = array[temp[i]].right;
			array[left].flag = false;
			array[right].flag = false;
		}

		for (i = 0; i < n; i++) {
			if (array[temp[i]].flag)
				break;
		}
		print(temp[i]);
		cout << endl;
	}
	return 0;
}
