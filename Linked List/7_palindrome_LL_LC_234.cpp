#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/palindrome-linked-list/

// Hint - Reverse half LL and then check

class Solution {
private:
    ListNode* reverse(ListNode *head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
public:
    bool isPalindrome(ListNode *head) {
        if(!head && !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        fast = head;
        slow = slow->next;
        while(slow) {
            if(slow->val != fast->val) {
                return false;
            }
            slow = slow->next; fast = fast->next;
        }
        return true;
    }
};
