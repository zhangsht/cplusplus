#include <cstdio>
#include <vector>
using namespace std;

long long binarySearch(const vector<long long> table, int bot, int top, long long &x) {
    int left = bot, right = top;
    while (left < right - 1) {
        int mid = (left + right) / 2;
        if (table[mid] == x) return mid;
        else if (x < table[mid]) right = mid;
        else left = mid;
    }
}

int main() {
    int t, n;
    long long N;

    scanf("%d", &t);
    
    while (t--) {
        long long tem, a;
        vector<long long> v;
        scanf("%d%lld", &n, &N);

        scanf("%lld", &a);
        for (int i = 1; i < n; i++) {
            scanf("%lld", &tem);
            if (a < tem) a = tem;
        }
        
        for (long long i = 0; i < N; i++) {
            scanf("%lld", &tem);
            v.push_back(tem);
        }
        
        long long tot = 0;
        tot = binarySearch(v, 0, N, a);
        printf("%lld\n", tot * 50);
    }
    return 0;
}

