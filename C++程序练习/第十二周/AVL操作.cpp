#include <iostream>
using namespace std;

#ifndef AVL_NODE
#define AVL_NODE
template <class Entry>
struct AvlNode {
     Entry entry;
     AvlNode<Entry> *left;
     AvlNode<Entry> *right;
     int bf;                // balance factor 平衡因子
};

#endif
// 查找AVL树里面是否有元素entry，如果有则返回该结点，没有则返回NULL
template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry) {
	if (root == NULL || root->entry == entry) return entry;

	AVL_search(root->left, entry);
	AVL_search(root->right, entry);
}

// 将entry插入到AVL树
template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry) {
	bool taller;
	avl_inert(root, entry, taller);
}

template <class Entry>
void avl_inert(AvlNode<Entry> *&root, const Entry entry, bool taller) {
	if (root == NULL) {
		root = new
	}
}
