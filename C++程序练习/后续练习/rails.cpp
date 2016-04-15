#include <stack>
#include <iostream>
using namespace std;

int main() {
	int number;
	while (cin >> number && number) {
		int temp;
		while (cin >> temp && temp) {
			int k = 1;
			stack<int> load;
			for (int i = 0; i < number; i++) {
				if (i) cin >> temp;
				if (load.empty()) load.push(k++);
				while (temp != load.top() && temp > load.top()) load.push(k++);
				if (!load.empty()) load.pop();
			}
			if (load.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "\n";
	}
    return 0;
}
