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
        //��ʱ����temp��ֵ��һ��ԤԼʱ�䣻
        Dancetime temp = req[0];
        int tot = 0;
        //�����һ������ʼʱ���ڵ�ǰ����ʱ��֮�����źϷ����������������
        //�ó��������
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
