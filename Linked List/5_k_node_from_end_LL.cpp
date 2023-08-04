#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* last(ListNode *head, int k) {
        ListNode *ptr = head;
        for (int i = 1; i <= k; i++) {
            ptr = ptr->next;
        }
        ListNode *k_last = head;
        while (ptr != NULL) {
            k_last = k_last->next;
            ptr = ptr->next;
        }
        return k_last;
    }
};
