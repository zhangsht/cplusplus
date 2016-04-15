#include <cstdio>
#include <cstring>

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		char str[201];
		getchar();
		gets(str);
		int len = strlen(str);

		char temp;
		char *start;
		for (int i = n; i < len; i += 2 * n) {
			for (int j = 0; j < n / 2; j++) {
				start = str + i;
				temp = *(start + j);
				*(start + j) = *(start + n - 1 - j);
				*(start + n - 1 - j) = temp;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < len; j++)
				if (j % n == i)
				printf("%c", *(str + j));
		}
		printf("\n");
	}
}
