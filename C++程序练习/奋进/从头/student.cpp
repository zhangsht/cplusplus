#include <iostream>
#include <string>
using namespace std;

class cub {
private:
	int l, w, h;
public:
	void setdata(int l, int w, int h) {
		this->l = l;
		this->w = w;
		this->h = h;
	}
	void display() {
		cout << l * w * h << endl;
	}
};
int main() {
	int l, w, h;
	while (cin >> l >> w >> h){
		cub s;
		s.setdata(l, w, h);
		s.display();
	}
	return 0;
}
