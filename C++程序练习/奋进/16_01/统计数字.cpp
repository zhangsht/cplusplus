//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <cstdio>
#include <map>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n, index;
	bool flag = false;
	while (cin >> n) {
		if (flag) printf("\n");
		flag = true;
		std::map<int, int> data;
	    for (int i = 0; i < n; ++i) {
	    	scanf("%d", &index);
	    	data[index]++;
	    }
	    std::map<int, int>::iterator it, end = data.end();
	    for (it = data.begin(); it != end; ++it) {
	    	printf("%d %d\n", (it->first), (it->second));
	    }
	}
	return 0;
}
