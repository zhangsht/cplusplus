#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	fstream f("C:\\Users\\zhangsht\\Desktop\\data.dat", ios::out|ios::binary|ios::in);
	if (!f) cout << "wrong_f\n";
	else {
		for (int i = 5; i < 100; i += 5) {
			if (i % 5 == 0) f << i << ' ';
		}
		f << 100;
	}
	f.close();
//	fstream f1("C:\\Users\\zhangsht\\Desktop\\me.txt", ios::out);
//	if (!f1) cout << "wrong\n";
//
//	f1 << 1234 << ' ' << 3.14 << 'A' << "wrong";
//	f1.close();
//	fstream f2("C:\\Users\\zhangsht\\Desktop\\me.txt", ios::in);
//	int i;
//	double d;
//	char c;
//	char s[15];
//	f2 >> i >> d >> c;
//	f2.getline(s, 15);
//	cout << i << ' ' << d << ' ' << c <<  ' ' << s << endl;
//	f2.close();
	return 0;
}
