//The first solution is straight forward. Suppose we have a->b->c->d, we just swap a and b and return the address of a. Then we input b and c and then swap c and d. we return the address of c.Just write a function to do this and we are done.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode*  dummy = new ListNode(0);
        ListNode* end = dummy;
        dummy->next = head;
        while(end != NULL) {
            end = changeNode(end, end->next);
        }
        return dummy->next;
    }
private:
    ListNode* changeNode(ListNode* prev, ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* ret = head->next->next;
        prev->next = prev->next->next;
        prev->next->next = head;
        head->next=ret;
        return head;
    }
};

//The second solution uses the pointer to poniter. A key question of this problem is for a chain like a->b->c->d, when we swap c and d, we need to let b->next = d. How to store (b->next) is a problem. In previous solution, we just return this address in our function.here we store the address use the pointer to pointer **pp. so pp will be the address of the pointer that pointer points to head. *pp will be the address of head. **pp will be the value of head. we use *a and *b to denote the head and the head->next. we swap a and b, and let *pp = b. Then we set pp be the address of a->next.
//赋值表达式's return value is the left value of the expression
//However, the performance of this approach is slower. I guess this is due to the effiency of pointer to pointer.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
        
    }
};
