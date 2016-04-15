#include <iostream>
#include <queue>
using namespace std;

struct Grade {
	int Id;
	int Chinese, Math, English;
	int tot;
};

struct cmp {
	bool operator()(const Grade& stu1, const Grade& stu2) {
	if (stu1.tot != stu2.tot) return stu1.tot < stu2.tot;
	else if (stu1.Chinese != stu2.Chinese) return stu1.Chinese < stu2.Chinese;
	else return stu1.Id > stu2.Id;
}

};
int main() {
	int n;
	Grade temp;
	bool flag = false;

    while (	cin >> n) {
    	if (flag) cout << endl;
		flag = true;
    	priority_queue<Grade, vector<Grade>, cmp> v;
    	for (int i = 1; i <= n; i++) {
			cin >> temp.Chinese >> temp.Math >> temp.English;
			temp.Id = i;
			temp.tot = temp.Chinese + temp.Math + temp.English;
			v.push(temp);
		}

		for (int count = 0; count < 5; count++) {
			cout << v.top().Id << " " << v.top().tot << endl;
			v.pop();
		}
	}
	return 0;
}
