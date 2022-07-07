#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode *head) {
    ListNode *cur = head, *l = NULL, *r = NULL;
    while(cur) {
        r = cur->next;
        cur->next = l;
        l = cur;
        cur = r;
    }
    return l;
}
bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        true;

    ListNode *fast = head, *slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow->next = reverseList(slow->next);
    slow = slow->next;
    fast = head;
    
    while(slow) {
        if(slow->val != fast->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}