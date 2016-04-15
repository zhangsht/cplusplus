#include <iostream>
// #include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	// vector<double> number;
	double temp;
	double tot = 0;
	for (int i = 1, j = n; i <= n; i++, j--) {
		 cin >> temp;
		 tot += (temp * j * i);
		// number.push_back(temp);
	}
	cout << fixed << setprecision(2) << tot << endl;
	// for (int i = 0; i < n; i++) {

	// }
}
