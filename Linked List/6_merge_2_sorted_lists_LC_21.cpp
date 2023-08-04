#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/merge-two-sorted-lists/ 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *temp = new ListNode(0);
        ListNode *ptr = temp;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ptr->next = l1;
                ptr = ptr->next; l1 = l1->next;
            } else {
                ptr->next = l2;
                ptr = ptr->next; l2 = l2->next;
            }
        }
        ptr->next = l1 ? l1 : l2;
        return temp->next;
    }
};
