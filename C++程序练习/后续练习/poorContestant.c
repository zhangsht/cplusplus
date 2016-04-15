#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

struct user {
	char name[11];
	int cnt;
	user(char n[], int c) {
		strcpy(name, n);
		cnt = c;
	};
};

struct minCmp {
	bool operator()(const user& a, const user& b) {
		return a.cnt > b.cnt;
	};
};
struct maxCmp {
	bool operator()(const user& a, const user& b) {
		return a.cnt < b.cnt;
	};
};

priority_queue<user, vector<user>, minCmp>minQ;
priority_queue<user, vector<user>, maxCmp>maxQ;

void insert(user u) {
	user tmp;
	if (minQ.empty()) minQ.push(u);
	else if (maxQ.size() >= minQ.size()) {
		tmp = maxQ.top();
		if (u.cnt < tmp.cnt) {
			maxQ.pop();
			maxQ.push(u);
			u = tmp;
		}
		minQ.push(u);
	} else {
		tmp = minQ.top();
		if (u.cnt > tmp.cnt) {
			minQ.pop();
			minQ.push(u);
			u = tmp;
		}
		maxQ.push(u);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	bool f = false;

	char cmd[11], name[11];
	while (n--) {
		if (f) printf("\n");
		f = true;

		int size = 0, cnt;
		while (true) {
			scanf("%s", cmd);
			if (strcmp(smd, "Add") == 0) {
				scanf("%s%d", name, cnt);
				user u(name, cnt);
				insert(u);
				size++;
			} else if (strcmp(cmd, "Query") == 0) {
				if (size & 1 == 0) printf("No one!\n");
				else printf("%s\n", minQ.top().name);
			} else break;
		}
		if (size & 1) printf("%s is so poor.\n", minQ.top().name);
		else printf("Happy BG meeting!!\n");

		while (!minQ.empty()) minQ.pop();
		while (!maxQ.empty()) maxQ.pop();
	}
	return 0;
}