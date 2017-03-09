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
        if (head == NULL) return head;
        ListNode* odd = NULL;
        ListNode* even = NULL;
        ListNode dummy(0);
        dummy.next = head;
        int i = 1;
        while(head != NULL) {
            if (odd == NULL) {
                odd = head;
            } else if (even == NULL) {
                even = head;
            } else if (i%2 == 1) {
                even->next = head->next;
                even = even->next;
                ListNode* temp = odd->next;
                odd->next = head;
                head->next = temp;
                odd = head;
                head = even;
                i++;
                continue;
            }
            head = head->next;
            i++;
        }
        return dummy.next;
    }
};
