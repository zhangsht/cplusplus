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
         // 清空list
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
         // 判断list是否为空
         bool empty() const {
             return count == 0;
         }
         // 判断list是否已满
         bool full() const {
              Node<List_entry> *new_node =  new Node<List_entry>;
              if (new_node == NULL) return true;
              else {
                  delete new_node;
                  new_node = NULL;
                  return false;
              }
         }
         // 获取list的元素数量
         int size() const {
             return count;
         }
         // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
         // 若position < 0 或者 position > count，则返回underflow
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
         // 删除第position个位置的元素，并将该元素的值保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
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
         // 获取第position个位置的元素，保存在entry中
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code retrieve(int position, List_entry &entry) const {
              if (position < 0 || position >= count) return  underflow;
              setPosition(position);
              entry = current->entry;
              return success;
         }
         // 将第position个位置的元素替换为entry
         // 若position < 0 或者 position >= count，则返回underflow
         Error_code replace(int position, const List_entry &entry) {
              if (position < 0 || position >= count) return  underflow;
              setPosition(position);
              current->entry = entry;
              return success;
         }
         // 用visit函数遍历list内所有的元素
         void traverse(void (*visit)(List_entry &)) {
            Node<List_entry> *tem = head;
            for (int i = 0; i < count; i++) {
                    visit(tem->entry);
                    tem = tem->next;
              }
         }
protected:
         int count;                                                                          // 记录list内元素数量
         Node<List_entry> *head;                                         // 链表头指针
         mutable int curPosition;                                   // current指针的位置编号
         mutable Node<List_entry> *current;                 // current指针
         // 设置current指针的位置，指向第position个位置
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
