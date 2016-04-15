#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;
void dfs(vector<int>& queen, bool used[]) {
    if (queen.size() == 8) {
        for (int i = 0; i < 7; i++)
            printf("%d ", queen[i]);
        printf("%d\n", queen[7]);
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (used[i])
            continue;
        bool diagonalOK = true;
        for (int j = 0; j < queen.size(); j++) {
            if (queen.size() - j == abs(i - queen[j])) {
                diagonalOK = false;
                break;
            }
        }
        if (diagonalOK) {
            queen.push_back(i);
            used[i] = true;
            dfs(queen, used);
            queen.pop_back();
            used[i] = false;
        }
    }
}
int main() {
    vector<int> queen;
    bool used[9] = {0};
    dfs(queen, used);
    return 0;
}
