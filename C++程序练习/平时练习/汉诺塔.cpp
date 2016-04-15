// Problem#: 15771
// Submission#: 3941517
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>

using namespace std;

void hannoi(int n, int A, int B, int C)
{
    if (n > 0) {
        hannoi (n-1, A, C, B);
        cout << "move disk " << n << " from peg " << A << " to peg " << C << endl;
        hannoi (n-1, B, A, C);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
    cin >> n;
    hannoi (n, 1, 2, 3);
    }

    return 0;
}
