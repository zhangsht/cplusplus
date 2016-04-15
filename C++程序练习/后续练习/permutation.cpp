#include <iostream>
#include <string>
using namespace std;

void permutation(string& pre, string & remain) {
	if (remain.size() == 1) {
		cout << pre + remain << endl;
	} else {
		for (int i = 0, j = remain.size(); i < j; i++) {
			string newPre = pre + remain[i], newRemain = remain;
			newRemain.erase(i, 1);
			permutation(newPre, newRemain);
		}
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str = "", pre = "";
		for (char i = '1', end = '1' + n; i < end; i++) str += i;
		permutation(pre, str);
	}
	return 0;
}