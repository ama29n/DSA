#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/delete-node-in-a-linked-list/ 

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};