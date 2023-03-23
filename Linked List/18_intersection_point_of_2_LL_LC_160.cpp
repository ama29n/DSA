#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while(a && b && a != b) {
        a = a->next;
        b = b->next;
        
        if(!a && !b)
            return NULL;
        if(!a) 
            a = headB;
        if(!b)
            b = headA;
    }
    return a;
}
