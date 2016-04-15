#include <iostream>
#include <string>
int main() {
    std::string sa, sb;
    int a, b;
    std::cin >> sa >> a >> sb >> b;
    int tot_a[10] = {0}, tot_b[10] = {0};
    int len_a = sa.length(), len_b = sb.length();
    int i = 0, j = 0;
    for (int k = 0; k < len_a; k++)
      if (sa[k] - '0' == a) tot_a[i++] = a;
    for (int k = 0; k < len_b; k++)
      if (sb[k] - '0' == b) tot_b[j++] = b;
    int tot[11] = {0}, m = (i > j ? j : i), n = (i > j ? i : j), t = n;
    if (n == 0 && m == 0) {
        std::cout << 0 <<std::endl;
        return 0;
    }
    i -= 1, j -= 1;
    for (int k = m - 1; k >= 0; k--) {
        tot[n] = tot_a[i] + tot_b[j];
        n--, i--, j--;
    }
    if (i < 0) {
        for (; j >= 0; j--)
          tot[n--] = tot_b[j];
    } else {
        for (; i >= 0; i--)
          tot[n--] = tot_a[i];
    }
    for (int k = t; tot[k] != 0; k--) {
        if (tot[k] > 10) tot[k - 1]++;
        tot[k] %= 10;
    }
    if (tot[0]) std::cout << tot[0];
    for (int k = 1; k <= t; k++)
      std::cout << tot[k];
    std::cout << std::endl;
    return 0; 
}

