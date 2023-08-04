#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if(!head || !head->next) {
            return head;
        }
        // We assume that we get the reverse LL till head->next
        ListNode *temp = reverseList(head->next);
        // head still points to head->next;
        head->next->next = head;
        // make head point to NULL
        head->next = NULL;
        // temp will same in all iterations i.e., the last node
        return temp;
    }
};
