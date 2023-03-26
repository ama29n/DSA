#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/intersection-of-two-linked-lists/ 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode *a = l1, *b = l2;
        while(a && b && a != b) {
            a = a->next;
            b = b->next;
            if(!a && !b) {
                return NULL;
            }
            a = a ? a : l2;
            b = b ? b : l1;
        }
        return a;
    }
};
