#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/swap-nodes-in-pairs/ 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *n1 = head, *n2 = head->next, *n3 = head->next->next;
        n2->next = n1;
        n1->next = swapPairs(n3);
        return n2;
    }
};