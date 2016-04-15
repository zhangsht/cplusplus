#include<stdio.h>

int list[255];

void split(int n, int m, int max){
	int i;
	// 如果分割完毕
	if (n == 0){
		// 遍历输出数组
		for (i = 0; i < m; i++){
			printf("%d", list[i]);
		}
		for (; i < max; i++){  //  空“篮子”补上0
			printf("0");
		}
		printf("\n");

		return;
	}

	// 由大到小进行分割
	for (i = n; i >= 1; i--){
		// 如果未分割或当前分割的数字不大于上一个分割的数字
		if (m == 0 || i <= list[m - 1]){
			// 将分割的数字存入数组
			list[m] = i;
			// 如果m小于总的“篮子”数（m从0开始计数），则分割剩下的数字
			if (m < max) {
				split(n - i, m + 1, max);
			}
		}
	}
}

int main() {
	int T, n, max;
	scanf("%d", &T);  //

	while (T--) {
		scanf("%d%d", &n, &max);

		split(n, 0, max);
	}
	return 0;
}
