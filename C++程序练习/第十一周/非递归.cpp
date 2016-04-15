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

 

// 二叉树的先序遍历

template <class Entry>

void preorder(Node<Entry> *root, void (*visit)(Entry &)) {
    Node<Entry>* p = root;
    stack<Node<Entry>*> mystack;
    while (p != NULL)
}