#include <iostream>
#include <string>
using namespace std;

 int main(){
	string model, input;
	cin >> model >> input;

	int len_M = model.size(), len_in = input.size();
	int lenth = (len_M > len_in) ? len_in : len_M;


	string result = "";
	int temp;
	for (int i = 1, j = len_M - 1, k = len_in - 1; i <= lenth; i++, j--, k--) {
		if (i % 2 == 1) {
			temp = (model[j] - '0' + input[k] - '0') % 13;
			if (temp == 10) result += ('J');
			else if (temp == 11) result += ('Q');
			else if (temp == 12) result += ('K');
			else result += (temp + '0');
		} else {
			temp = input[k] - model[j];
			if (temp < 0) temp += 10;
			result += (temp + '0');
		}
	}

	for (int i = lenth; i < len_in; i++) result += input[len_in - i - 1];

	for (int i = result.size() - 1; i >= 0; i--) cout << result[i];
	cout << endl;
	return 0;
}
