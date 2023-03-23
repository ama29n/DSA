#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
}

ListNode *reverse(ListNode *&head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return temp;
}