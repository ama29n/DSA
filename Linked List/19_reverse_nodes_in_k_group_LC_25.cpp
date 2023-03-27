#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/ 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *cur = head;
        int count = 0;
        while(cur) {
            count++; 
            cur = cur->next;
            if(count == k) {
                break;
            }
        }
        if(count < k) {
            return head;
        }
        ListNode *l = NULL, *r = NULL; cur = head;
        for(int i = 0; i < k; i++) {
            r = cur->next;
            cur->next = l;
            l = cur;
            cur = r;
        }
        head->next = reverseKGroup(cur, k);
        return l;
    }
};