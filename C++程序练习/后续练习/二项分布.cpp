#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double tot = 0;
	for (int i  = 15; i >= 0; i--) {
		double sum = 1;
		for (int j = 0; j < 15 - i; j++) sum *= 0.7;
		for (int k = 0; k < i; k++) sum *= 0.3;
		for (int k = 0, t = 15; k < i; k++, t--) sum *= (t);
		for (int k = 0, z = 1; k < i; k++, z++) sum /= (z);
		tot += sum;
		cout << fixed << i << ' ' << setprecision(4) << tot << endl;
	}
}
