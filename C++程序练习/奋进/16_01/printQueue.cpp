//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    int ans = 0;
	    std::queue<int> q;
	    std::priority_queue<int> pq;

	    cin >> n;
	    for (int i = 0, tmp; i < n; ++i) {
	    	cin >> tmp;
	    	q.push(tmp);
	    	pq.push(tmp);
	    }
	    while (!q.empty()) {
	    	int f = q.front();
	    	if (f == pq.top()) {
	    		q.pop();
	    		pq.pop();
	    	} else {
	    		q.push(q.front());
	    		q.pop();
	    		ans++;
	    	}
	    }
	    cout << ans << endl;
	}
	return 0;
}
