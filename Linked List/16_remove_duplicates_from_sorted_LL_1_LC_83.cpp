#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        ListNode *ptr = head;
        while(ptr) {
            while(ptr->next && ptr->val == ptr->next->val) {
                ListNode *del = ptr->next;
                ptr->next = ptr->next->next;
                delete(del);
            }
            ptr = ptr->next;
        }
        return head;
    }
};
