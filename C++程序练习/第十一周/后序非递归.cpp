#include <iostream>
#include <stack>
using namespace std;
#ifndef NODE

#define NODE

template <class Entry>

struct Node

{

         Entry entry;

         Node<Entry> *left;

         Node<Entry> *right;

};

#endif

 

// 二叉树的后序遍历

template <class Entry>

void postorder(Node<Entry> *root, void (*visit)(Entry &)) {
	stack<Node<Entry>*> nodeStack;
	Node<Entry>* current, previous = NULL;
	nodeStack.push(root);

	while (!nodeStack.empty()) {
		current = nodeStack.top();

		if ((current->left == NULL && current->right == NULL) ||
			(previous != NULL) && (previous == current->left || previous == current->right)) {
			visit(current->entry);
		nodeStack.pop();
		previous = current;
		} else {
			if (current->right != NULL) nodeStack.push(current->right);
			if (current->left != NULL) nodeStack.push(current->left);
		}
	}
}