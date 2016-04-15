#include <iostream>
#include <cmath>
using namespace std;
#ifndef AVL_NODE

#define AVL_NODE



template <class Entry>

struct AvlNode

{

         Entry entry;

         AvlNode<Entry> *left;

         AvlNode<Entry> *right;

         int bf;                // balance factor 平衡因子

};



#endif


// 判断一颗树是否为平衡二叉树

template <class Entry>

bool is_AVL_Tree(AvlNode<Entry> *&root) {
	if (root == NULL) return true;
	int lDepth = getDepth(root->left),
		rDepth = getDepth(root->right);
	int absDepth = abs(lDepth - rDepth);

	return (absDepth < 2) && is_AVL_Tree(root->left) && is_AVL_Tree(root->right);
}

template <class Entry>
int getDepth(AvlNode<Entry> *&root) {
	int lDepth, rDepth;
	if (root == NULL) return 0;

	lDepth = getDepth(root->left);
	rDepth = getDepth(root->right);
	return (rDepth > lDepth) ? (rDepth + 1) : (lDepth + 1);
}