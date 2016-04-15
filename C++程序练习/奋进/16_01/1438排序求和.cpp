//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    std::vector<int> v;

	    cin >> n;
	    for (int i = 0, tmp; i < n; ++i) {
	    	cin >> tmp;
	    	v.push_back(tmp);
	    }
	    sort(v.begin(), v.end(), greater<int>());
	    int tot = 0;
	    for (int i = 2; i < n; i += 3) {
	    	tot += v[i];
	    }
	    cout << tot << endl;
	}
	return 0;
}
