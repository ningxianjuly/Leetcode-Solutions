//
//  main.cpp
//  Leetcode
//
//  Created by 凝弦 on 2017/3/6.
//  Copyright © 2017年 凝弦. All rights reserved.
//
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
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while( fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode* lres = sortList(head);
        ListNode* rres = sortList(slow);
        ListNode* res = Merge(lres,rres);
        return res;
    }
private:
    ListNode* Merge(ListNode* lres, ListNode* rres) {
        ListNode dummy(0);
        ListNode* trl = &dummy;
        while(lres != NULL && rres != NULL) {
            if (lres->val <= rres->val) {
                trl->next = lres;
                lres = lres->next;
            } else {
                trl->next = rres;
                rres = rres->next;
            }
            trl = trl->next;
        }
        if (lres != NULL) {
            trl->next = lres;
        }
        if (rres != NULL) {
            trl->next = rres;
        }
        return dummy.next;
        
    }
};
