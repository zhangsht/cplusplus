// Problem#: 16102
// Submission#: 4041685
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
enum Error_code {
         success,
         underflow,
         overflow
};

template <class List_entry>
struct Node {
    List_entry entry;
    Node<List_entry> *next;
    Node();
    Node(List_entry entry_elment, Node<List_entry> * p = NULL) {
           entry = entry_elment;
           next = p;
    }
};

template <class List_entry>
class MyList {
public:
         MyList() {
             count = 0;
             head = NULL;
         }
         ~MyList() {
             clear();
         }

         MyList(const MyList<List_entry> &copy) {
             count = copy.count;
             if (count == 0) {
                 head = NULL;
             } else {
                 Node<List_entry> *tem = copy.head;
                 head = new Node<List_entry>(tem->entry);
                 Node<List_entry> *new_node = head;
                 for (int i = 0; i < count - 1; i++) {
                     tem = tem->next;
                     new_node->next = new Node<List_entry>(tem->entry);
                     new_node = new_node->next;
                 }
             }
         }
         void operator=(const MyList<List_entry> &copy) {
             if (this == &copy) return;
             clear();
            count = copy.count;
             if (count == 0) {
                 head = NULL;
             } else {
                 Node<List_entry> *tem = copy.head;
                 head = new Node<List_entry>(tem->entry);
                 Node<List_entry> *new_node = head;
                 for (int i = 0; i < count - 1; i++) {
                     tem = tem->next;
                     new_node->next = new Node<List_entry>(tem->entry);
                     new_node = new_node->next;
                 }
             }
         }
         // ���list
         void clear() {
             Node<List_entry> *tem = head, *tem2;
             for (int i = 0; i < count; i++) {
                 tem2 = tem;
                 tem = tem->next;
                 delete tem2;
             }
             count = 0;
             head = NULL;
         }
         // �ж�list�Ƿ�Ϊ��
         bool empty() const {
             return count == 0;
         }
         // �ж�list�Ƿ�����
         bool full() const {
              Node<List_entry> *new_node =  new Node<List_entry>;
              if (new_node == NULL) return true;
              else {
                  delete new_node;
                  new_node = NULL;
                  return false;
              }
         }
         // ��ȡlist��Ԫ������
         int size() const {
             return count;
         }
         // �ڵ�position��λ�ò���ֵΪentry��Ԫ�أ����positionΪ0�����������ͷ����������
         // ��position < 0 ���� position > count���򷵻�underflow
         Error_code insert(int position, const List_entry &entry) {
              if (position < 0 || position > count) return  underflow;
              Node<List_entry> *new_node, *previous, *following;
              if (position > 0) {
                  setPosition(position - 1);
                  previous =  current;
                  following = previous->next;
                  new_node = new Node<List_entry>(entry, following);
                  if (new_node == NULL) return overflow;
                  previous->next = new_node;
              } else {
                  new_node = new Node<List_entry>(entry, head);
                  if (new_node == NULL) return overflow;
                  head = new_node;
              }
              count++;
              return success;
         }
         // ɾ����position��λ�õ�Ԫ�أ�������Ԫ�ص�ֵ������entry��
         // ��position < 0 ���� position >= count���򷵻�underflow
         Error_code remove(int position, List_entry &entry) {
             if (position < 0 || position >= count || count < 1) return  underflow;
            Node<List_entry> *following, *tem;
             if (position == 0) {
                 tem = head;
                 head = head->next;
                 entry = tem->entry;
                 delete tem;
             } else {
                   setPosition(position - 1);
                   following = current->next;
                   current->next = following->next;
                   entry = following->entry;
                   delete following;
             }
             count--;
             return success;
         }
         // ��ȡ��position��λ�õ�Ԫ�أ�������entry��
         // ��position < 0 ���� position >= count���򷵻�underflow
         Error_code retrieve(int position, List_entry &entry) const {
              if (position < 0 || position >= count) return  underflow;
              setPosition(position);
              entry = current->entry;
              return success;
         }
         // ����position��λ�õ�Ԫ���滻Ϊentry
         // ��position < 0 ���� position >= count���򷵻�underflow
         Error_code replace(int position, const List_entry &entry) {
              if (position < 0 || position >= count) return  underflow;
              setPosition(position);
              current->entry = entry;
              return success;
         }
         // ��visit��������list�����е�Ԫ��
         void traverse(void (*visit)(List_entry &)) {
            Node<List_entry> *tem = head;
            for (int i = 0; i < count; i++) {
                    visit(tem->entry);
                    tem = tem->next;
              }
         }
protected:
         int count;                                                                          // ��¼list��Ԫ������
         Node<List_entry> *head;                                         // ����ͷָ��
         mutable int curPosition;                                   // currentָ���λ�ñ��
         mutable Node<List_entry> *current;                 // currentָ��
         // ����currentָ���λ�ã�ָ���position��λ��
         void setPosition(int position) const {
             Node<List_entry> *tem = head;
             for (int i = 0; i < position; i++) {
                 tem = tem->next;
             }
            current = tem;
         }
};

//void print(int &a) {
//    cout << a;
//}
//int main() {
//     MyList<int> test;
//     if (test.empty()) cout << "yes\n";
//     for (int i = 0; i < 10; i++) {
//         test.insert(i, i + 1);
//     }
//     test.traverse(print);
//     cout << endl;
//     int a;
//     for (int i = 0; i < 3; i++) {
//         test.remove(i + i, a);
//         cout << a << ' ';
//     }
//     cout << endl;
//     cout << test.size() << endl;
//     for (int i = 0; i < 3; i++) {
//         test.replace(i, i);
//     }
//     test.traverse(print);
//     cout << endl;
//     MyList<int> test2(test);
//     test2.traverse(print);
//     cout << endl;
//      MyList<int> test3(test);
//     test3.traverse(print);
//     cout << endl;
//     test.clear();
//     if (test.empty()) cout << "yes\n";
//     return 0;
//     
//}
