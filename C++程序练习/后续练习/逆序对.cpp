#include <cstdio>
long long count = 0;

void Merge(int *source, int *temp, int start, int middle, int end) {
	int j = middle + 1, i = start, k = start;
	while (i <= middle && j <= end) {
		if (source[i] <= source[j])
			temp[k++] = source[i++];
		else {
			temp[k++] = source[j++];
			count += (middle - i + 1);
		}
	}
	while(i <= middle) temp[k++] = source[i++];
	while(j <= end) temp[k++] = source[j++];
	for (i = start; i <= end; i++) source[i] = temp[i];
}

void MergeSort(int *source, int *temp, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		MergeSort(source, temp, start, middle);
		MergeSort(source, temp, middle + 1, end);
		Merge(source, temp, start, middle, end);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int array[n], temp[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	MergeSort(array, temp, 0, n - 1);
	printf("%lld\n", count);
	return 0;
}
