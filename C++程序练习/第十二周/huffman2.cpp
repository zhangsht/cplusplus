#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct HuffmanNode {
    char ch;
    int frequency;
    HuffmanNode *lc, *rc;
    HuffmanNode():ch(0), frequency(0), lc(NULL), rc(NULL){}
};

struct cmp {
    bool operator()(HuffmanNode* a, HuffmanNode* b)
    {
        return a->frequency > b->frequency;
    }
};

vector<int> v;
void code(HuffmanNode* r, int& tot)
{
    if(r->lc==NULL && r->rc==NULL)
    {
        tot += (r->frequency * v.size());
        v.pop_back();
        return;
    }
    if(r->lc)
    {
        v.push_back(0);
           code(r->lc, tot);
    }
    if(r->rc)
    {
        v.push_back(1);
        code(r->rc, tot);
    }
    if(!v.empty())
        v.pop_back();  //注意pop
}

int main()
{
    int n;
    cin >> n;
    char ch;// c;
    int f;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp>q;

    for(int i=0; i<n; i++)
    {
        HuffmanNode* h = new HuffmanNode;
        cin >> ch >> f;
        //scanf("%c %d", &ch, &f);
        h->ch = ch;
        h->frequency = f;
        q.push(h);
    }

    int res=0;
    while(q.size() > 1)
    {
        HuffmanNode* temp1 = new HuffmanNode;
        temp1 = q.top();
        q.pop();
        HuffmanNode* temp2 = new HuffmanNode;
        temp2 = q.top();
        q.pop();

        HuffmanNode* temp = new HuffmanNode;
        temp->frequency = temp1->frequency + temp2->frequency;
        temp->lc = temp1;
        temp->rc = temp2;

        res += temp1->frequency + temp2->frequency;
        q.push(temp);
    }
    HuffmanNode* root = q.top();
    int tot = 0;
    code(root, tot);
    cout << tot << endl;

    return 0;
}