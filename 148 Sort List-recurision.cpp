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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = NULL, *left = NULL, *right = NULL, *start = NULL;
        int length = 0;
        while(head != NULL) {
            length++;
            head = head->next;
        }
        for (int step = 1; step < length; step = step*2 ){
            start = dummy;
            cur = dummy->next;
            while(cur != NULL) {
                left = cur;
                right = divide(left,step);
                cur = divide(right,step);
                start = Merge(left,right,start);
            }
        }
        return dummy->next;
    }
private:
    
    ListNode* divide(ListNode* node, int step) {
        for(int i = 1; node != NULL && i < step; i++) {
            node = node->next;
        }
        if (node == NULL) {
            return NULL;
        }
        ListNode* head = node->next;
        node->next = NULL;
        return head;
    }
    
    ListNode* Merge(ListNode* lres, ListNode* rres, ListNode* head) {
        ListNode* root = head;
        while(lres != NULL && rres != NULL) {
            if (lres->val <= rres->val) {
                root->next = lres;
                lres = lres->next;
            } else {
                root->next = rres;
                rres = rres->next;
            }
            root = root->next;
        }
        if (lres != NULL) {
            root->next = lres;
        }
        
        if (rres != NULL) {
            root->next = rres;
        }
        
        while(root->next != NULL) {
            root=root->next;
        }
        return root;
    }
};
