#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int n, m;
double times = 0.0;
map<int, string> room;

int getNum(int tot) {
    for (int i = 0; i <= m / 2; i++) {
        times = times + 1;
        int tem = (tot + i * i) % m;
         if (room.find(tem) == room.end()) {
             return tem;
         }
         if (i != 0) {
             times = times +1;
             tem = (tot - i * i) % m;
             if (room.find(tem) == room.end()) {
                 return tem;
             }
         }
    }
}

int main() {
    while (cin >> n) {
        cin >> m;
        string str;
        for (int i = 0; i < n; i++) {
             cin >> str;
             int len = str.size(), tot = 0, num;
             for (int j = 0; j < len; j++) tot += (str[j] - 'a' + 1);
             num = getNum(tot);
             room[num] = str;
        }
        for (int i = 0; i < m; i++) {
            if (room.find(i) == room.end()) cout << i << ":NULL\n";
            else cout << i << ':' << room[i] << endl;
        }
        cout << setiosflags(ios::fixed) << setprecision(3) << times / n << endl;
        times = 0.0, room.clear();
    }
    return 0;
}
