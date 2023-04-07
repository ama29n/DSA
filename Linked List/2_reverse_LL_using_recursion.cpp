#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        // Assume this step will return the reversed LL
        ListNode *temp = reverseList(head->next);
        // Changing direction of current node 
        head->next->next = head;
        head->next = NULL;
        // temp will remain same in all iterations i.e, the last node
        return temp;
    }
};