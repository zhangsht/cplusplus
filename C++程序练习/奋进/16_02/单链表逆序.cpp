//authors zhangsht (zhangsht95@qq.com)
#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node(int d, node* p) {
		data = d;
		next = p;
	}
};

int main() {
	node *head, *pn, *pr;
	head = new node(0, NULL);
	node* current = head;
	for (int i = 1; i < 9; ++i) {
		pn = new node(i, NULL);
		current->next = pn;
		current = pn;
	}
	current = head;
	pn = current->next;
	current->next = NULL;
	while (pn) {
		pr = pn->next;
		pn->next = current;
		current = pn;
		pn = pr;
	}
	head = current;
	while (head) {
	    cout << head->data << ' ';
	    head = head->next;
	}
	return 0;
}
