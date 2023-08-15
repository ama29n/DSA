#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/ 

class Solution {
private:
    #define ff  first
    #define ss  second 
    void customEmpty(stack<pair<int, int>> &s) {
        while(!s.empty()) s.pop();
    }
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *ptr = head;
        vector<int> nums;
        while(ptr) {
            nums.push_back(ptr->val); ptr = ptr->next;
        }
        int n = nums.size();
        vector<int> pre(n);
        for(int i = 0; i < n; i++) {
            pre[i] = i - 1 < 0 ? nums[i] : pre[i - 1] + nums[i];
        }
        unordered_set<int> set;
        stack<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            if(set.find(pre[i]) != set.end()) {
                while(!s.empty() && s.top().ff != pre[i]) {
                    set.erase(s.top().ff);
                    s.pop();
                }
            } else if(pre[i] == 0) {
                customEmpty(s);
                set.clear();
            } else {
                set.insert(pre[i]);
                s.push({ pre[i], nums[i] });
            }
        }
        ListNode list(0), *prev = &list;
        while(!s.empty()) {
            ListNode *temp = new ListNode(s.top().ss);
            prev->next = temp;
            prev = prev->next;
            s.pop();
        }
        return reverse(list.next);
    }
};