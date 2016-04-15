#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++) {
        s = "";
        s += str[i];
        v.push_back(s);
    }
    string str2;
    cin >> str2;
    
    vector<string> result;
    vector<int> v2;
    string tem;
    int len = str2.length(), tot = 0;
    for (int i = 0; i < len; i++) {
        while(str2[i] != '0' && i < len) {
            if (str2[i] != '-') {
               while (str2[i] != '-') {
                   tot = tot * 10 + str2[i] - '0';
                   i++;
               }
               v2.push_back(tot - 1);
               tot = 0;
            }
            i++;
        }
        
        tem = "";
        int num = v2.size();
        for (int i = 0; i < num; i++) tem += v[v2[i]];
        
        v.push_back(tem);
        result.push_back(tem);
        v2.clear();
    }
    
    int num2 = result.size();
    for (int i = 0; i < num2 - 1; i++) cout << result[i] << ' ';
    cout << result[num2 - 1] << endl;
    return 0;
}

