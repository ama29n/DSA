#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int findLength(ListNode *head) {
    int len = 0;
    ListNode *ptr = head;
    while(ptr) {
        ptr = ptr->next;
        len++;
    }
    return len;
}
ListNode* swapNodes(ListNode* head, int k) {
    if(!head || !head->next)
        return head;
    
    // length of list 
    int n = findLength(head); 

    ListNode *cur = head, *prev, *x, *prevX, *y, *prevY;

    for(int i = 1; i < k; i++) {
        prev = cur;
        cur = cur->next;
    }
    x = cur, prevX = prev;
    cur = head, prev = NULL;
    for(int i = 1; i <= n - k; i++) {
        prev = cur;
        cur = cur->next;
    }
    y = cur, prevY = prev;
    
    // Main algorithm
    if(prevX) {
        prevX->next = y;
    }

    if(prevY) {
        prevY->next = x;
    }

    ListNode *t = x->next;
    x->next = y->next;
    y->next = t;

    if(k == 1)
        return y;

    if(k == n)
        return x;
    
    return head; 
}