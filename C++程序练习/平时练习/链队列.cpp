#include <iostream>
using namespace std;
enum ErrorCode {
         success,
         underflow,
         overflow
};
template <class QueueEntry>
struct Node {
         QueueEntry data;
         Node<QueueEntry> *next;
};
template <class QueueEntry>
class MyQueue {
    public:
         MyQueue() {
             front = NULL;
             rear = NULL;
        }
         bool empty() const {
             return size() == 0;
         }
         ErrorCode append(const QueueEntry &item) {
             if (front == NULL) {
                 front = new Node<QueueEntry>;
                 if (front == NULL) return overflow;
                 front->data = item;
                 front->next = NULL;
                 rear = front;
                 return success;
             }
             Node<QueueEntry>* t = new Node<QueueEntry>;
             if (t == NULL) return overflow;
             t->data = item;
             t->next = NULL;
             rear->next = t;
             rear = t;
             return success;
         }
         ErrorCode serve() {
             if (front == NULL) return underflow;
             if (size() == 1) {
                 delete front;
                 front = NULL;
                 rear = NULL;
                 return success;
             }
             Node<QueueEntry>* t = front;
             front = front->next;
             delete t;
             return success;
         }
         ErrorCode retrieve(QueueEntry &item) const {
             if (front == NULL) return underflow;
             item = front->data;
             return success;
         }
         int size() const {
             Node<QueueEntry>* t = front;
             int cnt = 0;
             while (t != NULL) {
                 t = t->next;
                 cnt++;
             }
             return cnt;
         }
         void clear() {
             if (front == NULL) return;
             Node<QueueEntry>* t;
             while (front != NULL) {
                 t = front;
                 front = front->next;
                 delete t;
             }
             rear = NULL;
         }
         ErrorCode retrieve_and_serve(QueueEntry &item) {
             ErrorCode e = retrieve(item);
             if (e == underflow) return e;
             e = serve();
             if (e == underflow) return e;
             return success;
         }
private:
         Node<QueueEntry> *front;                           // 队头指针
         Node<QueueEntry> *rear;                             // 队尾指针
};

//int main() {
//    MyQueue<int> q;
//    cout << q.size() << endl;
//    for (int i = 0; i < 100; i++) {
//        q.append(i);
//    }
//    int a;
//    for (int i = 0; i < 5; i++) {
//        q.retrieve(a);
//        q.serve();
//        cout << a << ' ';
//    }
//    cout << "\n";
//    if (q.empty()) cout << "fvsjbv\n";
//    cout << q.size() << endl;
//    q.clear();
//    cout << q.size() << endl;
//    if (q.empty()) cout << "hehe\n";
//}
