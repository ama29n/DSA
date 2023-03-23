#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

// https://leetcode.com/problems/merge-k-sorted-lists/  

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto head : lists) {
            ListNode *ptr = head;
            while(ptr) {
                v.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        if(v.size() == 0) {
            return NULL;
        }
        sort(v.begin(), v.end());
        ListNode temp(0), *ptr = &temp;
        for(auto it : v) {
            ListNode *n = new ListNode(it);
            ptr->next = n;
            ptr = ptr->next;
        }
        return temp.next;
    }
};