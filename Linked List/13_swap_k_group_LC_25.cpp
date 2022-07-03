#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *ptr = head;
    int count = 1;
    while(ptr && ptr->next) {
        count++;
        ptr = ptr->next;
        if(count == k)
            break;
    }
    if(count < k)
        return head;
    ListNode *cur = head, *l = NULL, *r = NULL;
    
    for(int i = 1; i <= k; i++) {
        r = cur->next;
        cur->next = l;
        l = cur;
        cur = r;
    }
    head->next = reverseKGroup(cur, k);
    return l;
}