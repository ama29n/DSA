#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

void push(ListNode *&head, int val) {
    ListNode *ptr = new ListNode(val);
    if (head == NULL) {
        head = ptr;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;
}

void display(ListNode *&head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

ListNode *reverse_k(ListNode *&head, int k) {
    if (!head)
        return NULL;

    ListNode *cur = head, *after = NULL, *before = NULL;
    int count = 1;

    while (cur != NULL && count <= k) {
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
        count++;
    }

    head->next = reverse_k(after, k);
    return before;
}

int main() {
    ListNode *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    ListNode *newnode = reverse_k(head, 5);
    display(newnode);
}