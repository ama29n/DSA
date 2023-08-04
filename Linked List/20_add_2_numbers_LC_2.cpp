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
    ListNode* addTwoNumbers(ListNode  *l1, ListNode *l2) {
        ListNode temp(0), *ptr = &temp;
        int carry = 0;
        while(l1 || l2) {
            int val = carry;
            carry = 0;
            val += l1 ? l1->val : 0;
            val += l2 ? l2->val : 0;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            if(val >= 10) {
                carry = val / 10;
                val %= 10;
            }
            ListNode *node = new ListNode(val);
            ptr->next = node;
            ptr = ptr->next;
        }
        if(carry) {
            ListNode *node = new ListNode(carry);
            ptr->next = node;
        }
        return temp.next;
    }
};
