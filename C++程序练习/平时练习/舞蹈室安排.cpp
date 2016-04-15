#include <iostream>
#include <algorithm>
using namespace std;

struct Dancetime {
    int a, b;
};

bool cmp(const Dancetime& t1, const Dancetime& t2) {
    return t1.b < t2.b;
}

int main() {
    int Test;
    cin >> Test;
    while (Test--) {
       int n;
       cin >> n;
       if (n < 2) {
           cout << n << endl;
           continue;
       }
       Dancetime req[151];
       for (int i = 0; i < n; i++)
           cin >> req[i].a >> req[i].b;
        sort(req, req + n, cmp);
        //临时变量temp赋值第一个预约时间；
        Dancetime temp = req[0];
        int tot = 0;
        //如果下一个的起始时间在当前结束时间之后，括号合法，其余均跳过不计
        //得出最大数量
        for (int i = 1; i < n; i++) {
                if (req[i].a > temp.b) {
                    tot++;
                    temp = req[i];
                }
        }
        cout << tot + 1 << endl;
    }
    return 0;
}
