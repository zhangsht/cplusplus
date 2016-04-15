#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
bool greater6(char c) {
    return c > '6';
}
void outputsquare(char value) {
    cout << (value - '0') * (value - '0') << ' ';
}
int my_cube(char value) {
    int a = (value - '0');
    return a * a * a;
}
int main() {
    vector<char> v(10);
    ostream_iterator<vector<char>::value_type> output(cout, " ");
    fill(v.begin(), v.end(), '3');
    v[3] = '8';
    vector<char>::iterator it = remove_if(v.begin(), v.end(), greater6);
    copy(v.begin(), it, output);
    cout << endl;
    for_each(v.begin(), it, outputsquare);
    cout << endl;
    vector<char> v3(it - v.begin());
    copy_backward
    //transform(v.begin(), it, v3.begin(), my_cube);
    copy(v3.begin(), v3.end(), output);
    return 0;
}

