#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int n, len = 5;
	char str[101][6];
	int pos[6];

	while(cin >> n, n) {
	    char ans[6];
	    for (int i = 0; i < n; i++) cin >> str[i];
	    char next[6] = "ABCDE";
	    int min = 9999;

	    do {
	    	for (int i = 0; i < len; i++) pos[next[i] - 'A'] = i;
	    	int sum = 0;
	    	for (int i = 0; i < n; i++) {
	    		for (int j = 0; j < len; j++) {
	    			for (int k = j + 1; k < len; k++)
	    				if (pos[str[i][j] - 'A'] > pos[str[i][k] - 'A']) sum++;
	    		}
	    	}
	    	if (sum < min) {
	    		min = sum;
	    		strcpy(ans, next);
	    	}
	    } while(next_permutation(next, next + 5));
	    cout << ans << " is the median ranking with value " << min << ".\n";
	}
	return 0;
}
