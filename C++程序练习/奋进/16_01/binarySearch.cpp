#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
int binarySearch(const vector<Comparable> table, int bot, int top, const Comparable &x){
	int mid;
	while (bot + 1 < top) {
		mid = (bot + top) / 2;
		if (x < table[mid]) top = mid - 1;
		else if (x > table[mid]) bot = mid + 1;
		else bot = mid;
	}
	if (table[bot + 1] == x) return bot + 1;
	if (table[bot] == x) return bot;
	return -1;
}
//
//int main()
//{
//	int a[] = {0,1, 1,3,3,3,6};
//	vector<int> v(a,a+7);
//	cout << binarySearch(v, 0, v.size()-1, 7);
//	return 0;
//}
