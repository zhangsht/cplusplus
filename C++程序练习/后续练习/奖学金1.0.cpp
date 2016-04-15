// Problem#: 4094
// Submission#: 4359135
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Grade {
    int Id;
    int Chinese, Math, English;
    int tot;
};

bool cmp(const Grade& stu1, const Grade& stu2) {
    if (stu1.tot < stu2.tot) return true;
    if (stu1.tot == stu2.tot) {
        if (stu1.Chinese < stu2.Chinese) return true;
        if (stu1.Chinese == stu2.Chinese) {
            if (stu1.Id > stu2.Id) return true;
        }
    }
    return false;
}

int main() {
    int n, Chinese, Math, English;
    Grade temp;
    bool flag = false;

   while (cin >> n) {
   	if (flag) cout << endl;
   	flag = true;
   	vector<Grade> v;
    for (int i = 1; i <= n; i++) {
        cin >> Chinese >> Math >> English;
        temp.Id = i, temp.Chinese = Chinese,
        temp.Math = Math, temp.English = English;
        temp.tot = Chinese + Math + English;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = v.size() - 1, count = 0; count < 5; count++, i--)
        cout << v[i].Id << " " << v[i].tot << endl;
   }
    return 0;
}
