// Problem#: 16804
// Submission#: 4263351
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
#ifndef NODE
#define NODE
template <class Entry>
struct Node {
     Entry entry;
     Node<Entry> *left;
     Node<Entry> *right;
     Node(const Entry &en) {
       entry = en;
       left = NULL;
       right = NULL;
     }
};
#endif

template <class Entry>
Node<Entry>* BSTree_search(Node<Entry> *root, Entry &target) {
    if (root == NULL || root->entry == target) return root;

    if (root->entry < target) return BSTree_search(root->right, target);
    else return BSTree_search(root->left, target);
}

template <class Entry>
void BSTree_insert(Node<Entry> *&root, const Entry &target) {
    if (root == NULL) {
        root = new Node<Entry>(target);
        return;
    }

    if (target < root->entry) BSTree_insert(root->left, target);
    else if (target > root->entry) BSTree_insert(root->right, target);
}

template <class Entry>
void BSTree_remove(Node<Entry> *&root, const Entry &target) {
    if (root == NULL) {
        return;
    } else if (root->entry == target) {
        Node<Entry> *del = root;
        if (root->right == NULL) root = root->left;
        else if (root->left == NULL) root = root->right;
        else {
            del = root->left;
            Node<Entry> *par = root;
            while (del->right != NULL) {
                par = del;
                del = del->right;
            }
            root->entry = del->entry;
            if (par == root) root->left = del->left;
            else par->right = del->left;
            delete del;
        }
    } else if (root->entry  > target) BSTree_remove(root->left, target);
    else BSTree_remove(root->right, target);
}