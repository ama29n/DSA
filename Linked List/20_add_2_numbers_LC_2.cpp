#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = l1, *b = l2;
        int carry = 0;
        ListNode head(0), *ptr = &head;
        while(a || b) {
            int val = carry;
            carry = 0;
            val += a ? a->val : 0;
            val += b ? b->val : 0;
            a = a ? a->next : a;
            b = b ? b->next : b;
            if(val >= 10) {
                carry = val / 10;
                val %= 10;
            }
            ListNode *node = new ListNode(val);
            ptr->next = node; ptr = ptr->next; 
        }
        if(carry != 0) {
            ListNode *node = new ListNode(carry);
            ptr->next = node;
        }
        return head.next;
    }
};