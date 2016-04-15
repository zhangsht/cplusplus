/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* L1 = NULL, *L2 = NULL, *p = head;
        bool flag = false;
        while (p != NULL) {
        	if (flag) {
        		L1->next = p;
        	}
            L1 = p;
            p = p->next;
            L2 = p;
            if (p != NULL);
           		p = p->next;
           	if (flag) {
           	    L2->next = p;
           	}
           	flag = true;
        }
        if (L1 != NULL) {
        	L1->next = L2;
        }
        return L1;
    }
};