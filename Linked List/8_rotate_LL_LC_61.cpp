#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/rotate-list/ 

class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *ptr = head;
        int count = 1;
        while(ptr->next) { ptr = ptr->next; count++; }
        ptr->next = head; ptr = ptr->next;
        k %= count;
        for(int i = 1; i < (count - k); i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
