#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/middle-of-the-linked-list/

// In the even length list, it will return the (n / 2) + 1 th node
class Solution {
public:
    ListNode* middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// In the even length list, it will return the (n / 2) th 
class Solution {
public:
    ListNode* middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// In both the cases, for odd LL, the slow will point to center node
