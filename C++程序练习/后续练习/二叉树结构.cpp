#include <stdio.h>
#include <string.h>

const int Max = 1000;

struct order {
	int root;
	char str[Max];
};

int main() {
	order preOrder, postOrder;
	scanf("%s%s", preOrder.str, postOrder.str);
	int len = strlen(preOrder.str);

	int cnt = 0;
	for (preOrder.root = 1; preOrder.root < len; preOrder.root++) {
		postOrder.root = len - 2;
		while (preOrder.str[preOrder.root] != postOrder.str[postOrder.root]) {
			postOrder.root--;
		}

		if (preOrder.str[preOrder.root - 1] == postOrder.str[postOrder.root + 1]) cnt++;
	}

	int tot = 1;
	for (int i = 0; i < cnt; i++) tot *= 2;
	printf("%d", tot);
	return 0;
}
