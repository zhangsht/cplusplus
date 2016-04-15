#include <iostream>
#include <set>
#include <string.h>
#include <string>

using namespace std;

int main() {
	int n, m;
	while (cin >> n && n) {
		cin >> m;

		string temp;
		set<string> sendList;
		set<string> friendList;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			for (int i = temp.size() - 1; i >= 0; i--) 
			  temp[i] = toupper(temp[i]);
			friendList.insert(temp);
		}
		for (int i = 0; i < m; i++) {
			cin >> temp;
			for (int i = temp.size() - 1; i >= 0; i--) 
			  temp[i] = toupper(temp[i]);
			sendList.insert(temp);
		}

		set<string>::iterator it;
		for (it = sendList.begin(); it != sendList.end(); it++) {
			if (friendList.find(*it) != friendList.end())
				friendList.erase(*it);
		}
		cout << friendList.size() << endl;
	}
	return 0;
}
