#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
            if(fast == slow) {
                break;
            }
        }
        if(!fast || !fast->next) {
            return NULL;
        }
        slow = head;
        while(slow != fast) {
            slow = slow->next; fast = fast->next;
        }
        return slow;
    }
};
