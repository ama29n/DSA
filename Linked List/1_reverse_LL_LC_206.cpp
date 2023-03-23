#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/reverse-linked-list/

// Using stack, Time - O(n), Space - O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *ptr = head;
        stack<ListNode *> s;
        while(ptr) {
            s.push(ptr); ptr = ptr->next;
        }
        ptr = s.top(); s.pop();
        ListNode *newHead = ptr;
        while(!s.empty()) {
            ptr->next = s.top();
            ptr = ptr->next;
            s.pop();
        }
        ptr->next = NULL;
        return newHead;
    }
};

// Time - O(n), Space - O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *l = NULL, *r = NULL;
        while(cur) {
            r = cur->next;
            cur->next = l;
            l = cur;
            cur = r;
        }
        return l;
    }
};