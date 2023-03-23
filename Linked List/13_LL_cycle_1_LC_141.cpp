#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/linked-list-cycle/ 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};