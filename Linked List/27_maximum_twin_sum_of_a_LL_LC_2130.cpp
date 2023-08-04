#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/ 

// Space -> O(n)
class Solution {
public:
    int pairSum(ListNode *head) {
        ListNode *ptr = head;
        int count = 0;
        // Finding the size of LL
        while(ptr) {
            count++; ptr = ptr->next;
        }
        // Inserting half nodes in the stack
        stack<ListNode*> s;
        ptr = head;
        for(int i = 0; i < count / 2; i++) {
            s.push(ptr); ptr = ptr->next;
        }
        // Finding the maximum twin sum
        int twin = 0;
        while(!s.empty()) {
            int sum = s.top()->val + ptr->val;
            s.pop(); ptr = ptr->next;
            twin = max(twin, sum);
        }
        return twin;
    }
};

// Space -> O(1)

// Reverse from mid and then 2 pointer