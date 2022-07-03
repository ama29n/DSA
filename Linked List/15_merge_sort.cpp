#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to find the mid of a list, in even cases it will return the n / 2 th node
ListNode* findMid(ListNode *head) {
    ListNode *fast = head->next;
    ListNode *slow = head;
    
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode *mergeSort(ListNode * right, ListNode *left) {
    // If right is NULL return left
    if(!right)
        return left;
    // If left is NULL return right
    if(!left)
        return right;
    
    // temp is a dummy node
    ListNode temp(-1), *ptr = &temp;
    
    // Mergin sorted lists 
    while(left && right) {
        if(left->val > right->val) {
            ptr->next = right;
            right = right->next;
        } else {
            ptr->next = left;
            left = left->next;
        }
        ptr = ptr->next;
    }
    
    // If in case, a list is smaller than the other
    ptr->next = right ? right : left;
    
    return temp.next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    
    ListNode *mid = findMid(head), *left = head;
    
    // Right will be the next of mid 
    ListNode *right = mid->next;
    
    // Splitting the lists 
    mid->next = NULL;
    
    // Recursive calls
    right = sortList(right);
    left = sortList(left);
    
    // Merging sorted parts
    ListNode *newHead = mergeSort(right, left);
    
    return newHead;
}