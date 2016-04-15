//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <set>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n;
	while (cin >> n) {
	    std::set<int> s;
	    for (int i = 0, tmp; i < n; i++) {
	    	cin >> tmp;
	    	s.insert(tmp);
	    }
	    int len = s.size(), j;
	    cout << len << endl;
	    std::set<int>::iterator it, end = s.end();
	    for (it = s.begin(), j = 0; j < len - 1; it++, j++) {
	    	cout << *it << ' ';
	    }
	    cout << *it << endl;
	}
	return 0;
}
