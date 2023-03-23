#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/remove-nodes-from-linked-list/

// Hint - Reverse the LL 

class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode *cur = head, *l = NULL, *r = NULL;
        while(cur) {
            r = cur->next; cur->next = l; l = cur; cur = r;
        }
        return l;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        head = reverse(head);
        ListNode *ptr = head, *prev = NULL;
        int maxSoFar = 0;
        while(ptr) {
            maxSoFar = max(maxSoFar, ptr->val);
            if(ptr->val < maxSoFar) {
                ListNode *del = ptr;
                prev->next = ptr->next;
                ptr = ptr->next;
                delete del;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        head = reverse(head);
        return head;
    }
};