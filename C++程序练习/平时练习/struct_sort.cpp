#include <iostream>
#include <string>
#include <algorithm>
struct student {
    std::string id;
    int d, c;
    int tot, flag;
};
bool cmp(const student &s1, const student &s2) {
    if (s1.flag > s2.flag) return true;
    else if (s1.flag == s2.flag) {
        if (s1.tot < s2.tot) return true;
        else if (s1.tot == s2.tot) {
            if (s1.d < s2.d) return true;
            else if (s1.d == s2.d) {
                if (s1.id > s2.id) return true;
            }
        }
    }
    return false;
}
int main() {
    int n, L, H;
    std::cin >> n >> L >> H;
    student * s = new student[n];
    int temp_d, temp_c, i = 0;
    std::string temp_s;
    while (n--) {
        std::cin >> temp_s >> temp_d >> temp_c;
     if (temp_d >= L && temp_c >= L) {
         s[i].id = temp_s;
         s[i].d = temp_d;
         s[i].c = temp_c;
         s[i].tot = temp_d + temp_c;
         if (temp_d >= H && temp_c >= H) s[i].flag = 1;
         else if (temp_d >= H) s[i].flag = 2;
         else if (temp_d >= temp_c) s[i].flag = 3;
         else s[i].flag = 4;
         i++;
     }   
    }
    std::sort(s, s + i, cmp);
    std::cout << i << std::endl;
    for (int j = i - 1; j >= 0; j--)
      std::cout << s[j].id << ' ' << s[j].d << ' ' << s[j].c << std::endl;
    return 0; 
}

