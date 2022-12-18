#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode *cur = head, *prev = NULL, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next)
            return head;
        head = reverse(head);
        ListNode *cur = head->next, *prev = head;
        while(cur) {
            if(cur->val < prev->val) {
                ListNode *temp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete(temp);
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return reverse(head);
    }
};