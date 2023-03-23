#include <bits/stdc++.h>
using namespace std;

// Approach 1
// It is to reverse the linked lists and then add them

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



// Stack Approach
//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    stack<Node*> s1, s2, s3;
    Node *ptr = l1;
    while(ptr) {
        s1.push(ptr);
        ptr = ptr->next;
    }
    ptr = l2;
    while(ptr) {
        s2.push(ptr);
        ptr = ptr->next;
    }
    int carry = 0;
    while(!s1.empty() || !s2.empty()) {
        int a = 0, b = 0;
        if(!s1.empty()) a = s1.top()->data;
        if(!s2.empty()) b = s2.top()->data;
        int c = a + b + carry;
        carry = 0;
        if(c >= 10) {
            carry = 1;
            c = c % 10;
        }
        Node *node = new Node(c);
        s3.push(node);
        if(!s1.empty()) s1.pop();
        if(!s2.empty()) s2.pop();
    }
    if(carry == 1) {
        Node *node = new Node(1);
        s3.push(node);
    }
    Node *head = new Node(s3.top()->data);
    s3.pop();
    ptr = head;
    while(!s3.empty()) {
        ptr->next = s3.top();
        ptr = ptr->next;
        s3.pop();
    }
    return head;
}