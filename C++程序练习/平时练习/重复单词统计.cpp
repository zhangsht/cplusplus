#include <iostream>
#include <string>
int main() {
    std::string cur, pre;
    std::string result;
    int max = 1, count = 0;
    while (std::cin >> cur) {
        if (cur == pre) {
            count++;
        } else if (count >= max) {
                max = count + 1;
                result = pre;
        }
        pre = cur;
    }
    if (max > 1)
      std::cout << max << ' ' << result << std::endl;
    return 0; 
}

