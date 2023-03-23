#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/palindrome-linked-list/

// Hint - Reverse half LL and then check

class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode *cur = head, *l = NULL, *r = NULL;
        while(cur) {
            r = cur->next; cur->next = l; l = cur; cur = r;
        }
        return l;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next; fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode *l1 = head, *l2 = slow->next;
        while(l1 && l2) {
            if(l1->val != l2->val) {
                return false;
            }
            l1 = l1->next; l2 = l2->next;
        }
        return true;
    }   
};