#include<stdio.h>

int list[255];

void split(int n, int m, int max){
	int i;
	// ����ָ����
	if (n == 0){
		// �����������
		for (i = 0; i < m; i++){
			printf("%d", list[i]);
		}
		for (; i < max; i++){  //  �ա����ӡ�����0
			printf("0");
		}
		printf("\n");

		return;
	}

	// �ɴ�С���зָ�
	for (i = n; i >= 1; i--){
		// ���δ�ָ��ǰ�ָ�����ֲ�������һ���ָ������
		if (m == 0 || i <= list[m - 1]){
			// ���ָ�����ִ�������
			list[m] = i;
			// ���mС���ܵġ����ӡ�����m��0��ʼ����������ָ�ʣ�µ�����
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
