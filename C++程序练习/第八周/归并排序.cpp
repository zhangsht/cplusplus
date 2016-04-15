template <class Record>
struct Node {
    Record entry;
    Node<Record> *next;
    Node(Record ent, Node<Record> *p = NULL) {
        entry = ent;
        next = p;
    }
};

template <class Record>
class Sortable_list {
    public:
         Sortable_list() {
             head = NULL;
         }
         ~Sortable_list() {
             Node<Record> *tem;
             while (head != NULL) {
                  tem = head;
                  head = head->next;
                  delete tem;
             }
         }
         // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，以此类推
         // 输入数据中，position满足 0 <= position <= 链表元素数量
         void insert(int position, const Record &entry) {
             if (position == 0) {
                 Node<Record> *tem = new Node<Record>(entry, head);
                 head = tem;
             } else {
                 Node<Record> *tem = head, tem2;
                 for (int i = 0; i < position; i++) {
                     tem2 = tem;
                     tem = tem->next;
                 }
                 Node<Record> *tem3 = new Node<Record>(entry, tem);
                 tem2->next = tem3;
             }
         }

         // 输出链表的内容，每两个元素之间用一个空格隔开，最后一个元素之后没有空格，并且需要换行
         void print() {
              Node<Record> *tem = head;
              while (tem->next != NULL) {
                  cout << tem->entry << ' ';
                  tem = tem->next;
              }
              cout << tem->entry << endl;
         }
         // 对链表进行归并排序，你可以添加一些辅助函数，但不能改动类的成员变量
         void merge_sort() {
             recursive_merge_sort(head);
         }
         
         void recursive_merge_sort(Node<Record>* &sub_list)
    private:
         Node<Record> *head;                                     // 链表头指针
};
