#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
} *top;

void push(Node *&top, int val) {
    Node *ptr = new Node(val);
    if (top == NULL) {
        top = ptr;
        return;
    }
    ptr->next = top;
    top = ptr;
}

void display(Node *&top) {
    Node *temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void pop(Node *&head) {
    Node *ptr = top;
    top = top->next;
    delete ptr;
}

int main() {
    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);
    push(top, 5);
    display(top);
    cout << endl;
    pop(top);
    display(top);
}