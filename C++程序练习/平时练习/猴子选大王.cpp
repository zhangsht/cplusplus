#include <iostream>
#include <queue>
using namespace std;
class Josephus{
private:
	int n, s, m;
public:
	Josephus(int _n, int _s, int _m):n(_n), s(_s), m(_m){};
	void sol() {
	    queue<int>q;
	    for (int i = 1; i <= n; i++)
	      q.push(i);
	    for(int i = 1; i < s; i++) {
	        q.push(q.front());
	        q.pop();
        }
        while (q.size() != 1) {
            for (int i = 0; i < m; i++) {
                q.push(q.front());
	            q.pop();
            }
            cout << q.front() << ' ';
            q.pop();
        }
        cout << q.front() << endl;
    }
};

int main() {
    Josephus j(6, 3, 4);
    j.sol();
    return 0;
}

