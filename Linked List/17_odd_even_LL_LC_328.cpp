#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *odd = head, *even = head->next, *evenCopy = even;
    while(even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenCopy;
    return head;
}