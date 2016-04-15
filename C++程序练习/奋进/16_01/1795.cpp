//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    int d = 0;
	    for (int i = 0; i < n; ++i) {
	    	int x, y;
	    	cin >> x >> y;
	    	double d1 = sqrt((x - 30) * (x - 30) + (y - 30) * (y - 30)),
	    		   d2 = sqrt((x - 100) * (x - 100) + (y - 30) * (y - 30)),
	    		   d3 = sqrt((x - 170) * (x - 170) + (y - 30) * (y - 30));
	    	if (d1 < 20) d += 1;
	    	if (d2 < 10) d += 2;
	    	if (d3 < 5) d += 3;
	    }
	    cout << d << endl;
	}
	return 0;
}
