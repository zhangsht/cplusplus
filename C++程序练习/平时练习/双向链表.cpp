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
         Node<List_entry> *back;
         
         Node();
         Node(List_entry entry_elment, Node<List_entry> * p1 = NULL, Node<List_entry> * p2 = NULL) {
           entry = entry_elment;
           back = p1;
           next = p2;
         }
};

template <class List_entry>
class MyList {
    
public:
         MyList() {
             count = 0;
             curPosition = 0;
             current = NULL;
         }
         ~MyList() {
             clear();
         }
         // �������캯���͸�ֵ��������أ�ע�������ǳ�����Ĳ���
         MyList(const MyList<List_entry> &copy) {
             count = copy.count;
             curPosition = 0;

             if (count == 0) {
                 current = NULL;
                 return;
             } else {
                 copy.setPosition(0);
                 Node<List_entry> *tem = copy.current;
                 
                 Node<List_entry> *new_node = new Node<List_entry>(tem->entry);
                 current = new_node;

                 for (int i = 0; i < count - 1; i++) {
                     tem = tem->next;
                     new_node->next = new Node<List_entry>(tem->entry, new_node);
                     new_node = new_node->next;
                 }
             }
         }
         void operator =(const MyList<List_entry> &copy) {
              if (this == &copy) return;
              
              clear();
              count = copy.count;
             curPosition = 0;

             if (count == 0) {
                 current = NULL;
                 return;
             } else {
                 copy.setPosition(0);
                 Node<List_entry> *tem = copy.current;

                 Node<List_entry> *new_node = new Node<List_entry>(tem->entry);
                 current = new_node;

                 for (int i = 0; i < count - 1; i++) {
                     tem = tem->next;
                     new_node->next = new Node<List_entry>(tem->entry, new_node);
                     new_node = new_node->next;
                 }
             }
         }
         // ���list
         void clear() {
             setPosition(0);
             
             Node<List_entry> *tem = current, *tem2;
             current = NULL;
             
             for (int i = 0; i < count; i++) {
                 tem2 = tem;
                 tem = tem->next;
                 delete tem2;
             }
             count = 0;
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
             if (position == 0) {
                 previous = NULL;
                 if (count == 0)  following = NULL;
                 else {
                     setPosition(0);
                     following = current;
                 }
             } else {
                 setPosition(position - 1);
                 previous = current;
                 following = current->next;
             }
             
             new_node = new Node<List_entry>(entry, previous, following);
             if (new_node == NULL) return overflow;
             if (previous != NULL) previous->next = new_node;
             if (following != NULL) following->back = new_node;
             
             current = new_node;
             curPosition = position;
             
             count++;
             return success;
         }
         // ɾ����position��λ�õ�Ԫ�أ�������Ԫ�ص�ֵ������entry��
         // ��position < 0 ���� position >= count���򷵻�underflow
         Error_code remove(int position, List_entry &entry) {
            if (position < 0 || position >= count || count < 1) return  underflow;
            
            Node<List_entry> *following, *tem;
             if (position == 0) {
                 setPosition(0);
                 tem = current;
                 current = current->next;
                 if (current != NULL) current->back = NULL;
                 entry = tem->entry;
                 delete tem;
             } else {
                   setPosition(position - 1);
                   following = current->next;
                   current->next = following->next;
                   tem = following->next;
                   if (tem != NULL) tem->back = current;
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
             setPosition(0);
             Node<List_entry> *tem = current;
            for (int i = 0; i < count; i++) {
                    visit(tem->entry);
                    tem = tem->next;
              }
         }
         
protected:
         int count;                                                                          // ��¼list��Ԫ������
         mutable int curPosition;                                   // currentָ���λ�ñ��
         mutable Node<List_entry> *current;                 // currentָ��
         // ����currentָ���λ�ã�ָ���position��λ��
         void setPosition(int position) const {
             if (position > curPosition) {
                 for (; curPosition != position; curPosition++)
                       current = current->next;
             }  else {
                 for (; position != curPosition; curPosition--)
                       current = current->back;
             }
         }
};
//void print(int &a) {
//    cout << a;
//}
//int main() {
//     MyList<int> test;
//     if (test.empty()) cout << "yes\n";
//     
//     for (int i = 0; i < 10; i++) {
//         test.insert(i, i + 1);
//     }
//     test.insert(6, 11);
//     test.traverse(print);
//     cout << endl;
//     
//     int a;
//     for (int i = 0; i < 10; i++) {
//         test.remove(9-i, a);
//         cout << a << ' ';
//     }
//     cout << endl;
//     
//     test.remove(6, a);
//     cout << a << endl;
//     
//     test.insert(6, a);
//     test.traverse(print);
//     cout << endl;
//     
//     cout << test.size() << endl;
//     a = test.size();
//     for (int i = a - 1; i >= 0; i--) {
//         test.remove(i, a);
//         cout << a << ' ';
//     }
//     cout << endl;
//     
//     test.insert(0, a);
//     
//     MyList<int> test2(test);
//     test2.traverse(print);
//     cout << endl;
//     MyList<int> test3;
//     MyList<int> test4(test3);
//     test4.traverse(print);
//     cout << endl;
//     test.clear();
//     if (test.empty()) cout << "yes\n";
//     return 0;
//
//}
