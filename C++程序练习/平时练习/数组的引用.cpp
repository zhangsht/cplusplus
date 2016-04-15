#include <iostream>
#include <string>
using namespace std;
//int find_char(const string &str, const char c, const int &pos) {
//    int len = str.size(), count = 0;
//    pos = len;
//    for (int i = 0; i < len ; i++) {
//        if (str[i] == c) {
//            count++;
//           if (pos == len)
//              pos = i; 
//        }
//    }
//    return count;
//}
template <unsigned M, unsigned N>
void print(const int (&arry)[M][N]) {
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++)
        cout << arry[i][j] << ' ';
    cout << endl;
}

int main() {
    int arry[2][2] = {6, 8, 45, 23};
    print(arry); 
//   const char* p = "fbvduhvbkhvj";
//   while (*p) {
//       cout << *p++; 
//   }
//   cout << endl;
   return 0; 
} 

