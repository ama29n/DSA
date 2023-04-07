#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(0); temp->next = head;
        ListNode *prev = temp, *ptr = head;
        while(ptr) {
            if(ptr->next && ptr->val == ptr->next->val) {
                while(ptr->next && ptr->val == ptr->next->val) {
                    ListNode *del = ptr->next;
                    ptr->next = ptr->next->next;
                    delete del;
                }
                ListNode *del = ptr;
                prev->next = ptr->next;
                ptr = ptr->next;
                delete(del);
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return temp->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode temp(0), *prev = &temp, *cur = head;
        temp.next = head;
        while(cur) {
            if(cur->next && cur->next->val == cur->val) {
                while(cur->next && cur->next->val == cur->val) {
                    ListNode *del = cur;
                    prev->next = cur->next;
                    cur = cur->next;
                    delete del;
                }
                ListNode *del = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete del;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return temp.next;
    }
};