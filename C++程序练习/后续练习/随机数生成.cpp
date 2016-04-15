#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

int main() {
	set<int> s;
	int tem;
	srand((int)time(NULL));
	while(s.size() != 6) {
		tem = rand() % 8;
		s.insert(tem);
		cout << tem << ' '; 
	}
	cout << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) cout << *it << ' ';
}
