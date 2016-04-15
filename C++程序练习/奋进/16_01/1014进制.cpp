//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> d, h, t;
	for (int i = 2992; i < 10000; i++) {
		int num1 = i, num2 = i, num3 = i;
		int tmp;
		while (num1 != 0) {
		    tmp = num1 % 10;
		    d.push(tmp);
		    num1 /= 10;
		}
		while (num2 != 0) {
		    tmp = num2 % 12;
		    t.push(tmp);
		    num2 /= 12;
		}
		while (num3 != 0) {
		    tmp = num3 % 16;
		    h.push(tmp);
		    num3 /= 16;
		}
		int s1 = 0, s2 = 0, s3 = 0;
		while (!d.empty()) {
		    s1 += d.top();
		    d.pop();
		}
		while (!t.empty()) {
		    s2 += t.top();
		    t.pop();
		}
		while (!h.empty()) {
		    s3 += h.top();
		    h.pop();
		}

		if (s1 == s2 && s2 == s3) cout << i << endl;
	}
	return 0;
}
