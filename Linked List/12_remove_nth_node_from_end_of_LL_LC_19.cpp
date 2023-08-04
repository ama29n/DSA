#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *l1 = head, *l2 = head, *prev = NULL;
        for(int i = 1; i < n; i++) {
            l1 = l1->next;
        }
        while(l1->next) {
            l1 = l1->next; prev = l2; l2 = l2->next;
        }
        if(prev == NULL) {
            ListNode *del = head;
            head = head->next;
            delete del;
            return head;
        }
        prev->next = l2->next;
        delete l2;
        return head;
    }
};
