#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Time - O(n), Space - O(n)
class Solution {
public:
    node *addOne(node *head) {
        stack<node *> s;
        node *ptr = head;
        while (ptr != NULL) {
            s.push(ptr);
            ptr = ptr->next;
        }
        int carry = 1;
        while (s.size() > 1) {
            s.top()->data += carry;
            carry = s.top()->data / 10;
            s.top()->data = s.top()->data % 10;
            s.pop();
        }
        s.top()->data += carry;
        return head;
    }
};

// Time - O(n), Space - O(1)
class Solution {
public:
    node *reverse(node *head) {
        node *cur = head;
        node *before = NULL, *after = NULL;
        while (cur != NULL) {
            after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        head = before;
        return head;
    }
    node *addOne(node *head) {
        head = reverse(head);
        node *ptr = head;
        int carry = 1;
        while (ptr->next != NULL) {
            int *val = &ptr->data;
            *val += carry;
            carry = *val / 10;
            *val = *val % 10;
            ptr = ptr->next;
        }
        ptr->data += carry;
        head = reverse(head);
        return head;
    }
};