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
         // �ڵ�position��λ�ò���ֵΪentry��Ԫ�أ����positionΪ0�����������ͷ���Դ�����
         // ���������У�position���� 0 <= position <= ����Ԫ������
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

         // �����������ݣ�ÿ����Ԫ��֮����һ���ո���������һ��Ԫ��֮��û�пո񣬲�����Ҫ����
         void print() {
              Node<Record> *tem = head;
              while (tem->next != NULL) {
                  cout << tem->entry << ' ';
                  tem = tem->next;
              }
              cout << tem->entry << endl;
         }
         // ��������й鲢������������һЩ���������������ܸĶ���ĳ�Ա����
         void merge_sort() {
             recursive_merge_sort(head);
         }
         
         void recursive_merge_sort(Node<Record>* &sub_list)
    private:
         Node<Record> *head;                                     // ����ͷָ��
};
