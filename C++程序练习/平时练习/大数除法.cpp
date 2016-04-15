#include <iostream>
#include <string>
int main() {
    std::string s;
    int n, a[1000] = {0}, tem1, tem2 = 0, k = 0;
    std::cin >> s >> n;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        tem1 = s[i] - '0' + tem2 * 10;
        if (i != len - 1) tem2 = 0;
        if (tem1 >= n) {
            a[k++] = tem1 / n;
            tem2 = tem1 % n;
        } else {
            tem2 = s[i] - '0';
            a[k++] = 0;
        }
    }
    int i;
    for (i = 0; i < k; i++)
        if (a[i] != 0) break;
    for (; i < k; i++)
      std::cout << a[i];
    std::cout << ' ' << tem2 << std::endl;
    return 0; 
}

