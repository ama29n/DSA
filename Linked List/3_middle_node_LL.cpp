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

// In case of even nodes, it will give the (n/2 + 1)th node.
void middle1(ListNode *&head) {
    ListNode *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->val;
}

// In case of even nodes, it will give the (n/2)th node.
void middle2(ListNode *&head) {
    ListNode *fast = head->next, *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->val;
}

int main() {
    ListNode *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    middle1(head);
}