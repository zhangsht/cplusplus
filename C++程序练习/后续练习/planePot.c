#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int max = 300;

struct Period
{
	int end;
	int length;
	int average;
};

int main() {
	int runs;
	int quarter, requested, min;
	int quars[max + 1];
	Period periods[max * max];

	for (int i = 1; i <= runs; i++) {
		cin >> quarter >> requested >> min;
	}
}