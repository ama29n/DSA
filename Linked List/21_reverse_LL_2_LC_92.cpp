#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/reverse-linked-list-ii/ 

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *prev = left == 1 ? NULL : head;
    for(int i = 2; i < left; i++)
        prev = prev->next;
    ListNode *cur = prev == NULL ? head : prev->next;
    ListNode *l= prev, *r = NULL;
    for(int i = left; i <= right; i++) {
        r = cur->next;
        cur->next = l;
        l = cur;
        cur = r;
    } 
    if(prev) {
        prev->next->next = cur;
        prev->next = l;
    } else {
        head->next = cur;
        head = l;
    }
    return head;
}