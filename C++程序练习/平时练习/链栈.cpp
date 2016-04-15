#include <iostream>
using namespace std;
enum ErrorCode
{
         success,
         underflow,
         overflow
};
template <class StackEntry>
struct Node
{
         StackEntry data;
         Node *next;
};

template <class StackEntry>
class MyStack
{
    public:
         MyStack() {
             pTop = NULL;
         }
         bool empty() const {
             return pTop == NULL;
         }
         int size() const {
             int cnt = 0;
             Node<StackEntry> *temp = pTop;
             while (temp != NULL) {
                 temp = temp->next;
                 cnt++;
             }
             return cnt;
         }
         ErrorCode pop() {
             if (pTop == NULL) return underflow;
             Node<StackEntry> *t = pTop;
             pTop = pTop->next;
             delete t;
             return success;
         }
         ErrorCode top(StackEntry &item) const {
             if (pTop == NULL) return underflow;
             item = pTop->data;
             return success;
         }
         ErrorCode push(const StackEntry &item) {
             if (pTop == NULL) {
                 pTop = new Node<StackEntry>;
                 if (pTop == NULL) return overflow;
                 pTop->data = item;
                 pTop->next = NULL;
                 return success;
             }
             Node<StackEntry> *t = new Node<StackEntry>;
             if (t == NULL) return overflow;
             t->data = item;
             t->next = pTop;
             pTop = t;
             return success;
         }
         void clear() {
             if (pTop == NULL) return;
             Node<StackEntry> *temp = pTop;
             Node<StackEntry> *t2;
                while (temp != NULL) {
                     t2 = temp;
                     temp = temp->next;
                     delete t2;
                 }
            pTop = NULL;
         }
    private:
         Node<StackEntry> *pTop;
};
