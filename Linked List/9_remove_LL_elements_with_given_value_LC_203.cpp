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
    ListNode* removeElements(ListNode *head, int val) {
        ListNode *temp = new ListNode(0); 
        temp->next = head;
        ListNode *prev = temp, *cur = head;
        while(cur) {
            if(cur->val == val) {
                ListNode *del = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete del;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return temp->next;
    }
};
