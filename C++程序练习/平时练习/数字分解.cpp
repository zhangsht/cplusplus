#include <iostream>
int main() {
    int n;
    while (std::cin >> n) {
        int m = n / 2, k = m + 1;
        bool flag = false;
        for (int i = 1; i <= m; i++) {
            for (int j = 2; j <= k; j++) {
                if ((i + j) * (j - i + 1) / 2 == n) {
                    for (int k = i; k <= j; k++)
                        std::cout << k << ' ';
                    std::cout << '\n';
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) std::cout << "None\n";
    }
    return 0;
}
