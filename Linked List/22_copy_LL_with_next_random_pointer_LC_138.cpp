#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// We have to create a deep copy of the given linked list.
// Any node of the copied LL can't point to any node of the original linked list.

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> map;
        Node *ptr = head;
        while (ptr) {
            map[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            map[ptr]->next = map[ptr->next];
            map[ptr]->random = map[ptr->random];
            ptr = ptr->next;
        }
        return map[head];
    }
};