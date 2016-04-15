#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		map<string,string>myIP;
		map<string,string>::iterator it;
		string ID, IP;
		while (n--) {
			cin >> ID >> IP;
			it = myIP.find(IP);
			if (it == myIP.end()) myIP.insert(make_pair(IP, ID));
			else {
				myIP.insert(make_pair(it->second, ID));
				myIP.erase(it);
			}
		}
		for (it = myIP.begin(); it != myIP.end(); it++)
			cout << it->second << " is the MaJia of " << it->first << endl;
		cout << endl;
	}
	return 0;
}
