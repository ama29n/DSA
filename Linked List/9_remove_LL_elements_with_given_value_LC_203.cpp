#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/remove-linked-list-elements/ 

// Hint - First remove the elements that are in the starting of the list having value = val

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) {
            ListNode *del = head; head = head->next; delete del;
        }
        ListNode *prev = NULL, *ptr = head;
        while(ptr) {
            if(ptr->val == val) {
                ListNode *del = ptr;
                prev->next = ptr->next;
                ptr = ptr->next;
                delete del;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};