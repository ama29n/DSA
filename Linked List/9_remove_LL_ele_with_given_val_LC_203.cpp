#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    while(head && head->val == val) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
    if(!head)
        return NULL;
    ListNode *cur = head->next, *prev = head;
    while(cur) {
        if(cur->val == val) {
            ListNode *del = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete del;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}