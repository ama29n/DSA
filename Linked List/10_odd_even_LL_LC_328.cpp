#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/odd-even-linked-list/ 

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *odd = head, *even = head->next, *evenCopy = even;
    while(even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenCopy;
    return head;
}