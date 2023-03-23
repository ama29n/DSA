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

int main() {
    ListNode *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 9);
    display(head);
}