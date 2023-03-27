#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ 

class Solution {
public:
    int findLen(ListNode *head) {
        int len = 0; ListNode *ptr = head;
        while(ptr) {
            len++; ptr = ptr->next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }
        int n = findLen(head);
        ListNode *prevX, *X, *prevY, *Y, *prev, *ptr;
        // For kth element
        prev = NULL; ptr = head; 
        for(int i = 1; i < k; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        prevX = prev; X = ptr;
        // For (n - k)th element
        prev = NULL, ptr = head;
        for(int i = 1; i <= (n - k); i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        prevY = prev; Y = ptr;
        // Replacing Algorithm
        if(prevX) {
            prevX->next = Y;
        }
        if(prevY) {
            prevY->next = X;
        }
        ListNode *t = X->next;
        X->next = Y->next;
        Y->next = t;
        return k == 1 ? Y : k == n ? X : head;
    }
};
