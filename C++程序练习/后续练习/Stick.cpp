#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;

	while (cin >> n && n) {
		int temp;
		map<int, int> myMap;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (myMap.find(temp) == myMap.end()) myMap[temp] = 1;
			else myMap[temp]++;
		}

		map<int, int>::iterator it;
		for(it = myMap.begin(); it != myMap.end(); ++it) {
			if (it->second == 1) {
				cout << it->first << endl;
				break;
			}
		}
	}
	return 0;
}
