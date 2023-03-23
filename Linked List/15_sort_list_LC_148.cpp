#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/sort-list/ 

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode temp(0), *ptr = &temp;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next; ptr = ptr->next;
            } else {
                ptr->next = l2;
                l2 = l2->next; ptr = ptr->next;
            }
        }
        ptr->next = l1 ? l1 : l2;
        return temp.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *l1 = head, *l2 = head;
        while(l2->next && l2->next->next) {
            l1 = l1->next; l2 = l2->next->next;
        }
        l2 = l1->next; l1->next = NULL; l1 = head;
        l1 = sortList(l1);
        l2 = sortList(l2);
        head = merge(l1, l2);
        return head;
    }
};