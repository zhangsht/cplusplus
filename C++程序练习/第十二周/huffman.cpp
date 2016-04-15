#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int key;
    node* lchild;
    node* rchild;
};

bool compare(const node* a, const node* b) {
    return a->key < b->key;
}


int getDepth(node *root, int key, int times) {
    if (root->key == key) return times;

    if (!(root->lchild)) getDepth(root->lchild, key, times + 1);
    if (!(root->rchild)) getDepth(root->rchild, key, times + 1);
}

int main() {
    deque<node*> forest;
    node* ptr;
    vector<int> frequency;
    int temp, size;
    char c;

    cin >> size;

    for(int i=0;i<size;i++) {
        cin >> c >> temp;
        frequency.push_back(temp);
        ptr=new node;
        ptr->key=temp;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
        forest.push_back(ptr);
    }

    for(int i=0;i<size-1;i++) {
		sort(forest.begin(),forest.end(),compare);
		ptr=new node;
		ptr->key=forest[0]->key+forest[1]->key;
		ptr->lchild=forest[0];
		ptr->rchild=forest[1];
		forest.pop_front();
		forest.pop_front();
		forest.push_back(ptr);
	}

    int tot = 0;
    ptr=forest.front();
    for (int i = frequency.size() - 1; i >=0; i--) {
        tot += (getDepth(ptr, frequency[i], 0) * frequency[i]);
    }
    cout << tot << endl;

    return 0;
}

