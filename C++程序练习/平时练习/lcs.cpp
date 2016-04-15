#include<iostream>
#include <cstring>
#include <sstream>
#define N 1000
using namespace std;
//str1存储字符串1，str2存储字符串2
char str1[N],str2[N];
//c[i][j]存储str1[1...i]与str2[1...j]的最长公共子序列的长度
int c[N][N];
//flag[i][j]标记是那种子问题
//flag[i][j]==0为str1[i]==str2[j]
//flag[i][j]==1为c[i-1][j]>=s[i][j-1]
//flag[i][j]==-1为c[i-1][j]<s[i][j-1]
int flag[N][N];
//
int getLCSlength(const char *s1, const char *s2) {
    int i;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(i = 1; i <= len1; i++) c[i][0] = 0;
    for(i = 0; i <= len2; i++) c[0][i] = 0;
    int j;
    for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                flag[i][j] = 0;
            }
            else if(c[i-1][j]>=c[i][j-1]) {
                c[i][j] = c[i-1][j];
                flag[i][j] = 1;
            } else {
                c[i][j] = c[i][j-1];
                flag[i][j] = -1;
            }
    }
    return c[len1][len2];
}

int main() {
    string str;
    while(getline(cin, str)) {
        stringstream s(str);
        s >>  str1 >> str2;
        cout << getLCSlength(str1, str2) << endl;
    }
    return 0;
}
