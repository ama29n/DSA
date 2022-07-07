#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Indexing is from 1
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

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